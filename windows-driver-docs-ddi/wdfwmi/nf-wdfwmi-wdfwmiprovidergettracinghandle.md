# WdfWmiProviderGetTracingHandle function

## Description

[Applies to KMDF only]

The **WdfWmiProviderGetTracingHandle** method returns a handle to the event logger of a [WPP software tracing](https://learn.microsoft.com/windows-hardware/drivers/devtest/wpp-software-tracing) session.

## Parameters

### `WmiProvider` [in]

A handle to a WMI provider object that the driver obtained by calling [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate) or [WdfWmiInstanceGetProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancegetprovider).

## Return value

**WdfWmiProviderGetTracingHandle** returns a handle to the event tracing logger.

A bug check occurs if the driver supplies an invalid object handle.

## Remarks

If a driver sets the **WdfWmiProviderTracing** flag in the **Flags** member of the WMI provider object's [WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config) structure, it can call **WdfWmiProviderGetTracingHandle** to obtain a tracing handle after a provider instance has been registered. The driver can use the tracing handle as input to the [WmiTraceMessage](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdm/nf-wdm-wmitracemessage) routine.

For more information about the **WdfWmiProviderGetTracingHandle** method, see [Supporting WMI Event Tracing](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-data-blocks-and-events-in-your-driver). For more information about WMI, see [Supporting WMI in Framework-Based Drivers](https://learn.microsoft.com/windows-hardware/drivers/wdf/supporting-wmi-in-kmdf-drivers).

#### Examples

The following code example obtains a handle to a WPP tracing session's event logger.

```cpp
ULONGLONG tracingHandle;

tracingHandle = WdfWmiProviderGetTracingHandle(wmiProvider);
```

## See also

[WDF_WMI_PROVIDER_CONFIG](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/ns-wdfwmi-_wdf_wmi_provider_config)

[WdfWmiInstanceGetProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancegetprovider)

[WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate)