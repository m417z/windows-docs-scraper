# FltCompletePendedPreOperation function

## Description

**FltCompletePendedPreOperation** resumes processing for an I/O operation that was pended in a minifilter driver's preoperation callback ([**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine.

## Parameters

### `CallbackData`

Pointer to the callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the I/O operation. This parameter is required and cannot be NULL.

### `CallbackStatus` [in]

The status value that the minifilter driver is returning for this I/O operation. Cannot be FLT_PREOP_PENDING, FLT_PREOP_SYNCHRONIZE, or FLT_PREOP_DISALLOW_FASTIO. Must be one of the following FLT_PREOP_CALLBACK_STATUS values. For more information about the effect of these values, see the Remarks section of the reference entry for [**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback).

| Value | Meaning |
| ----- | ------- |
| FLT_PREOP_COMPLETE | The minifilter driver is completing the I/O operation. The Filter Manager does not send the I/O operation to any minifilter drivers below the caller or to the file system. The Filter Manager only calls the postoperation callback ([**PFLT_POST_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) routines of the minifilter drivers above the caller. |
| FLT_PREOP_SUCCESS_NO_CALLBACK | The minifilter driver is returning control of the I/O operation to the Filter Manager. The Filter Manager does not call the corresponding postoperation callback, if one exists, during I/O completion. |
| FLT_PREOP_SUCCESS_WITH_CALLBACK | The minifilter driver is returning control of the I/O operation to the Filter Manager. The Filter Manager calls the corresponding postoperation callback during I/O completion. |

### `Context` [in, optional]

If FLT_PREOP_SUCCESS_WITH_CALLBACK is specified for **CallbackStatus**, this parameter is an optional context pointer to be passed to the corresponding postoperation callback routine. If FLT_PREOP_COMPLETE or FLT_PREOP_SUCCESS_NO_CALLBACK is specified for **CallbackStatus**, this parameter must be NULL.

## Return value

None

## Remarks

When a minifilter driver's preoperation callback ([**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)) routine posts an I/O operation to a work queue and returns FLT_PREOP_PENDING, the Filter Manager stops processing the operation. When the operation is eventually dequeued and processed, the minifilter driver must call **FltCompletePendedPreOperation** to return the operation to the Filter Manager, which then resumes processing as directed by the **CallbackStatus** specified by the minifilter driver.

If the **CallbackStatus** parameter is FLT_PREOP_COMPLETE, **FltCompletePendedPreOperation** can be called at IRQL <= DISPATCH_LEVEL. Otherwise, callers of **FltCompletePendedPreOperation** must be running at IRQL <= APC_LEVEL.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FltCbdqInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize)

[**FltCompletePendedPostOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpostoperation)

[**FltQueueDeferredIoWorkItem**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuedeferredioworkitem)

[**PFLT_PRE_OPERATION_CALLBACK**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_pre_operation_callback)