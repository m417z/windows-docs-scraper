# EVT_WDF_INTERRUPT_ENABLE callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtInterruptEnable* event callback function enables a specified hardware interrupt.

## Parameters

### `Interrupt` [in]

A handle to a framework interrupt object.

### `AssociatedDevice` [in]

A handle to the framework device object that the driver passed to [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

## Return value

The *EvtInterruptEnable* callback function must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE** if the function encounters no errors. Otherwise, this function must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

## Remarks

To register an *EvtInterruptEnable* callback function, your driver must place the callback function's address in a [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure before calling [WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate).

The framework calls the driver's *EvtInterruptEnable* callback function each time the device enters its working (D0) state. Additionally, a driver can cause the framework to call the *EvtInterruptEnable* callback function by calling [WdfInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptenable). Note that most framework-based drivers should not call **WdfInterruptEnable**, because the framework calls the driver's *EvtInterruptEnable* callback function each time the device enters its working (D0) state.

Before calling the *EvtInterruptEnable* callback function, the framework raises the processor's IRQL to the device's DIRQL and acquires the spin lock that the driver specified in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

Beginning with version 1.11 of KMDF, your driver can provide [passive-level interrupt handling](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-passive-level-interrupts). If the driver has requested passive-level interrupt handling, then before calling the *EvtInterruptEnable* function at IRQL = PASSIVE_LEVEL, the framework acquires the passive-level interrupt lock that the driver configured in the interrupt object's [WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config) structure.

After the *EvtInterruptEnable* callback function returns, the framework calls the driver's [EvtDeviceD0EntryPostInterruptsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry_post_interrupts_enabled) event callback function at IRQL = PASSIVE_LEVEL.

You must not assume that a device will use the same interrupt resources each time the framework calls your driver's *EvtInterruptEnable* callback function. Sometimes the PnP manager [redistributes system resources](https://learn.microsoft.com/windows-hardware/drivers/wdf/the-pnp-manager-redistributes-system-resources), and it might assign new interrupt resources to your device. The driver can call [WdfInterruptGetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptgetinfo) to determine a device's interrupt resources.

For more information about handling interrupts in framework-based drivers, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

## See also

[EvtDeviceD0EntryPostInterruptsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry_post_interrupts_enabled)

[EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable)

[WDF_INTERRUPT_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/ns-wdfinterrupt-_wdf_interrupt_config)

[WdfInterruptCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptcreate)

[WdfInterruptEnable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptenable)

[WdfInterruptGetInfo](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nf-wdfinterrupt-wdfinterruptgetinfo)