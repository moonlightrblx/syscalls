# ellis syscall utils
## Use Cases

- Direct syscalls in C++ (avoiding `GetProcAddress` / EDR hooks)
- Custom runtime environments
- Static analysis tools
- Educational purposes
---
## syscall example

The syscall stub `syscall_stub.h` works by **dynamically generating a tiny executable stub** at runtime using `VirtualAlloc`(though you can change it to support km) and a hardcoded template (`mov r10, rcx; mov eax, <id>; syscall; ret`), then **patching in the desired syscall ID** and invoking it directly with up to 14 arguments passed via a `void**` array. This is a direct syscall and basically avoids all the stupid inline asm shit that you cannot do in x64 msvc. 

---
### how it works
   At initialization, we allocate a small executable memory region to ensure we can call our code.
   Then we `rcx` is moved into `r10` before issuing `syscall`.
   The `<syscall_id>` placeholder inside the stub is also patched in before we call it.
   Calls are issued through a generic `invoke_syscall(void** args)` interface that supports up to **14 arguments**, matching the max number of arguments in a syscall.


### Key Advantages

* **No inline asm needed** (compatible with x64 MSVC)
* **Bypasses basic user-mode API hooks**
* **Small and self-contained**
* **Works with arbitrary syscall numbers**
* **Lightweight and fast** only a few bytes of executable code.


### coming soon?
once I get my PC back I'm planning to add km support and release the dumper. I'll also fix the rest of this fucked up readme.