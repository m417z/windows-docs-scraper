# IUPnPDevices::get_Item

## Description

The
**Item** property specifies the [IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice) interface for a device, identified by the UDN, in the collection.

## Parameters

### `bstrUDN` [in]

Specifies a device in the collection.

### `ppDevice` [out]

Receives a reference to an
[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice) interface for the specified device.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPDevices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevices)