# _IO_PRIORITY_INFO structure

## Description

The IO_PRIORITY_INFO structure is used to hold thread priority information.

## Members

### `Size`

Read-only member initialized by the [IoInitializePriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioinitializepriorityinfo) routine.

### `ThreadPriority`

Read-only member used to hold a thread's priority.

### `PagePriority`

Read-only member used to hold a thread's paging priority.

### `IoPriority`

Read-only member used to hold a thread's I/O priority.

## Remarks

The IO_PRIORITY_INFO structure is used by the [FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo) and [FltApplyPriorityInfoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltapplypriorityinfothread) routines to save and set a thread's priority state.

A structure of type IO_PRIORITY_INFO must be initialized before first use by calling either the [IoInitializePriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioinitializepriorityinfo) routine or the [FltApplyPriorityInfoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltapplypriorityinfothread) routine.

## See also

[FltApplyPriorityInfoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltapplypriorityinfothread)

[FltGetIoPriorityHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhint)

[FltGetIoPriorityHintFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromcallbackdata)

[FltGetIoPriorityHintFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromfileobject)

[FltGetIoPriorityHintFromThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromthread)

[FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo)

[FltSetIoPriorityHintIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintocallbackdata)

[FltSetIoPriorityHintIntoFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintofileobject)

[FltSetIoPriorityHintIntoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintothread)

[IoInitializePriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-ioinitializepriorityinfo)