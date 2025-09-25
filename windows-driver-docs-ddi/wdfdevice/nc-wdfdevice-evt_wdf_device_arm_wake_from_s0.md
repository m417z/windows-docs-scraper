# EVT_WDF_DEVICE_ARM_WAKE_FROM_S0 callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceArmWakeFromS0* event callback function arms (that is, enables) a device so that it can trigger a wake signal while in a low-power device state, if the system remains in the [system working state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-working-state-s0) (S0).

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

If the operation is successful, the *EvtDeviceArmWakeFromS0* callback function must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

If NT_SUCCESS(status) equals **FALSE**, the framework does not call the driver's [EvtDeviceDisarmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_s0) callback function. (The framework does not report a device failure to the PnP manager.)

## Remarks

To register an *EvtDeviceArmWakeFromS0* callback function, a driver must call [WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks). Additionally, the driver must set **IdleCanWakeFromS0** in the **IdleCaps** member of its [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure.

The *EvtDeviceArmWakeFromS0* callback function handles device-specific operations that are needed to enable the device to detect an external event that triggers a wake signal on the bus. The bus driver's [EvtDeviceEnableWakeAtBus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_enable_wake_at_bus) callback function handles bus-specific operations, such as enabling the PCI bus's Power Management Event (PME) signal.

If the driver has registered an *EvtDeviceArmWakeFromS0* callback function, the framework calls it while the device is still in the D0 device power state, before the bus driver lowers the device's power state but after the framework has sent a [wait/wake IRP](https://learn.microsoft.com/windows-hardware/drivers/kernel/sending-a-wait-wake-irp) on behalf of the driver.

The process occurs in the following sequence:

1. The framework determines that the device has been idle for a preset amount of time.
2. The framework calls the driver's *EvtDeviceArmWakeFromS0* callback function.
3. The framework requests the driver for the device's bus to lower the device's power.

Immediately before your device enters a low power state, the framework will call your driver's [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

You do not need to provide an *EvtDeviceArmWakeFromS0* callback function if your device:

* Is a USB device that supports "selective suspend."
* Cannot be powered down while the system remains fully powered.
* Does not require special hardware operations that enable the device to trigger a wake signal.

If your device supports USB "selective suspend" and if your driver sets **IdleUsbSelectiveSuspend** in the **IdleCaps** member of its [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure, the framework sends a "selective suspend" request to the USB bus driver when the device has been idle for a preset amount of time.

For more information about this callback function, see [Supporting Idle Power-Down](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down).

## See also

[EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)

[EvtDeviceDisarmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_s0)