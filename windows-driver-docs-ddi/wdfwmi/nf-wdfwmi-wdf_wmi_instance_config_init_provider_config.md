# WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG function

## Description

[Applies to KMDF only]

The **WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG** function initializes a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure and stores a pointer to a specified [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure.

## Parameters

### `Config` [out]

A pointer to a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure.

### `ProviderConfig` [in]

A pointer to a [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure.

## Remarks

The **WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG** function zeros the specified [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure and sets its **Size** member. The function also sets the structure's **ProviderConfig** member to the specified pointer.

Your driver should call **WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG** to initialize a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure if it does not call [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate) before calling [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

#### Examples

For a code example the uses **WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG**, see [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

## See also

[WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config)

[WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_instance_config_init_provider)

[WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config)

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)

[WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate)