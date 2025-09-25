# WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT function

## Description

[Applies to KMDF and UMDF]

The **WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT** function initializes a driver's [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure.

## Parameters

### `Settings` [out]

A pointer to a driver-allocated [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure.

### `IdleCaps` [in]

A [WDF_POWER_POLICY_S0_IDLE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_s0_idle_capabilities)-typed enumerator.

## Remarks

First, the **WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT** function zeros the specified [WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings) structure and sets the structure's **Size** member.

Then, the function sets the structure's **IdleTimeout** member to **IdleTimeoutDefaultValue**, sets the **UserControlOfIdleSettings** member to **IdleAllowUserControl**, and sets the **Enabled** member to **WdfUseDefault**.

In addition, the function sets the **PowerUpIdleDeviceOnSystemWake** member to **WdfUseDefault** and the **IdleTimeoutType** member to **DriverManagedIdleTimeout**.

 In addition, the function sets the **ExcludeD3Cold** member to **WdfUseDefault**.

Next, the function sets the structure's **IdleCaps** member to the value that the *IdleCaps* parameter specifies.

Finally, if the *IdleCaps* parameter specifies **IdleUsbSelectiveSuspend** or **IdleCanWakeFromS0**, the function sets the **DxState** member to **PowerDeviceMaximum**. If the *IdleCaps* parameter specifies **IdleCannotWakeFromS0**, the function sets the **DxState** member to **PowerDeviceD3**.

#### Examples

For a code example that uses **WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT**, see [WdfDeviceAssignS0IdleSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdeviceassigns0idlesettings).

## See also

[WDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_device_power_policy_idle_settings)