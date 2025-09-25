## Description

The **IoMarkIrpPending** routine marks the specified IRP, indicating that a driver's dispatch routine subsequently returned STATUS_PENDING because further processing is required by other driver routines.

## Parameters

### `Irp` [in, out]

Pointer to the IRP to be marked as pending.

## Remarks

Unless the driver's dispatch routine completes the IRP (by calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)) or passes the IRP on to lower drivers, it must call **IoMarkIrpPending** with the IRP. Otherwise, the I/O manager attempts to complete the IRP as soon as the dispatch routine returns control.

After calling **IoMarkIrpPending**, the dispatch routine must return STATUS_PENDING, even if some routine completes the IRP (by calling [IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)) before the dispatch routine that called **IoMarkIrpPending** returns.

If a driver queues incoming IRPs, it should call **IoMarkIrpPending** before it queues each IRP. Otherwise, an IRP could be dequeued, completed by another driver routine, and freed by the system before the call to **IoMarkIrpPending** occurs, thereby causing a crash.

If a driver sets an [IoCompletion](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nc-wdm-io_completion_routine) routine for an IRP and then passes the IRP down to a lower driver, the *IoCompletion* routine should check the **IRP->PendingReturned** flag. If the flag is set, the *IoCompletion* routine must call **IoMarkIrpPending** with the IRP. *IoCompletion* routines do not return STATUS_PENDING. For more information, see [Implementing an IoCompletion Routine](https://learn.microsoft.com/windows-hardware/drivers/kernel/implementing-an-iocompletion-routine).

Drivers that create the IRP and send it to another stack must not call **IoMarkIrpPending** in their completion routine. This call will corrupt the pool header of the next allocation because there is no stack location for those drivers.

A driver that passes down the IRP and then waits on an event should not mark the IRP pending. Instead, its *IoCompletion* routine should signal the event and return STATUS_MORE_PROCESSING_REQUIRED.

If your driver calls [IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation), be careful not to modify the [IO_STACK_LOCATION](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location) structure in a way that could unintentionally affect the lower driver or the system's behavior with respect to that driver. In particular, your driver should not modify the **IO_STACK_LOCATION** structure's **Parameters** union, and should not call **IoMarkIrpPending**.

## See also

[**IO_STACK_LOCATION**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_io_stack_location)

[**IRP**](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/ns-wdm-_irp)

[IoCompleteRequest](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-iocompleterequest)

[IoSkipCurrentIrpStackLocation](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-ioskipcurrentirpstacklocation)

[IoStartPacket](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-iostartpacket)