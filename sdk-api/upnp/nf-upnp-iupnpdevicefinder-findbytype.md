# IUPnPDeviceFinder::FindByType

## Description

The
**FindByType** method searches synchronously for devices by device type or service type.

## Parameters

### `bstrTypeURI` [in]

Specifies the type URI for the device or service type for which to search.

### `dwFlags` [in]

Must be zero. This parameter is reserved for future use.

### `pDevices` [out]

Receives a reference to a collection of
[IUPnPDevices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevices) devices that were found.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

This method does not return until the search is complete. The search can take at least nine seconds, and possibly more. This method must not be called from a thread that processes user interface messages.

## See also

[IUPnPDeviceFinder](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinder)

[IUPnPDeviceFinder::FindByUDN](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-findbyudn)

[IUPnPDevices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevices)