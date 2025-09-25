# FltAllocateDeferredIoWorkItem function

## Description

**FltAllocateDeferredIoWorkItem** allocates a deferred-I/O work item.

## Return value

**FltAllocateDeferredIoWorkItem** returns **NULL** if there is insufficient memory in nonpaged pool to satisfy the request. Otherwise, it returns a pointer to the allocated work item.

## Remarks

**FltAllocateDeferredIoWorkItem** allocates a deferred I/O work item from nonpaged pool.

To insert this work item into a deferred I/O work queue, call [FltQueueDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuedeferredioworkitem).

To free the work item, a minifilter driver typically calls [FltFreeDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreedeferredioworkitem) from the worker routine that was specified in [FltQueueDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuedeferredioworkitem).

## See also

[FltFreeDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreedeferredioworkitem)

[FltQueueDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuedeferredioworkitem)