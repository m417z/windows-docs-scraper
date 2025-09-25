# FltSetIoPriorityHintIntoThread function

## Description

The **FltSetIoPriorityHintIntoThread** routine is used by a minifilter driver to set the IO priority information in a thread.

## Parameters

### `Thread` [in]

A pointer to the thread to modify. This parameter is required and cannot be **NULL**.

### `PriorityHint` [in]

The [IO_PRIORITY_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_priority_hint) enumeration value to set for the thread information pointed to by *Thread*.

## Return value

If the IO Priority value passed to the *PriorityHint* parameter is successfully applied to the *Thread*, **FltSetIoPriorityHintIntoThread** returns STATUS_SUCCESS. Otherwise, it returns an appropriate NTSTATUS value, such as one of the following:

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The value of the *PriorityHint* parameter is invalid. This is an error code. |

## Remarks

This routine is NONPAGED and can be called from paging IO paths.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltApplyPriorityInfoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltapplypriorityinfothread)

[FltGetIoPriorityHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhint)

[FltGetIoPriorityHintFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromcallbackdata)

[FltGetIoPriorityHintFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromfileobject)

[FltGetIoPriorityHintFromThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromthread)

[FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo)

[FltSetIoPriorityHintIntoCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintocallbackdata)

[FltSetIoPriorityHintIntoFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintofileobject)

[IO_PRIORITY_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_priority_hint)