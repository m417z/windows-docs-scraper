## Description

The **KeMemoryBarrier** routine creates a barrier at its position in the code—across which the compiler and the processor cannot move any operations.

## Remarks

The **KeMemoryBarrier** routine inserts a memory barrier into your code. This barrier guarantees that every operation that appears in the source code before the call to **KeMemoryBarrier** will complete before any operation that appears after the call.

The implementation of the **KeMemoryBarrier** routine depends on the processor architecture. For example, for an x86 processor, the Wdm.h header file defines **KeMemoryBarrier** to be the following inline function:

```cpp
FORCEINLINE
VOID
KeMemoryBarrier (
    VOID
    )
{
    LONG Barrier;

    __asm {
        xchg Barrier, eax
    }
}
```

In this definition, the braces that follow the **__asm** keyword contain inline assembly code. The compiler optimizer cannot move an instruction from a position before the inline assembly code to a position after the inline assembly code, and vice versa. In addition, the **xchg** instruction implicitly includes the **lock** prefix, which forces the processor hardware to complete the memory operations for all instructions that precede the **xchg** instruction before it initiates memory operations for instructions that follow the **xchg** instruction.

**KeMemoryBarrier** prevents both the compiler and the processor from moving operations across the barrier. To prevent only the compiler from moving operations, call [KeMemoryBarrierWithoutFence](https://learn.microsoft.com/previous-versions/windows/hardware/device-stage/drivers/ff552973(v%3Dvs.85)).

## See also

[KeMemoryBarrierWithoutFence](https://learn.microsoft.com/previous-versions/windows/hardware/device-stage/drivers/ff552973(v%3Dvs.85))