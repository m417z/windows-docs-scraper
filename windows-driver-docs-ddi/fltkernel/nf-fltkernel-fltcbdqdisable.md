# FltCbdqDisable function

## Description

*FltCbdqDisable* disables a minifilter driver's callback data queue.

## Parameters

### `Cbdq` [in, out]

Pointer to the callback data queue.

## Return value

None

## Remarks

*FltCbdqDisable* disables a callback data queue so that no more items can be added to it.

Minifilter drivers can use the **FltCbdq***Xxx* routines to implement a callback data queue for IRP-based I/O operations. By using these routines, minifilter drivers can make their queues cancel-safe; the system transparently handles I/O cancellation for the minifilter drivers.

The **FltCbdq***Xxx* routines can only be used for IRP-based I/O operations. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

A minifilter driver normally calls *FltCbdqDisable* during instance teardown or minifilter driver unload. After calling this routine, the minifilter driver should empty, or *drain*, the queue. This can be done by calling [FltCbdqRemoveNextIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio) repeatedly until no more items remain in the queue.

See [FltCbdqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize) for details on how to create a callback data queue. Use [FltCbdqInsertIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio) to add an I/O request to the queue. Use [FltCbdqRemoveIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremoveio) to remove a particular I/O request from the queue, or [FltCbdqRemoveNextIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio) to remove the next available I/O request.

To reenable the queue after disabling it, call [FltCbdqEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqenable).

If the queue is protected by a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks) rather than a [mutex object](https://learn.microsoft.com/windows-hardware/drivers/kernel/mutex-objects) or [resource variable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite), the caller of *FltCbdqDisable* can be running at IRQL <= DISPATCH_LEVEL. If a mutex or resource is used, the caller must be running at IRQL <= APC_LEVEL.

## See also

[FLT_CALLBACK_DATA_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data_queue)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FltCbdqEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqenable)

[FltCbdqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize)

[FltCbdqInsertIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio)

[FltCbdqRemoveIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremoveio)

[FltCbdqRemoveNextIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio)