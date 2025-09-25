# _WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS** structure contains driver-supplied information about a device's ability to wake itself and the system, when both are in a low-power state.

## Members

### `Size`

The size, in bytes, of this structure.

### `DxState`

A [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)-typed enumerator that identifies the low [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) that the device will enter when the system power state drops to a wakeable low-power state. The value of **DxState** cannot be **PowerDeviceD0**. **DEVICE_POWER_STATE** values are defined in *wdm.h*.

### `UserControlOfWakeSettings`

A [WDF_POWER_POLICY_SX_WAKE_USER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_sx_wake_user_control)-typed enumerator that indicates whether users have the ability to modify the device's wake settings.

### `Enabled`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed enumerator that indicates whether the device can wake the system (that is, restore the system to S0) when the system is in a low-power state. This member can have one of the following values:

**WdfTrue** - Waking the system is enabled.

**WdfFalse** - Waking the system is disabled.

**WdfUseDefault** - Waking the system is initially enabled by default; but if the **UserControlOfWakeSettings** member is set to **WakeAllowUserControl**, the [user's setting or driver's INF file](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior) overrides the initial value.

If waking the system is enabled and the system is about to enter a low-power state, the framework calls the driver's [EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx) or [EvtDeviceArmWakeFromSxWithReason](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx_with_reason) callback function before the device enters a low-power state.

### `ArmForWakeIfChildrenAreArmedForWake`

A Boolean value that, if set to **TRUE**, indicates that a parent device's ability to wake itself and the system should be enabled when this ability is enabled for the device's child devices. For more information, see the following Remarks section. This member is available in version 1.7 and later versions of KMDF.

### `IndicateChildWakeOnParentWake`

A Boolean value that, if set to **TRUE**, indicates that the framework will provide wake-up status to child devices if a parent device detects a wake-up signal. For more information, see the following Remarks section. This member is available in version 1.7 and later versions of KMDF.

## Remarks

The **WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS** structure is used as input to [WdfDeviceAssignSxWakeSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignsxwakesettings).

To initialize its **WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS** structure, your driver should call [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_power_policy_wake_settings_init).

The first time a driver calls [WdfDeviceAssignSxWakeSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignsxwakesettings), the following actions occur:

* The framework stores the values of all **WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS** structure members.
* If the **UserControlOfWakeSettings** member is set to **WakeAllowUserControl** and if the **Enabled** member is set to **WdfUseDefault**, the framework reads the registry to find out if the user has enabled waking the system.

During subsequent calls to [WdfDeviceAssignSxWakeSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignsxwakesettings), the framework does not store the value of the **UserControlOfWakeSettings** member. In other words, the framework performs the following steps the first time the driver calls **WdfDeviceAssignSxWakeSettings** but not during later calls:

* Stores the value of the **UserControlOfWakeSettings** member.
* Looks for a user setting in the registry, if the value of the **Enabled** member is **WdfUseDefault**.

The following rules apply to the value that you specify for the **DxState** member:

* The value cannot be **PowerDeviceD0**.
* If you specify **PowerDeviceMaximum**, the framework uses the value that the driver for the device's bus supplied in the **DeviceWake** member of its [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure.
* You cannot specify a device power state that is lower than the device power state in the **DeviceWake** member of the bus driver's [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure. (In other words, if the bus driver's **DeviceWake** value is **PowerDeviceD2**, your function driver's **DxState** value cannot be **PowerDeviceD3**.)

For information about registry entries that control a device's wake capabilities, see [User Control of Device Idle and Wake Behavior](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior).

If the device that the **WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS** structure describes is a parent device, the driver for the parent device can use the **ArmForWakeIfChildrenAreArmedForWake** and **IndicateChildWakeOnParentWake** members as follows:

* If the driver sets the **ArmForWakeIfChildrenAreArmedForWake** member to **TRUE**, the framework calls the driver's [EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx) or [EvtDeviceArmWakeFromSxWithReason](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx_with_reason) callback function when a child device's wake ability is enabled, even if the parent device's wake ability is not enabled.

  To reduce power consumption, you might not want to enable your device's wake ability unless a child device that also supports a wake ability is plugged in. If your driver sets the **ArmForWakeIfChildrenAreArmedForWake** member to **TRUE**, the **Enabled** member's values have the following meanings:

  + If **Enabled** is **WdfFalse**, the framework enables your driver's wake ability only if a child device's wake ability is enabled.
  + If **Enabled** is **WdfTrue**, the framework always enables your driver's wake ability, whether your device has wake-enabled child devices or not.
  + If **Enabled** is **WdfUseDefault** and **UserControlOfWakeSettings** is **WakeAllowUserControl**, users can control whether your device is always wake-enabled or if it is wake-enabled only when your device has child devices that are wake-enabled.
* If the driver sets the **IndicateChildWakeOnParentWake** member to **TRUE**, the framework calls the [EvtDeviceWakeFromSxTriggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_wake_from_sx_triggered) callback function in the parent device's driver and in the driver for each wake-enabled child device. If the driver sets this member to **FALSE**, the framework calls the *EvtDeviceWakeFromSxTriggered* callback function in the parent device's driver only. Your driver should set **IndicateChildWakeOnParentWake** to **TRUE** if the drivers for your device's children must examine hardware to determine why the system was awakened.

For more information about how to support a device's wake ability, see [Supporting System Wake-Up](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-system-wake-up).

## See also

[EvtDeviceArmWakeFromSx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx)

[EvtDeviceArmWakeFromSxWithReason](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_sx_with_reason)

[EvtDeviceWakeFromSxTriggered](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_wake_from_sx_triggered)

[WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities)

[WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_power_policy_wake_settings_init)

[WDF_POWER_POLICY_SX_WAKE_USER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_sx_wake_user_control)

[WdfDeviceAssignSxWakeSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignsxwakesettings)

[WdfDeviceIndicateWakeStatus](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceindicatewakestatus)