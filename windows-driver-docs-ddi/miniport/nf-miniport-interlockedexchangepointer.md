# InterlockedExchangePointer function (miniport.h)

## Description

The **InterlockedExchangePointer** routine performs an atomic operation that sets a pointer to a new value.

## Parameters

### `Target` [in, out]

A pointer to a PVOID value. The routine sets (**Target*) to *Value*.

### `Value` [in, optional]

Specifies the PVOID value to set (**Target*) to.

## Return value

**InterlockedExchangePointer** returns the original value of the pointer at **Target* (that is, the value of this pointer at entry to the routine).

## Remarks

**InterlockedExchangePointer** provides a fast, atomic way to synchronize updating a pointer variable that is shared by multiple threads.

**InterlockedExchangePointer** is designed for speed and, typically, is implemented inline by a compiler. **InterlockedExchangePointer** is atomic only with respect to other **Interlocked*Xxx*** calls. It does not use a spin lock and can be safely used on pageable data.

The *Target* parameter should be aligned on either a 32-bit or 64-bit boundary, depending on the system type, for better performance.

A call to **InterlockedExchangePointer** is atomic only with respect to other **Interlocked*Xxx*** calls.

Interlocked operations cannot be used on non-cached memory.

## See also

[InterlockedCompareExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedcompareexchange)

[InterlockedCompareExchangePointer](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedcompareexchangepointer)

[InterlockedExchange](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-interlockedexchange)