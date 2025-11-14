# ellis syscall utils
## Use Cases

- Direct syscalls in C++ (avoiding `GetProcAddress` / EDR hooks)
- Kernel exploit development
- Custom runtime environments
- Static analysis tools
- Educational purposes
---
## syscall example

The syscall stub `syscall_stub.h` works by **dynamically generating a tiny executable stub** at runtime using `VirtualAlloc` and a hardcoded template (`mov r10, rcx; mov eax, <id>; syscall; ret`), then **patching in the desired syscall ID** and invoking it directly with up to 14 arguments passed via a `void**` array. This is a direct syscall and basically avoids all the stupid inline asm shit that you cannot do in x64 msvc. 

---
### how it works
   At initialization, the module allocates a small executable memory region using `VirtualAlloc`.
   This sequence mirrors the Windows system-call ABI, where `rcx` is first moved into `r10` before issuing `syscall`.
   The `<syscall_id>` placeholder inside the stub is patched in at runtime.
   This allows the same template to be reused for any syscall simply by writing the appropriate ID into the stub’s instruction buffer.
   Calls are issued through a generic `invoke_syscall(void** args)` interface that supports up to **14 arguments**, matching the Windows syscall convention for register + stack arguments.
   Once arguments and syscall ID are prepared, the generated stub is invoked like a regular function pointer, resulting in a clean, unhooked, direct transition into kernel mode.

### Key Advantages

* **No inline asm needed** (compatible with x64 MSVC)
* **Bypasses user-mode API hooks**
* **Small and self-contained**
* **Works with arbitrary syscall numbers**
* **Lightweight and fast** — only a few bytes of executable code



---
## syscall dumper

> **Note**: This is a **closed-source** utility.

---

## Overview

This tool dynamically extracts **NT syscall IDs** directly from `ntdll.dll` on a live Windows system and generates a clean, version-specific C++ header containing:

- Syscall indices in `snake_case` constants
- A dense lookup table mapping syscall ID → function name
- Compile-time safe access via `constexpr`

It is designed for **low-level systems programming**, **kernel exploitation research**, **reverse engineering**, and **red team tooling** where direct syscall invocation is required (e.g., bypassing user-mode hooks).

---

## How It Works

The program performs the following steps at runtime:

1. **Memory-maps** `C:\Windows\System32\ntdll.dll` into the process address space.
2. **Parses** the PE structure:
   - DOS header → NT headers → Export directory
3. **Iterates** through all exported functions starting with `Nt` or `Zw`.
4. **Validates** each as a legitimate syscall stub using the standard pattern:
   ```asm
   mov r10, rcx
   mov eax, <syscall_id>
   ```
5. **Extracts** the syscall ID from the `mov eax, ...` instruction.
6. **Resolves duplicates**: Prefers `Nt*` over `Zw*` when both exist for the same ID.
7. **Sorts** syscalls by ID and removes gaps in indexing.
8. **Generates** a C++ header:
   - `namespace syscalls::idx` with `constexpr uintptr_t` entries
   - A `constexpr` string array `map[]` indexed by syscall ID
   - A `constexpr` `get<Idx>()` template for compile-time name lookup

---

## Output Example (`10.0.19041_syscalls.h`)

```cpp
#pragma once

#include <cstdint>
#include <array>

namespace syscalls {

 namespace idx {
  inline constexpr uintptr_t nt_create_file          = 0x55; // #85
  inline constexpr uintptr_t nt_read_file            = 0x06; // #6
  inline constexpr uintptr_t nt_write_file           = 0x08; // #8
  // ... 400+ more
 }

 inline constexpr const char* map[] = {
  nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, // 0x00–0x05
  "NtReadFile",                                           // 0x06
  nullptr,
  "NtWriteFile",                                          // 0x08
  // ... with gaps filled as nullptr
 };

 template<uintptr_t Idx>
 inline constexpr const char* get() {
  if constexpr (Idx < sizeof(map) / sizeof(map[0])) {
   return map[Idx];
  } else {
   return nullptr;
  }
 }

} // namespace syscalls
```


---

## Sample Usage (in your project)

```cpp
#include "10.0.19041_syscalls.h"

using namespace syscalls;

void example() {
    constexpr auto id = idx::nt_create_file;
    constexpr auto name = syscalls::get<id>();
    static_assert(std::string_view(name) == "NtCreateFile");
}
```

---

## Supported Platforms
- Any version of 64 bit windows

> Tested on build `10.0.19041` → `11 22H4`
