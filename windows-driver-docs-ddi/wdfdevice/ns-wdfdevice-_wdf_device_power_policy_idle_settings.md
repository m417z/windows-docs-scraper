# _WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS structure

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS** structure contains driver-supplied information that the framework uses when a device is idle and the system is in the [system working state](https://learn.microsoft.com/windows-hardware/drivers/kernel/system-working-state-s0) (S0).

## Members

### `Size`

The size, in bytes, of this structure.

### `IdleCaps`

A [WDF_POWER_POLICY_S0_IDLE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_s0_idle_capabilities)-typed enumerator that identifies the device's ability to wake itself up after being set to a low-power state, while the system remains in its working (S0) state.

### `DxState`

A [DEVICE_POWER_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/ne-wudfddi-_device_power_state)-typed enumerator that identifies the low [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) that the device will enter after the idle timeout period ends. **DEVICE_POWER_STATE** values are defined in *wdm.h*.

### `IdleTimeout`

The amount of time, in milliseconds, that the device will remain idle before the framework places it in the **DxState**-supplied low-power state. To use the framework's default idle timeout value, specify **IdleTimeoutDefaultValue**. For more information on when the framework considers the device to be idle, see [Supporting Idle Power-Down](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down).

### `UserControlOfIdleSettings`

A [WDF_POWER_POLICY_S0_IDLE_USER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_s0_idle_user_control)-typed enumerator that indicates whether users have the ability to modify the device's idle settings.

### `Enabled`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed enumerator that indicates whether the device will be powered down if it remains idle and while the system power is at S0. This member can have one of the following values:

**WdfTrue** - Powering down is enabled.

**WdfFalse** - Powering down is disabled.

**WdfUseDefault** - Powering down is initially enabled by default; but if the **UserControlOfIdleSettings** member is set to **IdleAllowUserControl**, the [user's setting or driver's INF file](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior) overrides the initial value.

If powering down is enabled, the device has a wake-up capability, and the idle timeout value expires, the framework calls the driver's [EvtDeviceArmWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nc-wdfdevice-evt_wdf_device_arm_wake_from_s0) callback function before the device enters a low-power state.

### `PowerUpIdleDeviceOnSystemWake`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed enumerator that indicates whether the device will return to its working (D0) state when the system returns to its working (S0) state. This member is valid only if the driver sets the **IdleCaps** member to [IdleCannotWakeFromS0](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_s0_idle_capabilities). The **PowerUpIdleDeviceOnSystemWake** member can have one of the following values:

**WdfTrue** - If both the device and the system are in a low-power state, the device returns to its working state when the system returns to its working state.

**WdfFalse** - If both the device and the system are in a low-power state, the device remains in the low-power state when the system returns to its working state.

**WdfUseDefault** - The default value that the framework uses if the driver does not set a different value. This value has the same meaning as **WdfFalse**.

If the **PowerUpIdleDeviceOnSystemWake** member is set to **WdfFalse** or **WdfUseDefault**, the device returns to its working state only when software accesses the device, such as when an application sends an I/O request to the device. For more information, see [A Device Returns to Its Working State](https://learn.microsoft.com/windows-hardware/drivers/wdf/a-device-returns-to-its-working-state).

The **PowerUpIdleDeviceOnSystemWake** member is available in version 1.9 and later versions of KMDF, and starting in version 2.0 of UMDF.

### `IdleTimeoutType`

A [WDF_POWER_POLICY_IDLE_TIMEOUT_TYPE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_idle_timeout_type)-typed enumerator that indicates how the **IdleTimeout** member is used.

The **IdleTimeoutType** member is available in version 1.11 and later versions of KMDF, and starting in version 2.0 of UMDF. See additional information in Remarks.

### `ExcludeD3Cold`

A [WDF_TRI_STATE](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdftypes/ne-wdftypes-_wdf_tri_state)-typed enumerator that indicates whether the D3cold power state should be an allowable choice for the low-power state that the device will enter when the idle timeout period expires. The **ExcludeD3Cold** member can have one of the following values:

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

The **ExcludeD3Cold** member is available starting in KMDF version 1.11, as well as starting in version 2.0 of UMDF, and is ignored in operating systems earlier than Windows 8. See additional information in Remarks.

## Remarks

The **WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS** structure is used as input to [WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings).

The first time a driver calls [WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings), the following actions occur:

* The framework stores the values of all **WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS** structure members.
* If the **UserControlOfIdleSettings** member is set to **IdleAllowUserControl** and if the **Enabled** member is set to **WdfUseDefault**, the framework reads the registry to find out if the user has enabled powering down the device when it is idle.

During subsequent calls to [WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings), the framework only stores the values of the **DxState**, **IdleTimeout**, and **Enabled** members. Also, in KMDF 1.9 and earlier, the framework stores the value of the **IdleCaps** member *unless* the value is **IdleUsbSelectiveSuspend**. Therefore, the driver must use the following rules:

* If the driver specifies **IdleUsbSelectiveSuspend** for the **IdleCaps** member's value, it must do so the first time that it calls [WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings), and it cannot subsequently change that value.
* If the driver specifies **IdleCanWakeFromS0** or **IdleCannotWakeFromS0** the first time it calls [WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings), it can subsequently call **WdfDeviceAssignS0IdleSettings** again to change that value (but it cannot change the value to **IdleUsbSelectiveSuspend**).

Starting in KMDF 1.11 and UMDF 2.0, a KMDF driver can switch between **IdleUsbSelectiveSuspend** and **IdleCannotWakeFromS0** at any time.

Starting in Windows 8, setting the **IdleTimeoutType** member to **SystemManagedIdleTimeout** or **SystemManagedIdleTimeoutWithHint** causes the framework to register with the power management framework (PoFx).

If the driver is implementing functional power state support for a multiple-component device, the driver must either set **IdleTimeoutType** to **DriverManagedIdleTimeout** or not call [WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings) at all.

 For more information, see [Supporting Functional Power States](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-functional-power-states) and [Overview of the Power Management Framework](https://learn.microsoft.com/windows-hardware/drivers/kernel/overview-of-the-power-management-framework).

The following rules apply to the value that you specify for the **DxState** member:

* The value cannot be **PowerDeviceD0**.
* For USB devices, the value cannot be **PowerDeviceD0** or **PowerDeviceD3**.
* If you specify **PowerDeviceMaximum**, the framework uses the value that the driver for the device's bus supplied in the **DeviceWake** member of its [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure.
* If the value of the **IdleCaps** member is **IdleCanWakeFromS0**, you cannot specify a device power state that is lower than the device power state in the **DeviceWake** member of the bus driver's [WDF_DEVICE_POWER_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_capabilities) structure. (In other words, if the bus driver's **DeviceWake** value is **PowerDeviceD2**, your function driver's **DxState** value cannot be **PowerDeviceD3**.)

In operating systems earlier than Windows 8, the D3 power state signifies that the device is in a low-power state, but that some power to the bus is still maintained. Starting in Windows 8, the former D3 power state is called D3hot, and a new power state (D3cold) is available. A device can enter the D3cold state either while the system is in its working (S0) state or in a low-power state. When a device is in the D3cold power state, the bus is inactive and the device must trigger its own wake signal when an external action (for example plugging in a network cable) causes a hardware event.

Starting in KMDF 1.11 and UMDF 2.0, a device that [supports idle power-down](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-idle-power-down) can use the **ExcludeD3Cold** member of this structure to specify whether the D3cold power state should be an allowable choice for the low [device power state](https://learn.microsoft.com/windows-hardware/drivers/kernel/device-power-states) that the device will enter after the idle timeout period ends.

For information about registry entries that control a device's idle capabilities, see [User Control of Device Idle and Wake Behavior](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior).

To initialize its **WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS** structure, your driver should call [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdf_device_power_policy_idle_settings_init).