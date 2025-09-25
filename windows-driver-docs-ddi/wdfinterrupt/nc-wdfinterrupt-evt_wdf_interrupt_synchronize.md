# EVT_WDF_INTERRUPT_SYNCHRONIZE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtInterruptSynchronize* event callback function performs operations that must be synchronized with an [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

### `Context` [in]

Driver-supplied information that the driver specifies when it calls [WdfInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsynchronize).

## Return value

The *EvtInterruptSynchronize* callback function must return **TRUE** if the operation succeeds. Otherwise, this function must return **FALSE**.

## Remarks

To execute an *EvtInterruptSynchronize* callback function, the driver must call [WdfInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsynchronize).

If the driver has configured the interrupt object for handling at the device's IRQL (DIRQL), then before calling the *EvtInterruptSynchronize* callback function, the framework raises the processor's interrupt request level to DIRQL and acquires the spin lock that the driver specified in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

As a result, while an *EvtInterruptSynchronize* callback function is executing, the interrupt object's [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback function (and any other code that executes at DIRQL while holding the spin lock) cannot execute.

*EvtInterruptSynchronize* callback functions must be designed so that they execute for only a short period of time. They are typically used to access interrupt data that is also accessed by an interrupt object's other *EvtInterruptSynchronize* or [EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr) callback functions.

Beginning with version 1.11 of KMDF, your driver can provide [passive-level interrupt handling](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-passive-level-interrupts). If the driver has requested passive-level interrupt handling, then before calling the *EvtInterruptSynchronize* function at IRQL = PASSIVE_LEVEL, the framework acquires the passive-level interrupt lock that the driver configured in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

For more information about the *EvtInterruptSynchronize* callback function, see [Synchronizing Interrupt Code](https://learn.microsoft.com/windows-hardware/drivers/wdf/synchronizing-interrupt-code).

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

## See also

[EvtInterruptIsr](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_isr)

[WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config)

[WdfInterruptSynchronize](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptsynchronize)