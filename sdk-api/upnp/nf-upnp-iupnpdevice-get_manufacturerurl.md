# IUPnPDevice::get_ManufacturerURL

## Description

The
**ManufacturerURL** property specifies the URL for the manufacturer's Web site.

## Parameters

### `pbstr` [out]

Receives a reference to a string that contains the URL. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required. If the device does not specify this URL, this parameter is set to **NULL**.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. If the device does not specify this URL, the return value is S_FALSE and *pbstr* is **NULL**. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

This property is optional and *pbstr* can return **NULL**.

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDevice::ManufacturerName](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_manufacturername)