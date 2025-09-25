# FltSetCancelCompletion function

## Description

A minifilter driver calls **FltSetCancelCompletion** to specify a cancel routine to be called if a given I/O operation is canceled.

## Parameters

### `CallbackData` [in]

Pointer to the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the I/O operation. The operation must be an IRP-based I/O operation and must not be a paging I/O operation. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro. This parameter is required and cannot be **NULL**.

### `CanceledCallback` [in]

Pointer to a caller-supplied cancel routine. The Filter Manager calls this routine if the I/O operation represented by *CallbackData* is canceled.

This routine is declared as follows:

```
typedef VOID
(*PFLT_COMPLETE_CANCELED_CALLBACK) (
      IN PFLT_CALLBACK_DATA CallbackData
      );
```

#### CallbackData

Pointer to the FLT_CALLBACK_DATA structure for the I/O operation.

## Return value

**FltSetCancelCompletion** returns STATUS_SUCCESS or an appropriate NTSTATUS value.

## Remarks

**FltSetCancelCompletion** specifies a cancel routine for an IRP-based I/O operation that is to be posted to a work queue.

Minifilter drivers usually call **FltSetCancelCompletion** for an I/O operation immediately before calling [FltQueueDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuedeferredioworkitem) to post the operation to a work queue.

Do not call **FltSetCancelCompletion** for any I/O operation that is to be posted to a cancel-safe callback data queue using the **FltCbdq***Xxx* routines.

The Filter Manager calls the *CanceledCallback* routine without holding the system cancel spin lock or performing any other synchronization. Any required synchronization must be supplied by the minifilter driver itself.

To cancel an I/O operation, call [FltCancelIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio).

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FltCancelIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcancelio)

[FltClearCancelCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltclearcancelcompletion)

[FltQueueDeferredIoWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltqueuedeferredioworkitem)