# _InlineInterlockedAdd function

## Description

Performs an atomic addition operation on the specified **LONG** values. The operation is performed with acquire memory ordering semantics.

## Parameters

### `Addend` [in, out]

A pointer to the first operand. This value will be replaced with the result of the operation.

### `Value` [in]

The second operand.

## Return value

The function returns the result of the operation.

## Remarks

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

This function is implemented using a compiler intrinsic where possible. For more information, see the WinBase.h header file and [_InterlockedAdd_acq](https://learn.microsoft.com/previous-versions/51s265a6(v=vs.85)).

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedAdd](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-interlockedadd)

[InterlockedAdd64](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-_inlineinterlockedadd64)

[InterlockedAddAcquire64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683510(v=vs.85))

[InterlockedAddNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972629(v=vs.85))

[InterlockedAddNoFence64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972630(v=vs.85))

[InterlockedAddRelease](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683513(v=vs.85))

[InterlockedAddRelease64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683514(v=vs.85))

[InterlockedExchangeAdd](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangeadd)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)