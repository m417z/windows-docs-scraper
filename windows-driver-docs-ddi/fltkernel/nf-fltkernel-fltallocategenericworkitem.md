# FltAllocateGenericWorkItem function

## Description

**FltAllocateGenericWorkItem** allocates a generic work item.

## Return value

**FltAllocateGenericWorkItem** returns **NULL** if there is insufficient memory in nonpaged pool to satisfy the request. Otherwise, it returns a pointer to the allocated work item.

## Remarks

**FltAllocateGenericWorkItem** allocates a generic work item from nonpaged pool.

To insert this work item into a work queue, call [FltQueueGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuegenericworkitem).

To free the work item, a minifilter driver typically calls [FltFreeGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreegenericworkitem) from the worker routine that was specified in [FltQueueGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuegenericworkitem).

## See also

[FltFreeGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltfreegenericworkitem)

[FltQueueGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuegenericworkitem)