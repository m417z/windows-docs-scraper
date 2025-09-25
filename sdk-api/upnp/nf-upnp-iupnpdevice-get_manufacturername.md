# IUPnPDevice::get_ManufacturerName

## Description

The
**ManufacturerName** property specifies a human-readable form of the manufacturer name of the device.

## Parameters

### `pbstr` [out]

Receives a reference to a string that contains the manufacturer's name. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDevice::ManufacturerURL](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_manufacturerurl)