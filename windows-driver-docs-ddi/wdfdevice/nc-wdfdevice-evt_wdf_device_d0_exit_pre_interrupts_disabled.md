# EVT_WDF_DEVICE_D0_EXIT_PRE_INTERRUPTS_DISABLED callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceD0ExitPreInterruptsDisabled* event callback function performs device-specific operations that are required before the driver disables the device's hardware interrupts.

## Parameters

### `Device` [in]

A handle to a framework device object.

### `TargetState` [in]

A [WDF_POWER_DEVICE_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_device_state)-typed enumerator that identifies the device power state that the device is about to enter.

## Return value

If the *EvtDeviceD0ExitPreInterruptsDisabled* callback function encounters no errors, it must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise, it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

For more information about this callback function's return values, see [Reporting Device Failures](https://learn.microsoft.com/windows-hardware/drivers/wdf/reporting-device-failures).

## Remarks

To register an *EvtDeviceD0ExitPreInterruptsDisabled* callback function, a driver must call [WdfDeviceInitSetPnpPowerEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpnppowereventcallbacks).

The *EvtDeviceD0ExitPreInterruptsDisabled* callback function is called at IRQL = PASSIVE_LEVEL, before the framework calls the driver's [EvtInterruptDisable](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinterrupt/nc-wdfinterrupt-evt_wdf_interrupt_disable) callback function. A driver can provide this function if it must perform device-specific operations before disables an interrupt, if those operations should not be performed at IRQL = DIRQL in the *EvtInterruptDisable* callback function.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

For more information about handling interrupts, see [Handling Hardware Interrupts](https://learn.microsoft.com/windows-hardware/drivers/wdf/handling-hardware-interrupts).

## See also

[EvtDeviceD0EntryPostInterruptsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_entry_post_interrupts_enabled)