# IUPnPDevice::get_PresentationURL

## Description

The
**PresentationURL** property specifies the presentation URL for a Web page that controls the device.

## Parameters

### `pbstr` [out]

Receives a reference to a string that contains the presentation URL for the Web page. This URL is an absolute URL. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer used. If the device does not specify a presentation URL, this parameter receives an empty string.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. If the device did not specify a presentation URL, the return value is S_FALSE. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

**Note** This property must not be empty and must contain a valid URL.

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)