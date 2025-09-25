# _WDF_WMI_PROVIDER_FLAGS enumeration

## Description

[Applies to KMDF only]

The **WDF_WMI_PROVIDER_FLAGS** enumeration defines configuration flags for a driver's WMI data provider.

## Constants

### `WdfWmiProviderEventOnly:0x0001`

WMI clients can receive notification of WMI events, but they cannot query or set instance data. The driver can call [WdfWmiInstanceFireEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancefireevent), but it does not provide any instance-specific callback functions.

### `WdfWmiProviderExpensive:0x0002`

Collecting the provider's data can potentially affect the driver's performance, so the driver will not collect data unless a WMI client has registered to use it. The framework calls the driver's [EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control) callback function, passing the **WdfWmiInstanceControl** value (from the [WDF_WMI_PROVIDER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ne-wdfwmi-_wdf_wmi_provider_control) enumeration), to inform the driver to begin collecting data. If the driver does not provide an *EvtWmiProviderFunctionControl* callback function, it can call [WdfWmiProviderIsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiproviderisenabled).

### `WdfWmiProviderTracing:0x0004`

The WMI data provider supports WMI event tracing. The driver can obtain the tracing handle by calling [WdfWmiProviderGetTracingHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidergettracinghandle). If this flag is set, no other flags can be set.

### `WdfWmiProviderValidFlags:WdfWmiProviderEventOnly` | WdfWmiProviderExpensive | WdfWmiProviderTracing

The bitwise OR of all flags. Drivers should not use this value.

## Remarks

The **WDF_WMI_PROVIDER_FLAGS** enumeration is used in the [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure.

## See also

[EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control)

[WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config)

[WdfWmiInstanceControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ne-wdfwmi-_wdf_wmi_provider_control)

[WdfWmiInstanceFireEvent](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancefireevent)

[WdfWmiProviderGetTracingHandle](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidergettracinghandle)

[WdfWmiProviderIsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiproviderisenabled)