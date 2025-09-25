# EVT_WDF_WMI_PROVIDER_FUNCTION_CONTROL callback function

## Description

[Applies to KMDF only]

A driver's *EvtWmiProviderFunctionControl* callback function enables and disables the driver's support for collecting data and sending events for a specified WMI data provider.

## Parameters

### `WmiProvider` [in]

A handle to a WMI provider object.

### `Control` [in]

A [WDF_WMI_PROVIDER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ne-wdfwmi-_wdf_wmi_provider_control)-typed value that identifies a capability that the driver must enable or disable.

### `Enable` [in]

A Boolean value that, if **TRUE**, indicates that the driver must enable the capability that *Control* specifies. If **FALSE**, the driver must disable the capability.

## Return value

The *EvtWmiProviderFunctionControl* callback function must return STATUS_SUCCESS if the operation succeeds. Otherwise, it must return a status value for which [NT_SUCCESS](https://learn.microsoft.com/windows-hardware/drivers/kernel/using-ntstatus-values)(*status*) equals **FALSE**.

## Remarks

To register an *EvtWmiProviderFunctionControl* callback function, your driver must place the function's address in a [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure before it calls [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate).

If your driver sets the **WdfWmiProviderExpensive** flag in the **Flags** member of a WMI data provider's [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure, and if the driver provides an *EvtWmiProviderFunctionControl* callback function, the framework calls the callback function when the driver should enable or disable its ability to collect WMI data.

Instead of providing an *EvtWmiProviderFunctionControl* callback function, the driver can call [WdfWmiProviderIsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiproviderisenabled) to find out if it should enable or disable collecting data.

For more information about the *EvtWmiProviderFunctionControl* callback function, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

## See also

[EvtWmiInstanceExecuteMethod](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_execute_method)

[EvtWmiInstanceQueryInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_query_instance)

[EvtWmiInstanceSetInstance](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_instance)

[EvtWmiInstanceSetItem](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_instance_set_item)

[WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config)

[WDF_WMI_PROVIDER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ne-wdfwmi-_wdf_wmi_provider_control)

[WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate)

[WdfWmiProviderIsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiproviderisenabled)