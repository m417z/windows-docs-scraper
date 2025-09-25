# FltCbdqRemoveNextIo function

## Description

*FltCbdqRemoveNextIo* removes the next matching item in a minifilter driver's callback data queue.

## Parameters

### `Cbdq` [in, out]

Pointer to a cancel-safe callback data queue. This queue must have been initialized by calling [FltCbdqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize).

### `PeekContext` [in, optional]

Pointer to caller-defined information that identifies the matching item. This parameter is optional and can be **NULL**.

## Return value

*FltCbdqRemoveNextIo* returns a pointer to the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for the item that was removed from the queue or **NULL** if no matching items were found. *FltCbdqRemoveNextIo* only returns items for I/O operations that have not yet been canceled.

## Remarks

*FltCbdqRemoveNextIo* removes the next matching item from a minifilter driver's callback data queue.

Minifilter drivers can use the **FltCbdq***Xxx* routines to implement a callback data queue for IRP-based I/O operations. By using these routines, minifilter drivers can make their queues cancel-safe; the system transparently handles I/O cancellation for the minifilter drivers.

The **FltCbdq***Xxx* routines can only be used for IRP-based I/O operations. To determine whether a given callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure represents an IRP-based I/O operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

A callback data queue is initialized by [FltCbdqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize). *FltCbdqRemoveNextIo* uses the routines provided in the queue's dispatch table to lock the queue and remove the next matching item from the queue. The remove operation itself is performed by the minifilter driver's *CbdqRemoveIo* callback routine.

*FltCbdqRemoveNextIo* uses the queue's *CbdqPeekNextIo* callback routine to scan the queue for matching items. The *PeekContext* parameter is passed to the *CbdqPeekNextIo* callback routine to loop through matching items. The meaning of *PeekContext* and the criteria for an item to match a given *PeekContext* are entirely dependent on the minifilter driver.

If the queue is protected by a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks), rather than a [mutex object](https://learn.microsoft.com/windows-hardware/drivers/kernel/mutex-objects) or [resource variable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite), the caller of *FltCbdqRemoveNextIo* can be running at IRQL <= DISPATCH_LEVEL. If a mutex or resource is used, the caller must be running at IRQL <= APC_LEVEL.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_CALLBACK_DATA_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data_queue)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FltCbdqDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable)

[FltCbdqEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqenable)

[FltCbdqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize)

[FltCbdqInsertIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio)

[FltCbdqRemoveIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremoveio)