# IUPnPDevice::get_Children

## Description

The
**Children** property specifies all the child devices of the device. The devices are stored in an
[IUPnPDevices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevices) collection.

## Parameters

### `ppudChildren` [out]

Receives a reference to an
[IUPnPDevices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevices) collection that enumerates the child devices of the device. This reference must be released when it is no longer required.

If the device has no child devices, the collection object has a length of zero.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

To determine if a device has any children (but not the actual number of children), use [IUPnPDevice::HasChildren](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_haschildren).

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDevice::HasChildren](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_haschildren)

[IUPnPDevices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevices)