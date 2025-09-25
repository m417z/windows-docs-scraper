# WdfWmiProviderGetDevice function

## Description

[Applies to KMDF only]

The **WdfWmiProviderGetDevice** method returns a handle to the framework device object that is the parent of a specified WMI provider object.

## Parameters

### `WmiProvider` [in]

A handle to a WMI provider object that the driver obtained by calling [WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate) or [WdfWmiInstanceGetProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancegetprovider).

## Return value

**WdfWmiProviderGetDevice** returns a handle to a framework device object.

A bug check occurs if the driver supplies an invalid object handle.

## See also

[WdfWmiInstanceGetProvider](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiinstancegetprovider)

[WdfWmiProviderCreate](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfwmi/nf-wdfwmi-wdfwmiprovidercreate)