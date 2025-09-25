# IUPnPDevice::get_RootDevice

## Description

The
**RootDevice** property specifies the topmost device in the device tree. The root device represents a physical object.

## Parameters

### `ppudRootDevice` [out]

Receives a reference to an
[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice) object that describes the root device. This reference must be released when it is no longer required.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDevice::IsRootDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_isrootdevice)