# FltCbdqEnable function

## Description

*FltCbdqEnable* enables a callback data queue that was disabled by a previous call to [FltCbdqDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable).

## Parameters

### `Cbdq` [in, out]

Pointer to the callback data queue.

## Return value

None

## Remarks

*FltCbdqEnable* reenables a callback data queue that was disabled by a previous call to [FltCbdqDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable). After the callback data queue is reenabled, it can once again accept new items.

Minifilter drivers can use the **FltCbdq***Xxx* routines to implement a callback data queue for IRP-based I/O operations. By using these routines, minifilter drivers can make their queue cancel-safe; the system transparently handles I/O cancellation for the minifilter driver.

The **FltCbdq***Xxx* routines can only be used for IRP-based I/O operations. To determine whether a given callback data structure represents an IRP-based I/O operation, use the [FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85)) macro.

If the queue is protected by a [spin lock](https://learn.microsoft.com/windows-hardware/drivers/kernel/spin-locks) rather than a [mutex object](https://learn.microsoft.com/windows-hardware/drivers/kernel/mutex-objects) or [resource variable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-exinitializeresourcelite), the caller of *FltCbdqEnable* can be running at IRQL <= DISPATCH_LEVEL. If a mutex or resource is used, the caller must be running at IRQL <= APC_LEVEL.

## See also

[FLT_CALLBACK_DATA_QUEUE](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/ns-fltkernel-_flt_callback_data_queue)

[FLT_IS_IRP_OPERATION](https://learn.microsoft.com/previous-versions/ff544654(v=vs.85))

[FltCbdqDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqdisable)

[FltCbdqInitialize](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinitialize)

[FltCbdqInsertIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqinsertio)

[FltCbdqRemoveIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremoveio)

[FltCbdqRemoveNextIo](https://learn.microsoft.com/windows-hardware/drivers/ddi/fltkernel/nf-fltkernel-fltcbdqremovenextio)