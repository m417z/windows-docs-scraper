# _WDF_WMI_PROVIDER_CONTROL enumeration

## Description

[Applies to KMDF only]

The **WDF_WMI_PROVIDER_CONTROL** enumeration defines the type of control functions that a WMI data provider can support.

## Constants

### `WdfWmiControlInvalid:0`

For internal use only.

### `WdfWmiEventControl`

The driver must enable or disable delivering events for a provider instance.

### `WdfWmiInstanceControl`

The driver must enable or disable collecting data for a provider instance.

## Remarks

The **WDF_WMI_PROVIDER_CONTROL** enumeration is used as an input parameter to the [WdfWmiProviderIsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiproviderisenabled) method and the driver's [EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control) callback function.

## See also

[EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control)

[WdfWmiProviderIsEnabled](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiproviderisenabled)