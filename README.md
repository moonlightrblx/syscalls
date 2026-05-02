**ellii's syscall utils**  

A lightweight way to make direct syscalls on Windows without relying on `ntdll.dll` or any imported functions.

### Why you would want this
- Bypassing user-mode API hooks / EDR monitoring that hooks `ntdll`
- Static analysis / emulation tools
- Learning how the Windows syscall interface actually works
- Any situation where you want minimal dependencies

### How it works.
#### Usermode
Instead of writing ugly inline assembly that MSVC hates, this library does something cleaner:

At startup, it allocates a small executable memory page and copies in a tiny handwritten stub:

```asm
mov r10, rcx
mov eax, <syscall_id>
syscall
ret
```

It then **patches the syscall number** into the stub right before calling it. Because the stub is in executable memory you control, you completely skip the normal `ntdll` path.

Arguments are passed through a simple `void**` array (up to 14 args, which covers every syscall on Windows). The code uses a big `switch` to call the stub with the right number of arguments.

#### KM

In KM we resolve the syscall id to a syscall function name and then get the address of it through MmGetSystemRoutineAddress. Then we do the whole switch statement and call it properly.

### Key Advantages

- **No inline assembly** → compiles cleanly with x64 MSVC
- Bypasses most basic user-mode hooks on `Nt*` functions
- Tiny and self-contained (just a few dozen bytes of shellcode)
- Works with any syscall number (even undocumented or future ones)
- Supports both user-mode and kernel-mode (with a simple `#ifdef`)

---

### Things you should update.

- The big `switch` is ugly but necessary without variadic assembly or `std::invoke` tricks if you really wanna fix it its easy.
- You can make the stub allocation happen only once and reuse it safely.
- Consider adding a `VirtualProtect` to `PAGE_EXECUTE_READ` after writing if you're paranoid enough .
- For kernel mode, the current implementation is a placeholder, you’ll probably want a better way to resolve syscall numbers or use the SSDT directly.
