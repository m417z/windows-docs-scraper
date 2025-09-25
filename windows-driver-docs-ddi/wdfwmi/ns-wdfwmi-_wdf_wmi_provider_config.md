# _WDF_WMI_PROVIDER_CONFIG structure

## Description

[Applies to KMDF only]

The **WDF_WMI_PROVIDER_CONFIG** structure contains configuration information for a driver's WMI data block.

## Members

### `Size`

The size, in bytes, of this structure.

### `Guid`

The symbolic name of a [GUID](https://learn.microsoft.com/windows-hardware/customize/desktop/unattend/microsoft-windows-shell-setup-notificationarea-promotedicon2-guid) that identifies a WMI data block.

### `Flags`

A bitwise OR of [WDF_WMI_PROVIDER_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ne-wdfwmi-_wdf_wmi_provider_flags)-typed values.

### `MinInstanceBufferSize`

The minimum size, in bytes, of fixed-length buffers that the [EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance) and [EvtWmiInstanceSetInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_instance) callback functions will use for provider instances. This member must be zero for variable-length buffers. This member is ignored if **WdfWmiProviderEventOnly** is set in the **Flags** member.

### `EvtWmiProviderFunctionControl`

A pointer to the driver's [EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control) callback function, or **NULL**.

## Remarks

The **WDF_WMI_PROVIDER_CONFIG** structure is used as input to the [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate) method.

To initialize a **WDF_WMI_PROVIDER_CONFIG** structure, your driver should call [WDF_WMI_PROVIDER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_provider_config_init).

## See also

[EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance)

[EvtWmiInstanceSetInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_instance)

[EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control)

[WDF_WMI_PROVIDER_CONFIG_INIT](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdf_wmi_provider_config_init)

[WDF_WMI_PROVIDER_FLAGS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ne-wdfwmi-_wdf_wmi_provider_flags)

[WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate)