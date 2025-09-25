# FltSetIoPriorityHintIntoCallbackData function

## Description

The **FltSetIoPriorityHintIntoCallbackData** routine is used by a minifilter driver to set the I/O priority information in callback data.

## Parameters

### `Data` [in]

A pointer to a [FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data) structure that represents an I/O operation. This parameter is required and cannot be **NULL**.

### `PriorityHint` [in]

The [IO_PRIORITY_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_priority_hint) enumeration value to set for the I/O operation in the callback data pointed to by *Data*.

## Return value

If this is a fast IO operation, the **FltSetIoPriorityHintIntoCallbackData** routine returns STATUS_SUCCESS.

| Return code | Description |
| --- | --- |
| **STATUS_INVALID_PARAMETER** | The value of the *PriorityHint* parameter is invalid. This is an error code. |

## Remarks

This routine is NONPAGED and can be called from paging I/O paths.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltApplyPriorityInfoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltapplypriorityinfothread)

[FltGetIoPriorityHint](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhint)

[FltGetIoPriorityHintFromCallbackData](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromcallbackdata)

[FltGetIoPriorityHintFromFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromfileobject)

[FltGetIoPriorityHintFromThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltgetiopriorityhintfromthread)

[FltRetrieveIoPriorityInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltretrieveiopriorityinfo)

[FltSetIoPriorityHintIntoFileObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintofileobject)

[FltSetIoPriorityHintIntoThread](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltsetiopriorityhintintothread)

[IO_PRIORITY_HINT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ne-wdm-_io_priority_hint)