# KsAllocateDefaultClock function

## Description

The **KsAllocateDefaultClock** function allocates and initializes the default clock structure.

## Parameters

### `DefaultClock` [out]

Specifies the caller-allocated shared default clock structure. The current time is set to zero and the state is set to KSSTATE_STOP. Upon successful completion of this routine, the structure indicated by this pointer will contain a reference to the default clock. The data returned should be treated as opaque and reserved for system use.

## Return value

The **KsAllocateDefaultClock** function returns STATUS_SUCCESS if successful, or a memory error if unsuccessful.

## Remarks

The internal DefaultClock.ReferenceCount element is initialized to one by the **KsAllocateDefaultClock** function. The element is incremented and decremented as each notification DPC is queued and completed. When the structure is to be freed, the element is used to determine if the owner of the clock should free the structure or if a pending DPC should free it asynchronously.

When the clock is no longer needed, the driver must call [KsFreeDefaultClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreedefaultclock) to release any resources allocated for use with the clock.

## See also

[KsAllocateDefaultClockEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclockex)

[KsFreeDefaultClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksfreedefaultclock)