# FltFreeGenericWorkItem function

## Description

The **FltFreeGenericWorkItem** routine frees a work item allocated by the [FltAllocateGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocategenericworkitem) routine.

## Parameters

### `FltWorkItem` [in]

Opaque pointer to the work item to be freed.

## Return value

None

## Remarks

**FltFreeGenericWorkItem** frees an FLT_GENERIC_WORKITEM structure that was allocated by a previous call to [FltAllocateGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocategenericworkitem). The freed memory is returned to nonpaged pool.

## See also

[FltAllocateGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltallocategenericworkitem)

[FltQueueGenericWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuegenericworkitem)