# EVT_WDF_INTERRUPT_DISABLE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtInterruptDisable* event callback function disables a specified hardware interrupt.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

### `AssociatedDevice` [in]

A handle to the framework device object that the driver passed to [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

## Return value

The *EvtInterruptDisable* callback function must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE** if the function encounters no errors. Otherwise, this function must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

## Remarks

To register an *EvtInterruptDisable* callback function, your driver must place the callback function's address in a [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure before calling [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

The framework calls the driver's *EvtInterruptDisable* callback function each time the device leaves its working (D0) state. Additionally, a driver can cause the framework to call the *EvtInterruptDisable* callback function by calling [WdfInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptdisable). Note that most framework-based drivers should not call **WdfInterruptDisable**, because the framework calls the driver's *EvtInterruptDisable* callback function each time the device leaves its working (D0) state.

Before calling the *EvtInterruptDisable* callback function, the framework raises the processor's IRQL to the device's DIRQL and acquires the spin lock that the driver specified in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

Beginning with version 1.11 of KMDF, your driver can provide [passive-level interrupt handling](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-passive-level-interrupts). If the driver has requested passive-level interrupt handling, then before calling the *EvtInterruptDisable* function at IRQL = PASSIVE_LEVEL, the framework acquires the passive-level interrupt lock that the driver configured in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

Before calling the *EvtInterruptDisable* callback function, the framework calls the driver's [EvtDeviceD0ExitPreInterruptsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit_pre_interrupts_disabled) event callback function at IRQL = PASSIVE_LEVEL.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

## See also

[EvtDeviceD0ExitPreInterruptsDisabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit_pre_interrupts_disabled)

[EvtInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_enable)

[WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config)

[WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate)

[WdfInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptdisable)