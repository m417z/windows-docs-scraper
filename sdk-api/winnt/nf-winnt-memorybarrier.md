# MemoryBarrier function

## Description

Creates a hardware memory barrier (fence) that prevents the CPU from re-ordering read and write operations. It may also prevent the compiler from re-ordering read and write operations.

## Remarks

Use this macro or the interlocked functions when the order of memory read and write operations is critical for program operation.

The **_ReadBarrier**, **_WriteBarrier**, and **_ReadWriteBarrier** compiler intrinsics prevent compiler re-ordering only. With Visual Studio 2003, **volatile** to **volatile** references are ordered; the compiler will not re-order **volatile** variable access. With Visual Studio 2005, the compiler also uses acquire semantics for read operations on **volatile** variables and release semantics for write operations on **volatile** variables (when supported by the CPU). For more information, see [Synchronization and Multiprocessor Issues](https://learn.microsoft.com/windows/desktop/Sync/synchronization-and-multiprocessor-issues).

This macro can be called on all processor platforms where Windows is supported, but it has no effect on some platforms. The definition varies from platform to platform. The following are some definitions of this macro in Winnt.h.

``` syntax

#ifdef _AMD64_
#define MemoryBarrier __faststorefence
#endif

#ifdef _IA64_
#define MemoryBarrier __mf
#endif

// x86

FORCEINLINE
VOID
MemoryBarrier (
    VOID
    )
{
    LONG Barrier;
    __asm {
        xchg Barrier, eax
    }
}
```

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)