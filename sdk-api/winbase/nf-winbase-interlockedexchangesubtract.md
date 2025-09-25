# InterlockedExchangeSubtract function

## Description

Performs an atomic subtraction of two values.

## Parameters

### `Addend` [in, out]

A pointer to a variable. The value of this variable is replaced with the result of the operation.

### `Value` [in]

The value to be subtracted from the variable pointed to by the *Addend* parameter.

## Return value

The function returns the initial value of the *Addend* parameter.

## Remarks

This function generates a full memory barrier (or fence) to ensure that memory operations are completed in order.

## See also

[Interlocked Variable Access](https://learn.microsoft.com/windows/desktop/Sync/interlocked-variable-access)

[InterlockedCompareExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedcompareexchange)

[InterlockedExchange](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchange)

[InterlockedExchangeAdd](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangeadd)

[InterlockedExchangePointer](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-interlockedexchangepointer)

[Synchronization Functions](https://learn.microsoft.com/windows/desktop/Sync/synchronization-functions)