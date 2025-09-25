# IUPnPDevice::get_ParentDevice

## Description

The
**ParentDevice** property specifies the parent of the device.

## Parameters

### `ppudDeviceParent` [out]

Receives a reference to an
[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice) object that describes the parent device. This reference must be released when it is no longer required. If the device has no parent, it is a topmost device, and the parameter receives **NULL**.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. If the device is a topmost device, the return value is S_FALSE. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

To determine if the device has no parent, use [IUPnPDevice::IsRootDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_isrootdevice).

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDevice::Children](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_children)