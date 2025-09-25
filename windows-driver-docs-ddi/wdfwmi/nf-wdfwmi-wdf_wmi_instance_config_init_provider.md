# WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER function

## Description

[Applies to KMDF only]

The **WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER** function initializes a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure and stores a specified handle to a WMI provider object.

## Parameters

### `Config` [out]

A pointer to a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure.

### `Provider` [in]

A handle to a WMI provider object that the driver obtained by a previous call to [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate).

## Remarks

The **WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER** function zeros the [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure that the *Config* parameter specifies and sets its **Size** member. This function also sets the structure's **Provider** member to the handle that the *Provider* parameter specifies.

Your driver should call **WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER** to initialize a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure if it calls [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate) before calling [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

#### Examples

The following code example initializes a [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure and calls [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate). Then, the example initializes a [WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config) structure and calls [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate).

```cpp
WDF_WMI_PROVIDER_CONFIG  providerConfig;
WDFWMIPROVIDER  provider;
GUID  providerGuid = MY_WMI_DATA_BLOCK_GUID;
WDF_WMI_INSTANCE_CONFIG  instanceConfig;
WDFWMIINSTANCE  instanceHandle;
NTSTATUS  status;

WDF_WMI_PROVIDER_CONFIG_INIT(
                             &providerConfig,
                             providerGuid
                             );
providerConfig.Flags = WdfWmiProviderTracing;
providerConfig.EvtWmiProviderFunctionControl = MyProviderFunctionControl;

status = WdfWmiProviderCreate(
                              Device,
                              &providerConfig,
                              WDF_NO_OBJECT_ATTRIBUTES,
                              &provider
                              );

if (!NT_SUCCESS(status)) {
    return status;
}
WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER(
                                      &instanceConfig,
                                      provider
                                      );
status = WdfWmiInstanceCreate(
                              Device,
                              &instanceConfig,
                              WDF_NO_OBJECT_ATTRIBUTES,
                              &instanceHandle
                              );
if (!NT_SUCCESS(status)) {
    return status;
}
```

## See also

[WDF_WMI_INSTANCE_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_instance_config)

[WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_instance_config_init_provider_config)

[WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config)

[WDF_WMI_PROVIDER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_provider_config_init)

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)

[WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate)