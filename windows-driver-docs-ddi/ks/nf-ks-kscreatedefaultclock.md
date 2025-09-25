# KsCreateDefaultClock function

## Description

Given an IRP_MJ_CREATE request, the **KsCreateDefaultClock** function creates a default clock that uses the system clock as a time base and associates the IoGetCurrentIrpStackLocation(Irp)->FileObject with the clock using an internal dispatch table (KSDISPATCH_TABLE). Does not complete the IRP or set the status in the IRP.

The **KsCreateDefaultClock** function can only be called at PASSIVE_LEVEL.

## Parameters

### `Irp` [in]

Specifies the IRP with the clock-create request being handled.

### `DefaultClock` [in]

Specifies an initialize default clock structure that is shared among any instance of the default clock for the parent.

## Return value

The **KsCreateDefaultClock** function returns STATUS_SUCCESS if successful, or an error if unsuccessful.

## Remarks

The clock can be created after using **KsAllocateDefaultClock** to create and initialize the internal structures for a default clock instance. After initialization, many file objects can be created against the same underlying default clock instance.

## See also

[KsAllocateDefaultClock](https://learn.microsoft.com/windows-hardware/drivers/ddi/ks/nf-ks-ksallocatedefaultclock)