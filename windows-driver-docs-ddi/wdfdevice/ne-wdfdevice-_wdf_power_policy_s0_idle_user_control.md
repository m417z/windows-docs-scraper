# _WDF_POWER_POLICY_S0_IDLE_USER_CONTROL enumeration (wdfdevice.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_POWER_POLICY_S0_IDLE_USER_CONTROL** enumeration identifies whether a user can control a device's behavior when the device is idle and the system is in its working (S0) state.

## Constants

### `IdleUserControlInvalid:0`

For internal use only.

### `IdleDoNotAllowUserControl`

Users cannot control the device's idle behavior.

### `IdleAllowUserControl`

Users can control the device's idle behavior.

## Remarks

The **WDF_POWER_POLICY_S0_IDLE_USER_CONTROL** enumeration is used as a member type in the [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure.

Users control a device's idle behavior by modifying information on a [property sheet](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior). The framework creates the property sheet and Device Manager displays it.

## See also

[WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings)