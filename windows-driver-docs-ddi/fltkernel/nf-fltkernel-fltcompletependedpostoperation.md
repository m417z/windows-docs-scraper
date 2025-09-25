# FltCompletePendedPostOperation function

## Description

**FltCompletePendedPostOperation** resumes completion processing for an I/O operation that was pended in a minifilter driver's postoperation callback routine.

## Parameters

### `CallbackData` [in]

Pointer to the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the I/O operation. This parameter is required and cannot be **NULL**.

## Return value

None

## Remarks

When a minifilter driver's postoperation callback ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routine posts an I/O operation to a work queue and returns FLT_POSTOP_MORE_PROCESSING_REQUIRED, the Filter Manager stops performing completion processing for the operation. When the operation is eventually dequeued and processed, the minifilter driver can call **FltCompletePendedPostOperation** to return control of the operation to the Filter Manager, which then resumes completion processing.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FltCompletePendedPreOperation](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpreoperation)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)