#include <windows.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <iomanip>
#include <sstream>
#pragma comment(lib, "kernel32.lib")

struct FileHandle { HANDLE h; FileHandle(HANDLE h_ = INVALID_HANDLE_VALUE) : h(h_) {} ~FileHandle() { if (h != INVALID_HANDLE_VALUE) CloseHandle(h); } operator HANDLE() const { return h; } };
struct MappingHandle { HANDLE h; MappingHandle(HANDLE h_ = nullptr) : h(h_) {} ~MappingHandle() { if (h) CloseHandle(h); } operator HANDLE() const { return h; } };
struct ViewPtr { BYTE* p; ViewPtr(BYTE* p_ = nullptr) : p(p_) {} ~ViewPtr() { if (p) UnmapViewOfFile(p); } operator BYTE* () const { return p; } };

bool is_valid_syscall_stub(const BYTE* pFunc) {
    return pFunc[0] == 0x4C && pFunc[1] == 0x8B && pFunc[2] == 0xD1 && pFunc[3] == 0xB8;
}

DWORD get_syscall_id(const BYTE* pFunc) { return *(DWORD*)(pFunc + 4); }

DWORD rva_to_file_offset(BYTE* pMap, PIMAGE_NT_HEADERS pNt, DWORD rva) {
    PIMAGE_SECTION_HEADER sec = IMAGE_FIRST_SECTION(pNt);
    for (WORD i = 0; i < pNt->FileHeader.NumberOfSections; ++i) {
        if (rva >= sec[i].VirtualAddress && rva < sec[i].VirtualAddress + sec[i].SizeOfRawData) {
            return sec[i].PointerToRawData + (rva - sec[i].VirtualAddress);
        }
    }
    return 0;
}

std::string to_snake_case(const char* name) {
    std::string out;
    for (int i = 0; name[i]; ++i) {
        char c = name[i];
        if (c >= 'A' && c <= 'Z') {
            if (i > 0) out += '_';
            out += (c + 32);
        }
        else out += c;
    }
    return out;
}

std::string get_current_time() {
    std::time_t t = std::time(nullptr);
    struct tm tm_buf;
    if (localtime_s(&tm_buf, &t) != 0) return "Unknown";
    char buffer[100];
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tm_buf);
    return buffer;
}

std::string get_windows_version() {
    using RtlGetVersionPtr = NTSTATUS(WINAPI*)(PRTL_OSVERSIONINFOW);
    static RtlGetVersionPtr pRtlGetVersion = nullptr;
    if (!pRtlGetVersion) {
        HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
        if (hNtdll) pRtlGetVersion = (RtlGetVersionPtr)GetProcAddress(hNtdll, "RtlGetVersion");
    }
    if (!pRtlGetVersion) return "Unknown";
    RTL_OSVERSIONINFOW ver = { sizeof(ver) };
    if (pRtlGetVersion(&ver) != 0) return "Unknown";
    return std::to_string(ver.dwMajorVersion) + "." +
        std::to_string(ver.dwMinorVersion) + " (Build " +
        std::to_string(ver.dwBuildNumber) + ")";
}

int main() {
    const char* path = "C:\\Windows\\System32\\ntdll.dll";
    FileHandle hFile = CreateFileA(path, GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
    if (hFile == INVALID_HANDLE_VALUE) { printf("[-] Failed to open ntdll.dll\n"); return 1; }

    MappingHandle hMap = CreateFileMapping(hFile, nullptr, PAGE_READONLY, 0, 0, nullptr);
    if (!hMap) { printf("[-] CreateFileMapping failed\n"); return 1; }

    ViewPtr view = (BYTE*)MapViewOfFile(hMap, FILE_MAP_READ, 0, 0, 0);
    if (!view) { printf("[-] MapViewOfFile failed\n"); return 1; }

    BYTE* pMap = view;
    PIMAGE_DOS_HEADER pDos = (PIMAGE_DOS_HEADER)pMap;
    if (pDos->e_magic != IMAGE_DOS_SIGNATURE) return 1;

    PIMAGE_NT_HEADERS pNt = (PIMAGE_NT_HEADERS)(pMap + pDos->e_lfanew);
    if (pNt->Signature != IMAGE_NT_SIGNATURE) return 1;

    IMAGE_DATA_DIRECTORY expDir = pNt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_EXPORT];
    if (!expDir.VirtualAddress) return 1;

    DWORD expOffset = rva_to_file_offset(pMap, pNt, expDir.VirtualAddress);
    if (!expOffset) return 1;

    PIMAGE_EXPORT_DIRECTORY pExport = (PIMAGE_EXPORT_DIRECTORY)(pMap + expOffset);

    DWORD namesOffset = rva_to_file_offset(pMap, pNt, pExport->AddressOfNames);
    DWORD ordOffset = rva_to_file_offset(pMap, pNt, pExport->AddressOfNameOrdinals);
    DWORD funcOffset = rva_to_file_offset(pMap, pNt, pExport->AddressOfFunctions);
    if (!namesOffset || !ordOffset || !funcOffset) return 1;

    PDWORD pNames = (PDWORD)(pMap + namesOffset);
    PWORD  pOrdinals = (PWORD)(pMap + ordOffset);
    PDWORD pFuncs = (PDWORD)(pMap + funcOffset);

    struct Syscall {
        std::string original;
        std::string snake;
        DWORD id;
    };
    std::vector<Syscall> syscalls;


    for (DWORD i = 0; i < pExport->NumberOfNames; ++i) {
        DWORD nameRva = pNames[i];
        DWORD nameOffset = rva_to_file_offset(pMap, pNt, nameRva);
        if (!nameOffset) continue;

        const char* name = (const char*)(pMap + nameOffset);
        if (strncmp(name, "Nt", 2) != 0 && strncmp(name, "Zw", 2) != 0) continue;

        WORD ord = pOrdinals[i];
        if (ord >= pExport->NumberOfFunctions) continue;

        DWORD funcRva = pFuncs[ord];
        DWORD funcOffset = rva_to_file_offset(pMap, pNt, funcRva);
        if (!funcOffset) continue;

        BYTE* pFunc = pMap + funcOffset;
        if (!is_valid_syscall_stub(pFunc)) continue;

        std::string snake = to_snake_case(name);
        syscalls.push_back({ name, snake, get_syscall_id(pFunc) });
    }

   
    std::sort(syscalls.begin(), syscalls.end(), [](const auto& a, const auto& b) {
        return a.id < b.id;
        });

    std::vector<Syscall> unique_syscalls;
    for (size_t i = 0; i < syscalls.size(); ++i) {
        const auto& sc = syscalls[i];
 
        bool prefer_nt = (strncmp(sc.original.c_str(), "Nt", 2) == 0);
        for (size_t j = i + 1; j < syscalls.size() && syscalls[j].id == sc.id; ++j) {
            if (strncmp(syscalls[j].original.c_str(), "Nt", 2) == 0) {
                prefer_nt = true;
                break;
            }
        }
        if (prefer_nt) {
     
            auto nt_it = std::find_if(syscalls.begin() + i, syscalls.end(),
                [&](const auto& s) { return s.id == sc.id && strncmp(s.original.c_str(), "Nt", 2) == 0; });
            if (nt_it != syscalls.end()) {
                unique_syscalls.push_back(*nt_it);
            }
            else {
                unique_syscalls.push_back(sc);
            }
        }
        else {
            unique_syscalls.push_back(sc);
        }
        while (i + 1 < syscalls.size() && syscalls[i + 1].id == sc.id) ++i;
    }

    syscalls = std::move(unique_syscalls);

    std::string filename = get_windows_version() + "_syscalls.h";
    std::ofstream out(filename);
    if (!out) { printf("[-] Failed to write %s\n", filename.c_str()); return 1; }

    out << "// ==============================================================================\n";
    out << "// Windows Syscall Table Dumper\n";
    out << "// Dumped by: ellii\n";
    out << "// Windows Version: " << get_windows_version() << "\n";
    out << "// Dumped at: " << get_current_time() << "\n";
    out << "// Source: C:\\Windows\\System32\\ntdll.dll\n";
    out << "// Total Syscalls: " << syscalls.size() << "\n";
    out << "// ==============================================================================\n\n";
    out << "#pragma once\n\n";
    out << "#include <cstdint>\n";
    out << "#include <array>\n\n";
    out << "namespace syscalls {\n\n";

    out << " namespace idx {\n\n";
    for (const auto& sc : syscalls) {
        out << "  inline constexpr uintptr_t " << std::left << std::setw(40)
            << sc.snake << " = 0x" << std::hex  << sc.id
            << std::dec << std::setfill(' ') << "; // #" << sc.id << "\n";
    }
    out << " }\n\n";



 
    out << "  inline constexpr const char* map[] = {\n";

    if (syscalls.empty()) {
        out << "    nullptr\n";
    }
    else {
        DWORD current_id = 0;
        size_t sc_idx = 0;

        while (current_id < syscalls[0].id) {
            out << "    nullptr, // 0x" << std::hex  << current_id << "\n";
            ++current_id;
        }

        // Write all syscalls with gaps
        for (sc_idx = 0; sc_idx < syscalls.size(); ++sc_idx) {
            const auto& sc = syscalls[sc_idx];
            while (current_id < sc.id) {
                out << "    nullptr, // 0x" << std::hex  << current_id << "\n";
                ++current_id;
            }
            out << "    \"" << sc.original << "\", // 0x" << std::hex << sc.id << "\n";
            current_id = sc.id + 1;
        }
    }

    out << "  };\n\n";
    out << "  template<uintptr_t Idx>\n";
    out << "  inline constexpr const char* get() {\n";
    out << "    if constexpr (Idx < sizeof(map) / sizeof(map[0])) {\n";
    out << "      return map[Idx];\n";
    out << "    } else {\n";
    out << "      return nullptr;\n";
    out << "    }\n";
    out << "  }\n\n";

    out << "} // namespace syscalls\n";
    out.close();

    printf("[+] Syscalls dumped to: %s\n", filename.c_str());
    printf("[+] Found %zu unique syscalls\n", syscalls.size());
    return 0;
}