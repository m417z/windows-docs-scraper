# EVT_WDF_INTERRUPT_DPC callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtInterruptDpc* event callback function processes interrupt information that the driver's [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function has stored.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

### `AssociatedObject` [in]

A handle to the framework device object that the driver passed to [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

## Remarks

To register an *EvtInterruptDpc* callback function, your driver must place the callback function's address in a [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure before calling [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

Drivers typically [complete I/O requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) in their *EvtInterruptDpc* callback functions.

The *EvtInterruptDpc* callback function executes at DISPATCH_LEVEL and must not access [pageable](https://learn.microsoft.com/windows-hardware/drivers/kernel/making-drivers-pageable) code. If an *EvtInterruptDpc* callback function must perform operations at IRQL = PASSIVE_LEVEL, it can [use framework work items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-work-items).

In KMDF version 1.11 and later, your driver can support [passive-level interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-passive-level-interrupts) and provide either an [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem) or an *EvtInterruptDpc* callback function. If your driver supports passive-level interrupts and provides an *EvtInterruptDpc* callback function, the driver cannot acquire the passive-level interrupt lock from within the callback.

Most drivers use a single *EvtInterruptDpc* callback function for each type of interrupt. If your driver creates multiple [framework queue objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-queue-objects) for each device, you might consider using a separate [DPC object](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/) and [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback function for each queue.

To schedule execution of an *EvtInterruptDpc* callback function, the driver must call [WdfInterruptQueueDpcForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptqueuedpcforisr) from within the [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function.

When a driver schedules the execution of an *EvtInterruptDpc* callback function, the system adds a DPC object to the system's DPC queue. If the system is not executing higher-priority tasks, it removes the object from the queue and calls the *EvtInterruptDpc* callback function.

The system does not add the DPC object to the DPC queue if the object is already queued. An [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function might be called several times before the system calls the *EvtInterruptDpc* callback function. Therefore, the *EvtInterruptDpc* callback function must be able to process information from several interrupts, and it must process all interrupts that have occurred since the last time it was called.

Typically, it is necessary to synchronize the execution of a driver's *EvtInterruptDpc* callback function with the execution of other callback functions. For more information, see [Synchronizing Interrupt Code](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronizing-interrupt-code).

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

## See also

[EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc)

[EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)

[WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config)

[WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate)

[WdfInterruptQueueDpcForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptqueuedpcforisr)