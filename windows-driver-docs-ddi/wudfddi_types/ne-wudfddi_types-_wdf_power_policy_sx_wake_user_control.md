# _WDF_POWER_POLICY_SX_WAKE_USER_CONTROL enumeration (wudfddi_types.h)

## Description

[Applies to KMDF and UMDF]

The **WDF_POWER_POLICY_SX_WAKE_USER_CONTROL** enumeration identifies whether a user can control a device's ability to wake the system from a low system power state.

## Constants

### `WakeUserControlInvalid`

For internal use only.

### `WakeDoNotAllowUserControl`

Users cannot control the device's ability to wake the system from a low system power state.

### `WakeAllowUserControl`

Users can control the device's ability to wake the system from a low system power state.

## Remarks

The **WDF_POWER_POLICY_SX_WAKE_USER_CONTROL** enumeration is used as a member type in the [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings) structure.

To control a device's ability to wake the system from a low system power state, users modify information on a [property sheet](https://learn.microsoft.com/windows-hardware/drivers/wdf/user-control-of-device-idle-and-wake-behavior). The framework creates the property sheet and Device Manager displays it.

## See also

[WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings)