# FltGetIoPriorityHintFromThread function

## Description

The **FltGetIoPriorityHintFromThread** routine is used by a minifilter driver to get IO priority information from a thread.

## Parameters

### `Thread` [in]

A pointer to the thread from which to retrieve priority information. This parameter is required and cannot be **NULL**.

## Return value

The **FltGetIoPriorityHintFromThread** routine returns an IO priority hint retrieved from a thread.

If *Thread* does not have a priority, the routine returns IoPriorityNormal.

If an error occurs retrieving the priority, the routine returns IoPriorityNormal.

## Remarks

This routine is NONPAGED and can be called from paging IO paths.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltApplyPriorityInfoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltapplypriorityinfothread)

[FltGetIoPriorityHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhint)

[FltGetIoPriorityHintFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromcallbackdata)

[FltGetIoPriorityHintFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromfileobject)

[FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo)

[FltSetIoPriorityHintIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintocallbackdata)

[FltSetIoPriorityHintIntoFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintofileobject)

[FltSetIoPriorityHintIntoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintothread)

[IO_PRIORITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_io_priority_info)