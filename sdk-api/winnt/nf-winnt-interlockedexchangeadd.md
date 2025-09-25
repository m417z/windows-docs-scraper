# InterlockedExchangeAdd function

## Description

Performs an atomic addition of two 32-bit values.

To operate on 64-bit values, use the [InterlockedExchangeAdd64](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangeadd64) function.

## Parameters

### `Addend` [in, out]

A pointer to a variable. The value of this variable will be replaced with the result of the operation.

### `Value` [in]

The value to be added to the variable pointed to by the *Addend* parameter.

## Return value

The function returns the initial value of the *Addend* parameter.

## Remarks

The
function performs an atomic addition of *Value* to the value pointed to by *Addend*. The result is stored in the address specified by *Addend*. The function returns the initial value of the variable pointed to by *Addend*.

The variables for
this function must be aligned on a 32-bit boundary; otherwise, this function will behave unpredictably on multiprocessor x86 systems and any non-x86 systems. See **_aligned_malloc**.

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

This function is implemented using a compiler intrinsic where possible. For more information, see the WinBase.h header file and [_InterlockedExchangeAdd](https://learn.microsoft.com/cpp/intrinsics/interlockedexchangeadd-intrinsic-functions)

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

**Itanium-based systems:** For performance-critical applications, use [InterlockedExchangeAddAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683594(v=vs.85)) instead.

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedCompareExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange)

[InterlockedExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchange)

[InterlockedExchangeAdd64](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangeadd64)

[InterlockedExchangeAddAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683594(v=vs.85))

[">InterlockedExchangeAddAcquire64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683604(v=vs.85))

[InterlockedExchangeAddNoFence](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangeadd)

[InterlockedExchangeAddNoFence64](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangeadd64)

[InterlockedExchangeAddRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683605(v=vs.85))

[InterlockedExchangeAddRelease64](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangeadd64)

[InterlockedExchangeSubtract](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-interlockedexchangesubtract)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)