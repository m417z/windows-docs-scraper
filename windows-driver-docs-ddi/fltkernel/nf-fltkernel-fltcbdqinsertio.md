# FltCbdqInsertIo function

## Description

**FltCbdqInsertIo** inserts the callback data structure for an I/O operation into a filter driver's callback data queue.

## Parameters

### `Cbdq` [in, out]

Pointer to the caller's cancel-safe callback data queue. This queue must have been initialized by calling [**FltCbdqInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize).

### `Cbd` [in]

Pointer to the callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the I/O operation to be queued. The operation must be an IRP-based I/O operation.

### `Context` [in, optional]

Caller-supplied variable that receives an opaque context pointer for the I/O request. Filter drivers can use this pointer to identify a specific item in the queue so that it can be removed by calling [**FltCbdqRemoveIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremoveio). If the filter driver is not required to remove particular I/O requests from the queue, this parameter can be **NULL**.

### `InsertContext` [in, optional]

Context pointer to be passed to the filter driver's *CbdqInsertIo* callback routine.

## Return value

**FltCbdqInsertIo** returns STATUS_SUCCESS when the callback data structure was inserted into the callback data queue, or an appropriate NTSTATUS value such as the following:

| Return code | Description |
| ----------- | ----------- |
| STATUS_FLT_CBDQ_DISABLED | The callback data structure was not inserted into the callback data queue because the queue is currently disabled. To reenable the queue, call [**FltCbdqEnable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqenable). This is an error code. |

> [!NOTE]
> In the case of success, **FltCbdqInsertIo** returns whatever the filter's *InsertIo* callback returns; for example, a filter might return either STATUS_SUCCESS or STATUS_PENDING to indicate success. It is important that the filter be self-consistent on whichever value it uses to indicate success.

## Remarks

**FltCbdqInsertIo** inserts the specified callback data ([**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure into a filter driver's callback data queue.

* Note that there is a potential race condition between a filter driver inserting the callback data, and the associated IRP being cancelled. This can be avoided by immediately invoking the queue's cancellation routine if the IRP has already been cancelled.

Filter drivers can use the **FltCbdq***Xxx* routines to implement a callback data queue for IRP-based I/O operations. By using these routines, filter drivers can make their queues cancel-safe; the system transparently handles I/O cancellation for the filter drivers.

The **FltCbdq***Xxx* routines can only be used for IRP-based I/O operations. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

A callback data queue is initialized by calling [**FltCbdqInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize). **FltCbdqInsertIo** uses the functions provided in the queue's dispatch table to lock the queue and insert the callback data structure into the queue. The insert operation itself is performed by the queue's *CbdqInsertIo* routine.

See [**FltCbdqInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize) for details on how to create a callback data queue. Use [**FltCbdqRemoveIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremoveio) to remove a particular I/O request from the queue, or [**FltCbdqRemoveNextIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio) to remove the next available I/O request.

If the queue is protected by a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks) rather than a [mutex object](https://learn.microsoft.com/windows-hardware/drivers/kernel/mutex-objects) or [resource variable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite), the caller of **FltCbdqInsertIo** can be running at IRQL <= DISPATCH_LEVEL. If a mutex or resource is used, the caller must be running at IRQL <= APC_LEVEL.

## See also

[**FLT_CALLBACK_DATA**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[**FLT_CALLBACK_DATA_QUEUE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data_queue)

[**FLT_IS_IRP_OPERATION**](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[**FltCbdqDisable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable)

[**FltCbdqEnable**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqenable)

[**FltCbdqInitialize**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize)

[**FltCbdqRemoveIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremoveio)

[**FltCbdqRemoveNextIo**](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio)