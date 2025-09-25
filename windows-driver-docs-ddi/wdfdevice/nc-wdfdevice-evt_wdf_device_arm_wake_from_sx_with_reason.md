# EVT_WDF_DEVICE_ARM_WAKE_FROM_SX_WITH_REASON callback function

## Description

[Applies to KMDF and UMDF]

A driver's *EvtDeviceArmWakeFromSxWithReason* event callback function arms (that is, enables) a device so that it can trigger a wake signal while in a low-power device state. The wake signal causes the device to enter its working state (D0) and causes the system to enter its working state (S0).

## Parameters

### `Device` [in]

A handle to a framework device object.

### `DeviceWakeEnabled` [in]

A Boolean value that, if **TRUE**, indicates that the device's ability to wake the system is enabled.

### `ChildrenArmedForWake` [in]

A Boolean value that, if **TRUE**, indicates that the ability of one or more child devices to wake the system is enabled.

## Return value

If the *EvtDeviceArmWakeFromSxWithReason* callback function encounters no error, it must return STATUS_SUCCESS or another status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **TRUE**. Otherwise it must return a status value for which NT_SUCCESS(*status*) equals **FALSE**.

If NT_SUCCESS(*status*) equals **FALSE**, the framework calls the driver's [EvtDeviceDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_sx) callback function. (The framework does not report a device failure to the PnP manager.)

## Remarks

Version 1.7 and later versions of KMDF support the *EvtDeviceArmWakeFromSxWithReason* callback function in addition to the [EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx) callback function.

To register an *EvtDeviceArmWakeFromSxWithReason* callback function, a driver must call [WdfDeviceInitSetPowerPolicyEventCallbacks](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceinitsetpowerpolicyeventcallbacks). Drivers can register either an [EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx) callback function or an *EvtDeviceArmWakeFromSxWithReason* callback function, but not both.

The *EvtDeviceArmWakeFromSxWithReason* callback function provides two parameters that enable the driver to determine why the framework has called it:

* The framework sets the *DeviceWakeEnabled* parameter to **TRUE** if the **Enabled** member of the [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings) structure indicates that the device can wake the system.
* The framework sets the *ChildrenArmedForWake* parameter to **TRUE** if one or more of the device's child devices can wake the system and the **ArmForWakeIfChildrenAreArmedForWake** member of WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS is set to **TRUE**.

Either one or both of these parameters can be **TRUE**, because of the following scenarios:

* The driver's device is enabled to wake the system.
* One or more of the device's child devices are enabled to wake the system.
* Both the device and one or more of its child devices are enabled to wake the system.

For more information about the *EvtDeviceArmWakeFromSxWithReason* callback function, see the Remarks section of [EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx).

## See also

[EvtDeviceArmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0)

[EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)

[EvtDeviceDisarmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_disarm_wake_from_sx)