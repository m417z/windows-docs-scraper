# FltFreeDeferredIoWorkItem function

## Description

The **FltFreeDeferredIoWorkItem** routine frees a work item allocated by the [FltAllocateDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatedeferredioworkitem) routine.

## Parameters

### `FltWorkItem` [in]

Opaque pointer to the work item to be freed.

## Return value

None

## Remarks

**FltFreeDeferredIoWorkItem** frees an opaque FLT_DEFERRED_IO_WORKITEM structure that was allocated by a previous call to [FltAllocateDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatedeferredioworkitem). The freed memory is returned to nonpaged pool.

The FLT_DEFERRED_IO_WORKITEM structure is opaque: that is, its members are reserved for system use.

## See also

[FltAllocateDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocatedeferredioworkitem)

[FltQueueDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuedeferredioworkitem)