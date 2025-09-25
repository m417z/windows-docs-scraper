# WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT function

## Description

[**Warning:** UMDF 2 is the latest version of UMDF and supersedes UMDF 1. All new UMDF drivers should be written using UMDF 2. No new features are being added to UMDF 1 and there is limited support for UMDF 1 on newer versions of Windows 10. Universal Windows drivers must use UMDF 2. For more info, see [Getting Started with UMDF](https://learn.microsoft.com/windows-hardware/drivers/wdf/getting-started-with-umdf-version-2).]

The **WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT** function initializes a driver's [WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wudf_device_power_policy_idle_settings) structure.

## Parameters

### `Settings` [out]

A pointer to a driver-allocated [WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wudf_device_power_policy_idle_settings) structure.

### `IdleCaps` [in]

A [WDF_POWER_POLICY_S0_IDLE_CAPABILITIES](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ne-wdfdevice-_wdf_power_policy_s0_idle_capabilities)-typed enumerator.

## Remarks

First, the **WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT** function zeros the specified [WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wudf_device_power_policy_idle_settings) structure and sets the structure's **Size** member.

Then, the function sets the structure's **IdleTimeout** member to **IdleTimeoutDefaultValue**, sets the **UserControlOfIdleSettings** member to **IdleAllowUserControl**, and sets the **Enabled** member to **WdfUseDefault**.

In addition, the function sets the **PowerUpIdleDeviceOnSystemWake** member to **WdfUseDefault**.

 The function then sets the **ExcludeD3Cold** member to **WdfUseDefault**.

Next, the function sets the structure's **IdleCaps** member to the value that the *IdleCaps* parameter specifies.

Finally, if the *IdleCaps* parameter specifies **IdleUsbSelectiveSuspend** or **IdleCanWakeFromS0**, the function sets the **DxState** member to **PowerDeviceMaximum**. If the *IdleCaps* parameter specifies **IdleCannotWakeFromS0**, the function sets the **DxState** member to **PowerDeviceD3**.

For a code example that uses **WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS_INIT**, see [IWDFDevice3::AssignS0IdleSettingsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-assigns0idlesettingsex).

## See also

[IWDFDevice3::AssignS0IdleSettingsEx](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi/nf-wudfddi-iwdfdevice3-assigns0idlesettingsex)

[WUDF_DEVICE_POWER_POLICY_IDLE_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wudfddi_types/ns-wudfddi_types-_wudf_device_power_policy_idle_settings)