# WdfWmiProviderIsEnabled function

## Description

[Applies to KMDF only]

The **WdfWmiProviderIsEnabled** method determines if either data collection or event notification is enabled for a specified WMI data provider.

## Parameters

### `WmiProvider` [in]

A handle to a WMI provider object that the driver obtained by calling [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate) or [WdfWmiInstanceGetProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancegetprovider).

### `ProviderControl` [in]

A [WDF_WMI_PROVIDER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ne-wdfwmi-_wdf_wmi_provider_control)-typed value that specifies one of the types of control functions (data collection or event notification) that a WMI data provider can support.

## Return value

**WdfWmiProviderIsEnabled** returns **TRUE** if the capability that the *ProviderControl* parameter specifies is enabled and **FALSE** otherwise.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

A driver that does not provide an [EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control) callback function can call **WdfWmiProviderIsEnabled** to determine if data collection or event notification is enabled.

#### Examples

The following code example determines if event notification is enabled for a specified WMI data provider.

```cpp
BOOLEAN eventNotifEnabled;

eventNotifEnabled = WdfWmiProviderIsEnabled(
                                            wmiProvider,
                                            WdfWmiEventControl
                                            );
```

## See also

[EvtWmiProviderFunctionControl](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nc-wdfwmi-evt_wdf_wmi_provider_function_control)

[WDF_WMI_PROVIDER_CONTROL](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ne-wdfwmi-_wdf_wmi_provider_control)

[WdfWmiInstanceGetProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancegetprovider)

[WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate)