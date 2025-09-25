# _WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS structure

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS** structure contains driver-supplied information that the framework uses when a device is idle and the system is in the system working state (S0).

## Members

### `Size`

The size, in bytes, of this structure.

### `IdleCaps`

A [WDF_POWER_POLICY_S0_IDLE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_s0_idle_capabilities)-typed enumerator that identifies the device's ability to wake itself up after being set to a low-power state, while the system remains in its working (S0) state.

### `DxState`

A DEVICE_POWER_STATE-typed enumerator that identifies the low [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) that the device will enter after the idle timeout period ends. DEVICE_POWER_STATE values are defined in *wdm.h*.

### `IdleTimeout`

The amount of time, in milliseconds, that the device will remain idle before the framework places it in the **DxState**-supplied low-power state. To use the framework's default idle timeout value, specify **IdleTimeoutDefaultValue**. For more information on when the framework considers the device to be idle, see [Supporting Idle Power-Down in UMDF-based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down-in-umdf-drivers).

### `UserControlOfIdleSettings`

A [WDF_POWER_POLICY_S0_IDLE_USER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_s0_idle_user_control)-typed enumerator that indicates whether users have the ability to modify the device's idle settings.

### `Enabled`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed enumerator that indicates whether the device will be powered down if it remains idle and while the system power is at S0. This member can have one of the following values:

**WdfTrue** - Powering down is enabled.

**WdfFalse** - Powering down is disabled.

**WdfUseDefault** - Powering down is initially enabled by default; but if the **UserControlOfIdleSettings** member is set to **IdleAllowUserControl**, the [user's setting or driver's INF file](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior-in-umdf) overrides the initial value.

If powering down is enabled, the device has a wake-up capability, and the idle timeout value expires, the framework calls the driver's [IPowerPolicyCallbackWakeFromS0::OnArmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-ipowerpolicycallbackwakefroms0-onarmwakefroms0) method before the device enters a low-power state.

### `PowerUpIdleDeviceOnSystemWake`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed enumerator that indicates whether the device will return to its working (D0) state when the system returns to its working (S0) state. This member is valid only if the driver sets the **IdleCaps** member to [IdleCannotWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_s0_idle_capabilities). The **PowerUpIdleDeviceOnSystemWake** member can have one of the following values:

**WdfTrue** - If both the device and the system are in a low-power state, the device returns to its working state when the system returns to its working state.

**WdfFalse** - If both the device and the system are in a low-power state, the device remains in the low-power state when the system returns to its working state.

**WdfUseDefault** - The default value that the framework uses if the driver does not set a different value. This value has the same meaning as **WdfFalse**.

If the **PowerUpIdleDeviceOnSystemWake** member is set to **WdfFalse** or **WdfUseDefault**, the device returns to its working state only when software accesses the device, such as when an application sends an I/O request to the device. For more information, see [A Device Returns to Its Working State](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-returns-to-its-working-state).

### `ExcludeD3Cold`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed enumerator that indicates whether the framework can put the device in the D3cold power state when the idle timeout period expires. The **ExcludeD3Cold** member can have one of the following values:

**WdfTrue** - The framework will move a device to a low-power D-state when the idle timeout period expires. If that D-state is D3, the device will be moved to D3hot. If **ExcludeD3Cold** is set to **WdfTrue**, then no further transition from D3hot to D3cold will be allowed.

**WdfFalse** - The device may enter the D3cold power state when the idle timeout period expires, if all of the following criteria are met:

* The **DxState** member of this structure specifies **PowerDeviceD3** or **PowerDeviceMaximum**.
* The ACPI firmware indicates that the device supports the D3cold power state.
* If the driver specified **IdleCanWakeFromS0** or **IdleUsbSelectiveSuspend** in the **IdleCaps** member of this structure, the device can respond to an external wake-up event while in the D3cold power state. Otherwise, this requirement does not apply.

**WdfUseDefault** - The framework examines the *DDInstall***.HW** section of the driver's INF file. If the following lines are present, this value has the same meaning as **WdfFalse**:

```
Include = machine.inf
Needs = PciD3ColdSupported
```

Otherwise, this value has the same meaning as **WdfTrue**.

The **ExcludeD3Cold** member is available starting in UMDF version 1.11, and is ignored in operating systems earlier than Windows 8. See additional information in Remarks.

## Remarks

The **WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS** structure is used as input to [IWDFDevice3::AssignS0IdleSettingsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-assigns0idlesettingsex).

The first time a driver calls [IWDFDevice3::AssignS0IdleSettingsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-assigns0idlesettingsex), the following actions occur:

* The framework stores the values of all **WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS** structure members.
* If the **UserControlOfIdleSettings** member is set to **IdleAllowUserControl** and if the **Enabled** member is set to **WdfUseDefault**, the framework reads the registry to find out if the user has enabled powering down the device when it is idle.

During subsequent calls to [IWDFDevice3::AssignS0IdleSettingsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-assigns0idlesettingsex), the framework only stores the values of the **DxState**, **IdleTimeout**, and **Enabled** members. Also, the framework stores the value of the **IdleCaps** member subject to the following rules:

* If the driver has ever specified **IdleCanWakeFromS0** for the *IdleCaps* parameter's value in a previous call to [AssignS0IdleSettingsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-assigns0idlesettingsex), it cannot subsequently change that value to **IdleUsbSelectiveSuspend**.
* If the driver has ever specified **IdleUsbSelectiveSuspend** for the *IdleCaps* parameter's value in a previous call to [AssignS0IdleSettingsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-assigns0idlesettingsex), it cannot subsequently change that value to **IdleCanWakeFromS0**.

The following rules apply to the value that you specify for the **DxState** member:

* The value cannot be **PowerDeviceD0**.
* For USB devices, the value cannot be **PowerDeviceD0** or **PowerDeviceD3**.
* If you specify **DevicePowerMaximum**, the framework uses the value that the driver for the device's bus supplied in the **DeviceWake** member of its [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure.
* If the value of the **IdleCaps** member is **IdleCanWakeFromS0**, you cannot specify a device power state that is lower than the device power state in the **DeviceWake** member of the bus driver's [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure. (In other words, if the bus driver's **DeviceWake** value is **PowerDeviceD2**, your function driver's **DxState** value cannot be **PowerDeviceD3**.)

In operating systems earlier than Windows 8, the D3 power state signifies that the device is in a low-power state, but that some power to the bus is still maintained. Starting in Windows 8, the former D3 power state is called D3hot, and a new power state (D3cold) is available. A device can enter the D3cold state either while the system is in its working (S0) state or in a low-power state. When a device is in the D3cold power state, the bus is inactive and the device must trigger its own wake signal when an external action (for example plugging in a network cable) causes a hardware event.

A device that [supports idle power-down](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down-in-umdf-drivers) can use the **ExcludeD3Cold** member of this structure to specify whether the D3cold power state should be an allowable choice for the low [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) that the device will enter after the idle timeout period ends.

For information about registry entries that control a device's idle capabilities, see [User Control of Device Idle and Wake Behavior in UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior-in-umdf).

To initialize its **WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS** structure, your driver should call [WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfdevice/nf-wudfdevice-wudf_device_power_policy_idle_settings_init).

## See also

[IWDFDevice3::AssignS0IdleSettingsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-assigns0idlesettingsex)

[WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfdevice/nf-wudfdevice-wudf_device_power_policy_idle_settings_init)