# FltCbdqRemoveIo function

## Description

*FltCbdqRemoveIo* removes a particular item from a minifilter driver's callback data queue.

## Parameters

### `Cbdq` [in, out]

Pointer to a cancel-safe callback data queue. This queue must have been initialized by calling [FltCbdqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize).

### `Context` [in]

Context pointer for the item to be removed. This context is initialized by [FltCbdqInsertIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio) when the I/O request is first inserted in the queue. This parameter is required and must be non-**NULL**.

## Return value

*FltCbdqRemoveIo* returns a pointer to the callback data structure for the I/O request that was removed from the queue. If no matching I/O request is found or if the queue is empty, *FltCbdqRemoveIo* returns **NULL**.

## Remarks

*FltCbdqRemoveIo* removes the callback data ([FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)) structure for a particular I/O operation from a minifilter driver's callback data queue. *FltCbdqRemoveIo* can only be used to delete a callback data structure that has a *Context* structure associated with it. This association is created when the callback data structure is inserted into the callback data queue by [FltCbdqInsertIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio).

Minifilter drivers can use the **FltCbdq***Xxx* routines to implement a callback data queue for IRP-based I/O operations. By using these routines, minifilter drivers can make their queues cancel-safe; the system transparently handles I/O cancellation for the minifilter drivers.

The **FltCbdq***Xxx* routines can only be used for IRP-based I/O operations. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

A callback data queue is initialized by [FltCbdqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize). *FltCbdqRemoveIo* uses the routines provided in the queue's dispatch table to lock the queue and remove the callback data structure from the queue. The remove operation itself is performed by the minifilter driver's *CbdqRemoveIo* callback routine.

If the queue is protected by a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks) rather than a [mutex object](https://learn.microsoft.com/windows-hardware/drivers/kernel/mutex-objects) or [resource variable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite), the caller of *FltCbdqRemoveIo* can be running at IRQL <= DISPATCH_LEVEL. If a mutex or resource is used, the caller must be running at IRQL <= APC_LEVEL.

There is a potential race between the filter manager removing a cancelled I/O request, and the filter driver removing it because it was completed. It is important to note that the request context remains valid after it is first removed, which will cause a second removal attempt to fail.

## See also

[FLT_CALLBACK_DATA](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data)

[FLT_CALLBACK_DATA_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data_queue)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FltCbdqDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable)

[FltCbdqEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqenable)

[FltCbdqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize)

[FltCbdqInsertIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio)

[FltCbdqRemoveNextIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio)