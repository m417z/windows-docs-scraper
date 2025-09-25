# InterlockedExchange function (miniport.h)

## Description

The **InterlockedExchange** routine sets an integer variable to a given value as an atomic operation.

## Parameters

### `Target` [in, out]

A pointer to a variable to be set to the supplied *Value* as an atomic operation.

### `Value` [in]

Specifies the value to which the variable will be set.

## Return value

**InterlockedExchange** returns the value of the variable at *Target* when the call occurred.

## Remarks

**InterlockedExchange** should be used instead of **ExInterlockedExchangeUlong**, because it is both faster and more efficient.

**InterlockedExchange** is implemented inline by the compiler when appropriate and possible. It does not require a spin lock and can therefore be safely used on pageable data.

A call to **InterlockedExchange** routine is atomic only with respect to other **Interlocked*Xxx*** calls.

Interlocked operations cannot be used on non-cached memory.

## See also

[ExInterlockedAddLargeInteger](https://learn.microsoft.com/previous-versions/ff545335(v=vs.85))

[ExInterlockedAddUlong](https://learn.microsoft.com/previous-versions/ff545343(v=vs.85))

[InterlockedDecrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockeddecrement)

[InterlockedIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedincrement)