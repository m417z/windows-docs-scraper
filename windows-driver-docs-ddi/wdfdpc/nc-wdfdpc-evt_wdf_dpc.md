# EVT_WDF_DPC callback function

## Description

[Applies to KMDF only]

A driver's *EvtDpcFunc* callback function performs driver-defined operations at IRQL = DISPATCH_LEVEL.

## Parameters

### `Dpc` [in]

A handle to a framework DPC object.

## Remarks

To register an *EvtDpcFunc* callback function, your driver must place the function's address in a [WDF_DPC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/ns-wdfdpc-_wdf_dpc_config) structure and call [WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate).

Drivers typically [complete I/O requests](https://learn.microsoft.com/windows-hardware/drivers/wdf/completing-i-o-requests) in their *EvtDpcFunc* callback functions.

The *EvtDpcFunc* callback function executes at DISPATCH_LEVEL and must not access [pageable](https://learn.microsoft.com/windows-hardware/drivers/kernel/making-drivers-pageable) code. If an *EvtDpcFunc* callback function must perform operations at IRQL = PASSIVE_LEVEL, it can [use framework work items](https://learn.microsoft.com/windows-hardware/drivers/wdf/using-framework-work-items).

Instead of providing *EvtDpcFunc* callback functions, many drivers provide a single [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function for each type of interrupt that its devices support. If your driver creates multiple [framework queue objects](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-queue-objects) for each device, you might consider using a separate DPC object and *EvtDpcFunc* callback function for each queue.

To schedule execution of an *EvtDpcFunc* callback function, the driver must call [WdfDpcEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcenqueue). Drivers typically call **WdfDpcEnqueue** from an [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function.

When a driver calls [WdfDpcEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcenqueue), the system adds the DPC object to the system's DPC queue. If the system is not executing higher-priority tasks, it removes the object from the queue and calls the object's *EvtDpcFunc* callback function.

The system does not add the DPC object to the DPC queue if the object is already queued. An [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function might be called several times before the system calls the *EvtDpcFunc* callback function. Therefore, the *EvtDpcFunc* callback function must be able to process information from several interrupts, and it must process all of the interrupts that have occurred since the last time it was called.

Typically, it is necessary to synchronize the execution of a driver's *EvtDpcFunc* callback function with the execution of other callback functions. For more information, see [Synchronizing Interrupt Code](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronizing-interrupt-code).

To obtain a handle to a DPC object's parent object, the *EvtDpcFunc* callback function can call [WdfDpcGetParentObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcgetparentobject). To obtain a pointer to a DPC object's underlying [KDPC](https://learn.microsoft.com/windows-hardware/drivers/kernel/eprocess) structure, the *EvtDpcFunc* callback function can call [WdfDpcWdmGetDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcwdmgetdpc).

For more information about using *EvtDpcFunc* callback functions, see [Servicing an Interrupt](https://learn.microsoft.com/windows-hardware/drivers/wdf/servicing-an-interrupt).

## See also

[EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc)

[EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)

[WDF_DPC_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/ns-wdfdpc-_wdf_dpc_config)

[WdfDpcCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpccreate)

[WdfDpcEnqueue](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcenqueue)

[WdfDpcGetParentObject](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcgetparentobject)

[WdfDpcWdmGetDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nf-wdfdpc-wdfdpcwdmgetdpc)