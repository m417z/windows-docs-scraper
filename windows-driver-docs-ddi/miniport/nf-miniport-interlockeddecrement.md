# InterlockedDecrement function (miniport.h)

## Description

The **InterlockedDecrement** routine decrements a caller-supplied variable of type LONG as an atomic operation.

## Parameters

### `Addend` [in, out]

A pointer to a variable to be decremented.

## Return value

**InterlockedDecrement** returns the decremented value.

## Remarks

**InterlockedDecrement** should be used instead of **ExInterlockedDecrementLong** because it is both more efficient and faster.

**InterlockedDecrement** is implemented inline by the compiler when appropriate and possible. It does not require a spin lock and can therefore be safely used on pageable data.

**InterlockedDecrement** is atomic only with respect to other **Interlocked*Xxx*** calls.

Interlocked operations cannot be used on non-cached memory.

## See also

[ExInterlockedAddLargeInteger](https://learn.microsoft.com/previous-versions/ff545335(v=vs.85))

[ExInterlockedAddUlong](https://learn.microsoft.com/previous-versions/ff545343(v=vs.85))

[InterlockedExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedexchange)

[InterlockedIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedincrement)