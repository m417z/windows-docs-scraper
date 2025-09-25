# FltDoCompletionProcessingWhenSafe function

## Description

If it is safe to do so, the **FltDoCompletionProcessingWhenSafe** function executes a minifilter driver post-operation callback routine.

## Parameters

### `Data` [in]

Pointer to the callback data structure ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) for the I/O operation. Usually this is the same as the *Data* pointer that was passed to the postoperation callback routine ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)) that called **FltDoCompletionProcessingWhenSafe**.

### `FltObjects` [in]

Pointer to the related objects structure ([FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)) for the I/O operation. Usually this is the same as the *FltObjects* pointer that was passed to the postoperation callback routine that called **FltDoCompletionProcessingWhenSafe**.

### `CompletionContext` [in, optional]

Pointer to a caller-supplied context information that will be passed in to the callback function that is specified in the *SafePostCallback* parameter.

### `Flags` [in]

Bitmask of flags which specify how completion processing will be performed. Usually this is the same as the *Flags* value that was passed to the postoperation callback routine that called **FltDoCompletionProcessingWhenSafe**. For more information, see the following Remarks section.

### `SafePostCallback` [in]

Pointer to a caller-supplied [PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)-typed callback routine that the operating system calls when it is safe to do so.

### `RetPostOperationStatus` [out]

Caller-allocated variable that receives the final status value for the I/O operation. For more information on how this parameter is set, see the following Remarks section.

## Return value

**FltDoCompletionProcessingWhenSafe** returns **TRUE** if completion processing for the I/O operation can be performed immediately or the I/O operation was successfully posted to a worker thread; otherwise, it returns **FALSE**.

## Remarks

**FltDoCompletionProcessingWhenSafe** executes the *SafePostCallback* immediately if the caller is running at IRQL <= APC_LEVEL. Otherwise, if it is safe to post the operation to a worker thread, the *SafePostCallback* processing is deferred until it can be called in a thread context where IRQL <= APC_LEVEL.

If IRQL < DISPATCH_LEVEL:

- **FltDoCompletionProcessingWhenSafe** immediately calls the *SafePostCallback* callback routine.
- The *RetPostOperationStatus* parameter receives a FLT_POSTOP_CALLBACK_STATUS value returned by *SafePostCallback*.
- **FltDoCompletionProcessingWhenSafe** returns **TRUE**.

If IRQL >= DISPATCH_LEVEL:

- **FltDoCompletionProcessingWhenSafe** attempts to post the I/O operation to a worker thread, and then call the *SafePostCallback* routine from the worker thread.
- If the I/O operation could be safely posted:
  - Filter manager sets *RetPostOperationStatus* to FLT_POSTOP_MORE_PROCESSING_REQUIRED.
  - **FltDoCompletionProcessingWhenSafe** returns **TRUE**.
- If the I/O operation could not be safely posted:
  - Filter manager sets *RetPostOperationStatus* to FLT_POSTOP_FINISHED_PROCESSING.
  - **FltDoCompletionProcessingWhenSafe** returns **FALSE**.

**FltDoCompletionProcessingWhenSafe** can only be called for IRP-based operations. To determine whether the operation is an IRP-based operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

**FltDoCompletionProcessingWhenSafe** cannot be used to post completion of a paging I/O operation to a worker thread.

**FltDoCompletionProcessingWhenSafe** can only be called from a minifilter driver's postoperation callback routine ([PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)). Note that **FltDoCompletionProcessingWhenSafe** should never be called if the *Flags* parameter of the postoperation callback has the FLTFL_POST_OPERATION_DRAINING bit set.

If a minifilter calls **FltDoCompletionProcessingWhenSafe** and the *SafePostCallback* is invoked in a worker thread because it is not safe to invoke it in the current thread context, the filter manager will resume completion processing as long as the minifilter does not return FLT_POSTOP_MORE_PROCESSING_REQUIRED from the *SafePostCallback*.

If the minifilter does return FLT_POSTOP_MORE_PROCESSING_REQUIRED from the *SafePostCallback*, the minifilter must call [**FltCompletePendedPostOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpostoperation) to resume completion processing.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FLT_RELATED_OBJECTS](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_related_objects)

[**FltCancelIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio)

[**FltCompletePendedPostOperation**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcompletependedpostoperation)

[PFLT_POST_OPERATION_CALLBACK](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nc-fltkernel-pflt_post_operation_callback)