# InterlockedIncrement16 function

## Description

Increments (increases by one) the value of the specified 16-bit variable as an atomic operation.

To operate on 32-bit values, use the [InterlockedIncrement](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedincrement) function.

To operate on 64-bit values, use the [InterlockedIncrement64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedincrement64) function.

## Parameters

### `Addend` [in, out]

A pointer to the variable to be incremented.

## Return value

The function returns the resulting incremented value.

## Remarks

The variable pointed to by the *Addend* parameter must be aligned on a 16-bit boundary; otherwise, this function will behave unpredictably on multiprocessor x86 systems and any non-x86 systems. See **_aligned_malloc**.

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

This function is implemented using a compiler intrinsic where possible. For more information, see the WinBase.h header file and [_InterlockedIncrement16](https://learn.microsoft.com/previous-versions/2ddez55b(v=vs.85)).

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedDecrement](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockeddecrement)

[InterlockedIncrement](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedincrement)

[InterlockedIncrement16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972663(v=vs.85))

[InterlockedIncrement16NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972664(v=vs.85))

[InterlockedIncrement16Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972665(v=vs.85))

[InterlockedIncrement64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedincrement64)

[InterlockedIncrementAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683618(v=vs.85))

[InterlockedIncrementAcquire64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683620(v=vs.85))

[InterlockedIncrementNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972667(v=vs.85))

[InterlockedIncrementNoFence64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972668(v=vs.85))

[InterlockedIncrementRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683622(v=vs.85))

[InterlockedIncrementRelease64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683624(v=vs.85))

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)