# InterlockedCompareExchangePointer function

## Description

Performs an atomic compare-and-exchange operation on the specified values. The function compares two specified pointer values and exchanges with another pointer value based on the outcome of the comparison.

To operate on non-pointer values, use the [InterlockedCompareExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange) function.

## Parameters

### `Destination` [in, out]

A pointer to a pointer to the destination value.

### `Exchange` [in]

The exchange value.

### `Comperand` [in]

The value to compare to *Destination*.

## Return value

The function returns the initial value of the *Destination* parameter.

## Remarks

The function compares the *Destination* value with the *Comparand* value. If the *Destination* value is equal to the *Comparand* value, the *Exchange* value is stored in the address specified by *Destination*. Otherwise, no operation is performed.

On a 64-bit system, the parameters are 64 bits and must be aligned on 64-bit boundaries; otherwise, the function will behave unpredictably. On a 32-bit system, the parameters are 32 bits and must be aligned on 32-bit boundaries.

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

This function is implemented using a compiler intrinsic where possible. For more information, see the WinBase.h header file and [_InterlockedCompareExchangePointer](https://learn.microsoft.com/previous-versions/1b4s3xf5(v=vs.85)).

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

**Itanium-based systems:** For performance-critical applications, use [InterlockedCompareExchangePointerAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683570(v=vs.85)) or [InterlockedCompareExchangePointerRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683571(v=vs.85)) instead.

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedCompare64Exchange128](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683553(v=vs.85))

[InterlockedCompareExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange)

[InterlockedCompareExchange128](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedcompareexchange128)

[InterlockedCompareExchange16](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedcompareexchange16)

[InterlockedCompareExchange16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972642(v=vs.85))

[InterlockedCompareExchange16NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972643(v=vs.85))

[InterlockedCompareExchange16Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972644(v=vs.85))

[InterlockedCompareExchange64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedcompareexchange64)

[InterlockedCompareExchangeAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683564(v=vs.85))

[InterlockedCompareExchangeAcquire64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683566(v=vs.85))

[InterlockedCompareExchangeNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972645(v=vs.85))

[InterlockedCompareExchangeNoFence64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972646(v=vs.85))

[InterlockedCompareExchangePointerAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683570(v=vs.85))

[InterlockedCompareExchangePointerNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972647(v=vs.85))

[InterlockedCompareExchangePointerRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683571(v=vs.85))

[InterlockedCompareExchangeRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683574(v=vs.85))

[InterlockedCompareExchangeRelease64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683576(v=vs.85))

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)