# InterlockedCompareExchangePointer function (wdm.h)

## Description

The **InterlockedCompareExchangePointer** routine performs an atomic operation that compares the input pointer value pointed to by *Destination* with the pointer value *Comperand*.

## Parameters

### `Destination` [in, out]

A pointer to a PVOID value. If (**Destination*) = *Comperand*, then the routine sets (**Destination*) to *Exchange*.

### `Exchange` [in]

Specifies the PVOID value to set (**Destination*) to.

### `Comperand` [in]

Specifies the PVOID value to compare with (**Destination*).

## Return value

**InterlockedCompareExchangePointer** returns the original value of the pointer at **Destination* (that is, the value of this pointer at entry to the routine).

## Remarks

If *Comperand* is equal to **Destination*, then **Destination* is set to equal *Exchange*. Otherwise, **Destination* is unchanged.

**InterlockedCompareExchangePointer** provides a fast, atomic way to synchronize the testing and updating of a pointer variable that is shared by multiple threads. If the input value pointed to by *Destination* equals the value of *Comperand*, the value pointed to by *Destination* is set to the value of *Exchange*.

**InterlockedCompareExchangePointer** is designed for speed and, typically, is implemented inline by a compiler. **InterlockedCompareExchangePointer** is atomic only with respect to other **Interlocked*Xxx*** calls. It does not use a spin lock and can be safely used on pageable data.

The **InterlockedCompareExchangePointer** routine is atomic only with respect to other **Interlocked*Xxx*** calls.

Interlocked operations cannot be used on non-cached memory.

## See also

[InterlockedCompareExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedcompareexchange)

[InterlockedExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedexchange)

[InterlockedExchangePointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedexchangepointer)