# InterlockedExchangePointer function

## Description

Atomically exchanges a pair of addresses.

## Parameters

### `Target` [in, out]

A pointer to the address to exchange. The function sets the address pointed to by the *Target* parameter (`*Target`) to the address that is the value of the *Value* parameter, and returns the prior value of the *Target* parameter.

### `Value` [in]

The address to be exchanged with the address pointed to by the *Target* parameter (`*Target`).

## Return value

The function returns the initial address pointed to by the *Target* parameter.

## Remarks

This function copies the address passed as the second parameter to the first and returns the original address of the first.

On a 64-bit system, the parameters are 64 bits and the *Target* parameter must be aligned on 64-bit boundaries; otherwise, the function will behave unpredictably. On a 32-bit system, the parameters are 32 bits and the *Target* parameter must be aligned on 32-bit boundaries.

The interlocked functions provide a simple mechanism for synchronizing access to a variable that is shared by multiple threads. This function is atomic with respect to calls to other interlocked functions.

This function is implemented using a compiler intrinsic where possible. For more information, see the WinBase.h header file and [_InterlockedExchangePointer](https://learn.microsoft.com/cpp/intrinsics/interlockedexchangepointer-intrinsic-functions).

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

**Itanium-based systems:** For performance-critical applications, use [InterlockedExchangePointerAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683611(v=vs.85)) instead.

**Note** This function is supported on Windows RT-based systems.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedCompareExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange)

[InterlockedExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchange)

[InterlockedExchange16](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-interlockedexchange16)

[InterlockedExchange16Acquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972654(v=vs.85))

[InterlockedExchange16NoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972655(v=vs.85))

[InterlockedExchange64](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchange64)

[InterlockedExchange8](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchange8)

[InterlockedExchangeAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683594(v=vs.85))

[InterlockedExchangeAcquire64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683596(v=vs.85))

[InterlockedExchangeAdd](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangeadd)

[InterlockedExchangeNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972659(v=vs.85))

[InterlockedExchangeNoFence64](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972660(v=vs.85))

[InterlockedExchangePointerAcquire](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms683611(v=vs.85))

[InterlockedExchangePointerNoFence](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/hh972661(v=vs.85))

[InterlockedExchangeSubtract](https://learn.microsoft.com/windows/win32/api/winbase/nf-winbase-interlockedexchangesubtract)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)