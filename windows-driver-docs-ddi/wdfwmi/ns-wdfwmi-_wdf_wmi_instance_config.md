# _WDF_WMI_INSTANCE_CONFIG structure

## Description

[Applies to KMDF only]

The **WDF_WMI_INSTANCE_CONFIG** structure contains configuration information for an instance of a WMI data provider.

## Members

### `Size`

The size, in bytes, of this structure.

### `Provider`

A handle to a WMI provider object that a driver obtained by calling [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate). If this member is **NULL**, the **ProviderConfig** member must not be **NULL**.

### `ProviderConfig`

A pointer to a [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure. If this member is **NULL**, the **Provider** member must not be **NULL**.

### `UseContextForQuery`

A Boolean value that, if **TRUE**, indicates that the driver will store instance data in the WMI instance object's context space and will not provide an [EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance) callback function. Instead, the framework will service a WMI client's request for instance data by sending the contents of the context space to WMI. If this member is **FALSE**, the driver must provide an *EvtWmiInstanceQueryInstance* callback function (unless the instance data is write-only).

If **UseContextForQuery** is **TRUE**, the instance data must be read-only and therefore the driver cannot provide [EvtWmiInstanceSetInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_instance) or [EvtWmiInstanceSetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_item) callback functions.

### `Register`

A Boolean value that, if **TRUE**, indicates that the framework will register the provider instance with the system's WMI service after it creates a WMI instance object. If this member is **FALSE**, the driver must call [WdfWmiInstanceRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstanceregister) to register the provider instance.

### `EvtWmiInstanceQueryInstance`

A pointer to the driver's [EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance) callback function for the provider instance, or **NULL**.

### `EvtWmiInstanceSetInstance`

A pointer to the driver's [EvtWmiInstanceSetInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_instance) callback function for the provider instance, or **NULL**.

### `EvtWmiInstanceSetItem`

A pointer to the driver's [EvtWmiInstanceSetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_item) callback function for the provider instance, or **NULL**.

### `EvtWmiInstanceExecuteMethod`

A pointer to the driver's [EvtWmiInstanceExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_execute_method) callback function for the provider instance, or **NULL**.

## Remarks

The **WDF_WMI_INSTANCE_CONFIG** structure is used as input to the [WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate) method.

To initialize a **WDF_WMI_INSTANCE_CONFIG** structure, your driver should call [WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_instance_config_init_provider) or [WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_instance_config_init_provider_config).

## See also

[EvtWmiInstanceExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_execute_method)

[EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance)

[EvtWmiInstanceSetInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_instance)

[EvtWmiInstanceSetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_item)

[WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_instance_config_init_provider)

[WDF_WMI_INSTANCE_CONFIG_INIT_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_instance_config_init_provider_config)

[WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config)

[WdfWmiInstanceCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancecreate)

[WdfWmiInstanceRegister](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstanceregister)

[WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate)