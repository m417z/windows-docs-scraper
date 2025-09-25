# EVT_WDF_INTERRUPT_ISR callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtInterruptIsr* event callback function services a hardware interrupt.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

### `MessageID` [in]

If the device is using message-signaled interrupts (MSIs), this parameter is the message number that identifies the device's hardware interrupt message. Otherwise, this value is 0.

## Return value

The *EvtInterruptIsr* callback function must return **TRUE** if the function services the hardware interrupt. Otherwise, this function must return **FALSE**.

## Remarks

To register an *EvtInterruptIsr* callback function, your driver must place the callback function's address in a [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure before calling [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

The *EvtInterruptIsr* callback function is a framework-based driver's interrupt service routine (ISR), which is called when a hardware interrupt occurs.

If the interrupt is not from the hardware that this *EvtInterruptIsr* callback function services, the driver must return **FALSE**. If the interrupt vector is being shared, the system calls another interrupt service routine.

If the driver has not requested passive-level handling for an interrupt object, then before calling the *EvtInterruptIsr* callback function, the framework raises the processor's IRQL to the device's IRQL (DIRQL) and acquires the spin lock that the driver specified in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

Because the *EvtInterruptIsr* callback function executes at a relatively high IRQL, it can call very few framework object methods or system routines. Additionally, this callback function cannot access [pageable](https://learn.microsoft.com/windows-hardware/drivers/kernel/making-drivers-pageable) code.

Typically, the *EvtInterruptIsr* callback function clears the hardware interrupt and saves any information that might be lost after the callback function returns and the system lowers the IRQL (because lowering the IRQL allows additional interrupts to occur). Framework-based drivers save information about the interrupt in the interrupt object's [context space](https://learn.microsoft.com/windows-hardware/drivers/wdf/framework-object-context-space).

Drivers typically provide an [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function to process the saved information at a lower IRQL. (A few drivers provide one or more [EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc) callback functions instead of an *EvtInterruptDpc* callback function.) For information about scheduling an *EvtInterruptDpc* callback function for execution, see [Servicing an Interrupt](https://learn.microsoft.com/windows-hardware/drivers/wdf/servicing-an-interrupt).

The *EvtInterruptIsr* callback function must be able to service several interrupts before the [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function executes. Therefore, the driver might have to store interrupt data from several interrupts, and the *EvtInterruptIsr* and*EvtInterruptDpc* callback functions might have to determine which interrupt data has been completely processed by the driver and which has not.

Beginning with version 1.11 of KMDF, your driver can provide [passive-level interrupt handling](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-passive-level-interrupts). If the driver has requested passive-level handling for an interrupt object, then before calling that interrupt's *EvtInterruptIsr* callback function at IRQL = PASSIVE_LEVEL, the framework acquires the passive-level interrupt lock that the driver configured in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure. As with interrupt handling at DIRQL, the driver's *EvtInterruptIsr* function should still save information about the interrupt for later processing.

Drivers that support passive-level interrupt handling can provide either an [EvtInterruptWorkItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_workitem) or an [EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc) callback function to process the saved information.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

## See also

[EvtDpcFunc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdpc/nc-wdfdpc-evt_wdf_dpc)

[EvtInterruptDpc](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_dpc)

[WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config)

[WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate)

[WdfInterruptGetDevice](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptgetdevice)

[WdfInterruptGetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptgetinfo)

[WdfInterruptWdmGetInterrupt](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptwdmgetinterrupt)