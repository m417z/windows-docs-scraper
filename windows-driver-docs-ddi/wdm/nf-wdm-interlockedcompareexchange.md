# InterlockedCompareExchange function (wdm.h)

## Description

The **InterlockedCompareExchange** routine performs an atomic operation that compares the input value pointed to by *Destination* with the value of *Comperand*.

## Parameters

### `Destination` [in, out]

A pointer to the input value that is compared with the value of *Comperand*.

### `ExChange` [in]

Specifies the output value pointed to by *Destination* if the input value pointed to by *Destination* equals the value of *Comperand*.

### `Comperand` [in]

Specifies the value that is compared with the input value pointed to by *Destination*.

## Return value

**InterlockedCompareExchange** returns the original value of **Destination*.

## Remarks

If *Comperand* is equal to **Destination*, then **Destination* is set to equal *Exchange*. Otherwise, **Destination* is unchanged.

**InterlockedCompareExchange** provides a fast, atomic way to synchronize the testing and updating of a variable that is shared by multiple threads. If the input value pointed to by *Destination* equals the value of *Comperand*, the output value of *Destination* is set to the value of *Exchange*.

**InterlockedCompareExchange** is designed for speed and, typically, is implemented inline by a compiler. **InterlockedCompareExchange** is atomic only with respect to other **Interlocked*Xxx*** calls. It does not use a spin lock and can be safely used on pageable data.

Interlocked operations cannot be used on non-cached memory.

## See also

[ExInterlockedCompareExchange64](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinterlockedcompareexchange64)

[InterlockedCompareExchangePointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedcompareexchangepointer)

[InterlockedDecrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockeddecrement)

[InterlockedExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedexchange)

[InterlockedExchangePointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedexchangepointer)

[InterlockedIncrement](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedincrement)