# InterlockedExchangeAdd function (miniport.h)

## Description

The **InterlockedExchangeAdd** routine adds a value to a given integer as an atomic operation and returns the original value of the given integer.

## Parameters

### `Addend` [in, out]

A pointer to an integer variable.

### `Value` [in]

Specifies the value to be added to *Addend*.

## Return value

**InterlockedExchangeAdd** returns the original value of the *Addend* variable when the call occurred.

## Remarks

**InterlockedExchangeAdd** should be used instead of **ExInterlockedAddUlong** because it is both faster and more efficient.

**InterlockedExchangeAdd** is implemented inline by the compiler when appropriate and possible. It does not require a spin lock and can therefore be safely used on pageable data.

**InterlockedExchangeAdd** is atomic only with respect to other **Interlocked*Xxx*** calls.

Interlocked operations cannot be used on non-cached memory.

## See also

[ExInterlockedAddLargeInteger](https://learn.microsoft.com/previous-versions/ff545335(v=vs.85))

[ExInterlockedAddUlong](https://learn.microsoft.com/previous-versions/ff545343(v=vs.85))

[InterlockedDecrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockeddecrement)

[InterlockedIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedincrement)