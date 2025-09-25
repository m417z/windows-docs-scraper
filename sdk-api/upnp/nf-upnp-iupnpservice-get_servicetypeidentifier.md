# IUPnPService::get_ServiceTypeIdentifier

## Description

The
**ServiceTypeIdentifier** property specifies the service type identifier for the device.

## Parameters

### `pVal` [out]

Receives a reference to a string that contains the service type identifier. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice)