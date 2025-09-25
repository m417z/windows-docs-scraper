# ExInterlockedCompareExchange64 macro

## Description

The **ExInterlockedCompareExchange64** routine compares one integer variable to another and, if they are equal, sets the first variable to a caller-supplied value.

## Parameters

### `Destination` [in, out]

A pointer to an integer that will be compared and possibly replaced.

### `Exchange` [in]

A pointer to an integer that will replace the one at *Destination* if the comparison results in equality.

### `Comperand`

A pointer to an integer with which the value at *Destination* will be compared.

### `Lock` [in]

A pointer to a caller-allocated spin-lock that is used if the host system does not support an 8-byte atomic compare-and-exchange operation.

## Remarks

This macro wraps **InterlockedCompareExchange64** or **ExfInterlockedCompareExchange64** and assumes the return value of the type LONGLONG.

**ExInterlockedCompareExchange64** tests and, possibly, replaces the value of a given variable. For most underlying microprocessors, this routine is implemented inline by the compiler to execute as an atomic operation. If a spin lock is used, this routine can only be safely used on nonpaged parameters.

If the *Destination* and *Comparand* are unequal, **ExInterlockedCompareExchange64** simply returns the value of *Destination*.

**ExInterlockedCompareExchange64** is atomic only with respect to other **(Ex)Interlocked*Xxx*** calls.

Callers of **ExInterlockedCompareExchange64** can be running at any IRQL. The storage for the *Destination*, Comparand, and *Exchange* parameter and the list entries must be resident at all IRQLs.

## See also

[InterlockedCompareExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedcompareexchange)

[InterlockedExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedexchange)

[InterlockedExchangeAdd](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedexchangeadd)