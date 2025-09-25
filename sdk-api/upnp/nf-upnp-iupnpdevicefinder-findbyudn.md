# IUPnPDeviceFinder::FindByUDN

## Description

The
**FindByUDN** method searches synchronously for a device by its unique device name (UDN).

## Parameters

### `bstrUDN` [in]

Specifies the UDN for which to search. This value is case sensitive, and should be provided as lower-case (e.g. uuid:e8f85dfd-ff...).

### `pDevice` [out]

Receives a reference to an
[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice) object that contains the requested device. Receives **NULL** if the specified device is not found.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns S_FALSE.

## Remarks

This method returns as soon as a device that matches the specified UDN is found. If no device is found, the method takes at least nine seconds to return, and possibly longer.

## See also

[IUPnPDeviceFinder](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinder)

[IUPnPDeviceFinder::FindByType](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-findbytype)

[IUPnPDevices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevices)