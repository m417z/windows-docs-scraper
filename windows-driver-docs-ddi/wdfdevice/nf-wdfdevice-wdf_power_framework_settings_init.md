# WDF_POWER_FRAMEWORK_SETTINGS_INIT function

## Description

[Applies to KMDF only]

The **WDF_POWER_FRAMEWORK_SETTINGS_INIT** function initializes a [WDF_POWER_FRAMEWORK_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_framework_settings) structure.

## Parameters

### `PowerFrameworkSettings` [out]

A pointer to a driver-allocated [WDF_POWER_FRAMEWORK_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_framework_settings) structure.

## Remarks

The **WDF_POWER_FRAMEWORK_SETTINGS_INIT** function zeros the specified [WDF_POWER_FRAMEWORK_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_framework_settings) structure and sets the structure's **Size** member.

#### Examples

For a code example that uses **WDF_POWER_FRAMEWORK_SETTINGS_INIT**, see [WdfDeviceWdmAssignPowerFrameworkSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmassignpowerframeworksettings).

## See also

[WDF_POWER_FRAMEWORK_SETTINGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/ns-wdfdevice-_wdf_power_framework_settings)

[WdfDeviceWdmAssignPowerFrameworkSettings](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfdevice/nf-wdfdevice-wdfdevicewdmassignpowerframeworksettings)