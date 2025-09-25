# FltGetIoPriorityHintFromFileObject function

## Description

The **FltGetIoPriorityHintFromFileObject** routine is used by a minifilter driver to get IO priority information from a file object.

## Parameters

### `FileObject` [in]

A pointer to a file object. This parameter is required and cannot be **NULL**.

## Return value

The **FltGetIoPriorityHintFromFileObject** routine returns an IO priority hint retrieved from a file object.

If the *FileObject* does not have a priority, the routine returns IoPriorityNormal.

If an error occurs retrieving the priority, the routine returns IoPriorityNormal.

## Remarks

This routine is NONPAGED and can be called from paging IO paths.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltApplyPriorityInfoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltapplypriorityinfothread)

[FltGetIoPriorityHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhint)

[FltGetIoPriorityHintFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromcallbackdata)

[FltGetIoPriorityHintFromThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromthread)

[FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo)

[FltSetIoPriorityHintIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintocallbackdata)

[FltSetIoPriorityHintIntoFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintofileobject)

[FltSetIoPriorityHintIntoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintothread)

[IO_PRIORITY_INFO](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/ns-ntifs-_io_priority_info)