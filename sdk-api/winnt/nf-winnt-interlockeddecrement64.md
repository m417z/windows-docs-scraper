# InterlockedDecrement64 function

## Description

Decrements (decreases by one) the value of the specified 64-bit variable as an atomic operation.

To operate on 32-bit values, use the [InterlockedDecrement](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockeddecrement) function.

## Parameters

### `Addend` [in, out]

A pointer to the variable to be decremented.

## Return value

The function returns the resulting decremented value.

## Remarks

The variable pointed to by the *Addend* parameter must be aligned on a 64-bit boundary; otherwise, this function will behave unpredictably on multiprocessor x86 systems and any non-x86 systems. See **_aligned_malloc**.

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

This function is implemented using a compiler intrinsic where possible. For more information, see the WinBase.h header file and [_InterlockedDecrement64](https://learn.microsoft.com/previous-versions/f24ya7ct(v=vs.85)).

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

**Itanium-based systems:** For performance-critical applications, use [InterlockedDecrementAcquire64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683585(v=vs.85)) or [InterlockedDecrementRelease64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683588(v=vs.85)) instead.

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedDecrement](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockeddecrement)

[InterlockedDecrement16](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockeddecrement16)

[InterlockedDecrement16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972649(v=vs.85))

[InterlockedDecrement16NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972650(v=vs.85))

[InterlockedDecrement16Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972651(v=vs.85))

[InterlockedDecrementAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683583(v=vs.85))

[InterlockedDecrementAcquire64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683585(v=vs.85))

[InterlockedDecrementNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972652(v=vs.85))

[InterlockedDecrementNoFence64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972653(v=vs.85))

[InterlockedDecrementRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683586(v=vs.85))

[InterlockedDecrementRelease64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683588(v=vs.85))

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)