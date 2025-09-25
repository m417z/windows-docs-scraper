# EVT_WDF_DEVICE_ARM_WAKE_FROM_SX callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceArmWakeFromSx* event callback function arms (that is, enables) a device so that it can trigger a wake signal while in a low-power device state. The wake signal causes the device to enter its working state (D0) and causes the system to enter its working state (S0).

## Parameters

### `Device` [in]

A handle to a framework device object.

## Return value

If the *EvtDeviceArmWakeFromSx* callback function encounters no error, it must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

If NT_SUCCESS(status) equals **FALSE**, the framework calls the driver's [EvtDeviceDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_sx) callback function. (The framework does not report a device failure to the PnP manager.)

## Remarks

To register an *EvtDeviceArmWakeFromSx* callback function, a driver must call [WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks). Drivers can register either an *EvtDeviceArmWakeFromSx* callback function or an [EvtDeviceArmWakeFromSxWithReason](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx_with_reason) callback function, but not both.

This callback function handles device-specific operations that are needed to enable the device to detect an external event that triggers a wake signal on the bus. The bus driver's [EvtDeviceEnableWakeAtBus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfpdo/nc-wdfpdo-evt_wdf_device_enable_wake_at_bus) callback function handles bus-specific operations, such as enabling the PCI bus's Power Management Event (PME) signal.

If a driver has registered an *EvtDeviceArmWakeFromSx* or [EvtDeviceArmWakeFromSxWithReason](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx_with_reason) callback function, the framework calls it while the device is still in the D0 device power state, before the bus driver lowers the device's power state but after the framework has sent a [wait/wake IRP](https://learn.microsoft.com/windows-hardware/drivers/kernel/sending-a-wait-wake-irp) on behalf of the driver.

The process occurs in the following sequence:

1. The framework determines that the system is about to enter a low-power system state.
2. The framework calls the driver's *EvtDeviceArmWakeFromSx* or [EvtDeviceArmWakeFromSxWithReason](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx_with_reason) callback function.
3. The framework asks the driver for the device's bus to lower the device's power.

Immediately before a device enters a low-power state, the framework calls the driver's [EvtDeviceD0Exit](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_d0_exit) callback function.

For more information about when the framework calls this callback function, see [PnP and Power Management Scenarios](https://learn.microsoft.com/windows-hardware/drivers/wdf/pnp-and-power-management-scenarios).

You do not need to provide an *EvtDeviceArmWakeFromSx* or [EvtDeviceArmWakeFromSxWithReason](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx_with_reason) callback function if your device does not require special hardware operations that enable the device to trigger a wake signal.

For more information about this callback function, see [Supporting System Wake-Up](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up).

## See also

[EvtDeviceArmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)

[EvtDeviceArmWakeFromSxWithReason](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx_with_reason)

[EvtDeviceDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_sx)