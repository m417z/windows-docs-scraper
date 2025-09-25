# IUPnPService::get_Id

## Description

The
**Id** property specifies the service ID for the service.

## Parameters

### `pbstrId` [out]

Receives a reference to the service ID. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required..

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPService](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservice)