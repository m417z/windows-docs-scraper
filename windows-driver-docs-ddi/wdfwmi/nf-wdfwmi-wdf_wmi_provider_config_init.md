# WDF_WMI_PROVIDER_CONFIG_INIT function

## Description

[Applies to KMDF only]

The **WDF_WMI_PROVIDER_CONFIG_INIT** function initializes a [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure.

## Parameters

### `Config` [out]

A pointer to a [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure.

### `Guid` [in]

A pointer to a GUID that identifies a WMI data provider's data block.

## Remarks

The **WDF_WMI_PROVIDER_CONFIG_INIT** function zeros the specified [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure and sets its **Size** member. This function also copies the specified GUID into the structure's **Guid** member.

#### Examples

For a code example that uses **WDF_WMI_PROVIDER_CONFIG_INIT**, see [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate).

## See also

[WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config)