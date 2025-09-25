# KsFreeDefaultClock function

## Description

The **KsFreeDefaultClock** function frees a default clock structure previously allocated with [KsAllocateDefaultClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclock), taking into account any currently running timer DPCs. This assumes that all instances of the clock have been closed. This may actually just decrement the internal reference counter and allow a pending DPC to free the structure asynchronously.

This may only be called at PASSIVE_LEVEL.

## Parameters

### `DefaultClock` [in]

Specifies the previously allocated structure to free.

## Return value

None