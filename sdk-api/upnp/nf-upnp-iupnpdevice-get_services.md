# IUPnPDevice::get_Services

## Description

The
**Services** property specifies the list of services provided by the device.

## Parameters

### `ppusServices` [out]

Receives a reference to an
[IUPnPServices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservices) collection that enumerates the services provided by the device. This reference must be released when it is no longer required.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPServices](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpservices)