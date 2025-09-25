# WdfInterruptQueueWorkItemForIsr function

## Description

[Applies to KMDF and UMDF]

The **WdfInterruptQueueWorkItemForIsr** method queues a framework interrupt object's [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem) callback function for execution.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

## Return value

If the driver's ISR is running at IRQL = PASSIVE_LEVEL, **WdfInterruptQueueWorkItemForIsr** returns **TRUE** if it successfully queues the interrupt object's [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem) callback function. The method returns **FALSE** if the callback function was previously queued and has not executed.

If the driver's ISR is running at IRQL = DIRQL, the framework first queues an internal DPC and then queues a work item from that DPC. In this case, **WdfInterruptQueueWorkItemForIsr** returns **TRUE** if the framework successfully queues the internal DPC. The method returns **FALSE** if the internal DPC was previously queued.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

Drivers typically call **WdfInterruptQueueWorkItemForIsr** from within an [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function.

An interrupt object's [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem) callback function can be queued only once before it executes. Therefore, if a call to **WdfInterruptQueueWorkItemForIsr** succeeds, subsequent calls will not queue additional callbacks.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

A bug check occurs if drivers call **WdfInterruptQueueWorkItemForIsr** with an interrupt object that does not specify an [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem) callback function.

## See also

[EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc)

[EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)

[WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate)

[WdfInterruptQueueDpcForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptqueuedpcforisr)