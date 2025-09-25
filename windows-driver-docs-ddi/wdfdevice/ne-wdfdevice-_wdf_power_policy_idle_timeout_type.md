# _WDF_POWER_POLICY_IDLE_TIMEOUT_TYPE enumeration

## Description

[Applies to KMDF and UMDF]

 The **WDF_POWER_POLICY_IDLE_TIMEOUT_TYPE** enumeration identifies how the idle timeout for a device is determined.

## Constants

### `DriverManagedIdleTimeout:0`

The idle timeout value is determined by the **IdleTimeout** member of the [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure.

### `SystemManagedIdleTimeout:1`

Starting in Windows 8, the timeout value is determined by the power framework (PoFx). The value of the **IdleTimeout** member is not used.

On operating systems earlier than Windows 8, the behavior is same as **DriverManagedIdleTimeout**.

### `SystemManagedIdleTimeoutWithHint:2`

Starting in Windows 8, the PoFx uses the value specified in the **IdleTimeout** member as an input when determining at what point after all the components are idle to transition the device to a low-power (Dx) state. This option enables the driver to delay the transition to a low-power state.

The actual duration after which the PoFx allows the device to enter a low-power state might be greater than the **IdleTimeout** value.

On operating systems earlier than Windows 8, the behavior is the same as **DriverManagedIdleTimeout**.

## Remarks

The **WDF_POWER_POLICY_IDLE_TIMEOUT_TYPE** enumeration is used in the [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure.

## See also

[WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings)