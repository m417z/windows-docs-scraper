# WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT** function initializes a driver's [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings) structure.

## Parameters

### `Settings` [out]

A pointer to a driver-allocated [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings) structure.

## Remarks

The **WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT** function zeros the specified [WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_wake_settings) structure and sets the structure's **Size** member. Then the function sets the structure's **Enabled** member to **WdfUseDefault**, sets the **DxState** member to **PowerDeviceMaximum**, and sets the **UserControlOfWakeSettings** member to **WakeAllowUserControl**.

For a code example that uses **WDF_DEVICE_POWER_POLICY_WAKE_SETTINGS_INIT**, see [WdfDeviceAssignSxWakeSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassignsxwakesettings).