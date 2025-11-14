#pragma once
#include <windows.h>
#include <cstdint>

using syscall_stub_t = NTSTATUS(NTAPI*)(...);  
namespace utils { 
    inline NTSTATUS invoke_syscall(uintptr_t number, void** args, size_t arg_count)
    {

        alignas(16) static const BYTE stub_template[] = {
            0x4C, 0x8B, 0xD1,                   // mov     r10, rcx
            0xB8, 0x00, 0x00, 0x00, 0x00,       // mov     eax, 0x00000000  ; syscall ID goes here
            0x0F, 0x05,                         // syscall
            0xC3                                // ret
        };


        static BYTE* executable_stub = []() -> BYTE* {
            void* page = VirtualAlloc(
                nullptr,
                4096,
                MEM_COMMIT | MEM_RESERVE,
                PAGE_EXECUTE_READWRITE
            );
            if (!page) {

                return nullptr;
            }
            memcpy(page, stub_template, sizeof(stub_template));
            return static_cast<BYTE*>(page);
            }();

        if (!executable_stub) {
            return STATUS_ACCESS_VIOLATION;
        }


        *reinterpret_cast<uint32_t*>(executable_stub + 4) = static_cast<uint32_t>(number); // patch syscall number in

        auto fn = reinterpret_cast<syscall_stub_t>(executable_stub); // get the syscall in a callable format


        switch (arg_count) {
        case 0:  return fn();
        case 1:  return fn(args[0]);
        case 2:  return fn(args[0], args[1]);
        case 3:  return fn(args[0], args[1], args[2]);
        case 4:  return fn(args[0], args[1], args[2], args[3]);
        case 5:  return fn(args[0], args[1], args[2], args[3], args[4]);
        case 6:  return fn(args[0], args[1], args[2], args[3], args[4], args[5]);
        case 7:  return fn(args[0], args[1], args[2], args[3], args[4], args[5], args[6]);
        case 8:  return fn(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7]);
        case 9:  return fn(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8]);
        case 10: return fn(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9]);
        case 11: return fn(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10]);
        case 12: return fn(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11]);
        case 13: return fn(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12]);
        case 14: return fn(args[0], args[1], args[2], args[3], args[4], args[5], args[6], args[7], args[8], args[9], args[10], args[11], args[12], args[13]);

        default:

            return 0;
        }
    }
}
namespace syscalls{
    template<uintptr_t SyscallId, typename... Args>
    inline NTSTATUS invoke(Args... args) {
        void* arg_array[] = { const_cast<void*>(static_cast<const void*>(&args))... };
        return utils::invoke_syscall(SyscallId, arg_array, sizeof...(Args));
    }
}