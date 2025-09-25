# EVT_WDF_INTERRUPT_WORKITEM callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtInterruptWorkItem* event callback function processes interrupt information that the driver's [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function has stored.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

### `AssociatedObject` [in]

A handle to the framework device object that the driver passed to [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

## Remarks

The *EvtInterruptWorkItem* callback function runs at IRQL = PASSIVE_LEVEL.

To register an *EvtInterruptWorkItem* callback function, your driver must place the callback function's address in a [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure before calling [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

Most drivers use a single *EvtInterruptWorkItem* callback function for each type of interrupt.

To schedule execution of an *EvtInterruptWorkItem* callback function, the driver must call [WdfInterruptQueueWorkItemForIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptqueueworkitemforisr) from within the [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function.

If your driver creates multiple framework interrupt objects for each device, you might consider using a separate *EvtInterruptWorkItem* callback for each interrupt.

Drivers that implement either DIRQL interrupt handling or passive level interrupt handling can queue an *EvtInterruptWorkItem* callback.

 A driver cannot queue both an [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) and an *EvtInterruptWorkItem* callback.

If the driver has set the **AutomaticSerialization** member to TRUE in the interrupt's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure, the framework synchronizes execution of the interrupt object's *EvtInterruptWorkItem* callback function with callback functions from other objects that are underneath the interrupt's parent object. For information about callback synchronization locks, see [Using Framework Locks](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-locks).

 In general, if the driver needs to acquire the interrupt object's passive lock from within *EvtInterruptWorkItem*, the driver should set the **AutomaticSerialization** member of [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) to FALSE and then call [WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85)) from within *EvtInterruptWorkItem*.

If **AutomaticSerialization** is set to TRUE, a driver's *EvtInterruptWorkItem* callback function should not call any of the following methods:

[WdfInterruptAcquireLock](https://learn.microsoft.com/previous-versions/ff547340(v=vs.85))
[WdfInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsynchronize)
[WdfInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptdisable)
[WdfInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptenable)
For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).