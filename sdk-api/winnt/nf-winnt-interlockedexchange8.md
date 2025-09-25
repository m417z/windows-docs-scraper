# InterlockedExchange8 function

## Description

Sets an 8-bit variable to the specified value as an atomic operation.

To operate on a pointer variable, use the
[InterlockedExchangePointer](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangepointer) function.

To operate on a 16-bit variable, use the [InterlockedExchange16](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-interlockedexchange16) function.

To operate on a 32-bit variable, use the [InterlockedExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchange) function.

To operate on a 64-bit variable, use the [InterlockedExchange64](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchange64) function.

## Parameters

### `Target` [in, out]

A pointer to the value to be exchanged. The function sets this variable to *Value*, and returns its prior value.

### `Value` [in]

The value to be exchanged with the value pointed to by *Target*.

## Return value

The function returns the initial value of the *Target* parameter.

## Remarks

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

This function is implemented using a compiler intrinsic where possible. For more information, see the WinBase.h header file and [_InterlockedExchange8](https://learn.microsoft.com/cpp/intrinsics/interlockedexchange-intrinsic-functions).

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedCompareExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange)

[InterlockedExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchange)

[InterlockedExchange16](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-interlockedexchange16)

[InterlockedExchange16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972654(v=vs.85))

[InterlockedExchange16NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972655(v=vs.85))

[InterlockedExchange64](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchange64)

[InterlockedExchangeAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683594(v=vs.85))

[InterlockedExchangeAcquire64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683596(v=vs.85))

[InterlockedExchangeAdd](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangeadd)

[InterlockedExchangeNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972659(v=vs.85))

[InterlockedExchangeNoFence64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972660(v=vs.85))

[InterlockedExchangePointer](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangepointer)

[InterlockedExchangePointerAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683611(v=vs.85))

[InterlockedExchangePointerNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972661(v=vs.85))

[InterlockedExchangeSubtract](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-interlockedexchangesubtract)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)