# InterlockedCompareExchange128 function

## Description

Performs an atomic compare-and-exchange operation on the specified values. The function compares two specified 128-bit values and exchanges with another 128-bit value based on the outcome of the comparison.

To operate on 16-bit values, use the [InterlockedCompareExchange16](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedcompareexchange16) function.

To operate on 32-bit values, use the [InterlockedCompareExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange) function.

To operate on 64-bit values, use the [InterlockedCompareExchange64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedcompareexchange64) function.

## Parameters

### `Destination` [in, out]

 A pointer to the destination value. This parameter is an array of two 64-bit integers considered as a 128-bit field.

### `ExchangeHigh` [in]

The high part of the exchange value.

### `ExchangeLow` [in]

The low part of the exchange value.

### `ComparandResult` [in, out]

The value to compare to. This parameter is an array of two 64-bit integers considered as a 128-bit field. On output, this is overwritten with the original value of the destination.

## Return value

The function returns 1 if *ComparandResult* equals the original value of the *Destination* parameter, or 0 if *ComparandResult* does not equal the original value of the *Destination* parameter.

## Remarks

The
function compares the *Destination* value with the *ComparandResult* value:

* If the *Destination* value is equal to the *ComparandResult* value, the *ExchangeHigh* and *ExchangeLow* values are stored in the array specified by *Destination*, and also in the array specified by *ComparandResult*.
* Otherwise, the *Destination* is left unmodified.

Regardless of the result of the comparison, the original *Destination* value is stored in the array specified by *ComparandResult*.

The parameters for this function must be aligned on a 16-byte boundary; otherwise, the function will behave unpredictably on x64 systems. See **_aligned_malloc**.

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

This function is only available on x64-based systems, and it is implemented using a compiler intrinsic. For more information, see the WinBase.h header file and [_InterlockedCompareExchange128](https://learn.microsoft.com/previous-versions/ttk2z1ws(v=vs.85)).

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedCompare64Exchange128](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683553(v=vs.85))

[InterlockedCompareExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange)

[InterlockedCompareExchange16](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedcompareexchange16)

[InterlockedCompareExchange16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972642(v=vs.85))

[InterlockedCompareExchange16NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972643(v=vs.85))

[InterlockedCompareExchange16Release](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972644(v=vs.85))

[InterlockedCompareExchange64](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedcompareexchange64)

[InterlockedCompareExchangeAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683564(v=vs.85))

[InterlockedCompareExchangeAcquire64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683566(v=vs.85))

[InterlockedCompareExchangeNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972645(v=vs.85))

[InterlockedCompareExchangeNoFence64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972646(v=vs.85))

[InterlockedCompareExchangePointer](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedcompareexchangepointer)

[InterlockedCompareExchangePointerAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683570(v=vs.85))

[InterlockedCompareExchangePointerNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972647(v=vs.85))

[InterlockedCompareExchangePointerRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683571(v=vs.85))

[InterlockedCompareExchangeRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683574(v=vs.85))

[InterlockedCompareExchangeRelease64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683576(v=vs.85))

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)