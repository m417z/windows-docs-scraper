# InterlockedIncrement function (wdm.h)

## Description

The **InterlockedIncrement** routine increments a caller-supplied variable as an atomic operation.

## Parameters

### `Addend` [in, out]

A pointer to a variable of type LONG.

## Return value

**InterlockedIncrement** returns the incremented value.

## Remarks

**InterlockedIncrement** should be used instead of **ExInterlockedIncrementLong** because it is both more efficient and faster.

**InterlockedIncrement** is implemented inline by the compiler when appropriate and possible. It does not require a spin lock and can therefore be safely used on pageable data.

**InterlockedIncrement** is atomic only with respect to other **Interlocked*Xxx*** calls.

Interlocked operations cannot be used on non-cached memory.

## See also

[ExInterlockedAddLargeInteger](https://learn.microsoft.com/previous-versions/ff545335(v=vs.85))

[ExInterlockedAddUlong](https://learn.microsoft.com/previous-versions/ff545343(v=vs.85))

[InterlockedDecrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockeddecrement)

[InterlockedExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedexchange)