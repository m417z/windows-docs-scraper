# IUPnPDevice::get_HasChildren

## Description

The
**HasChildren** property specifies whether the device has any child devices.

## Parameters

### `pvarb` [out]

Receives a reference to a **VARIANT_BOOL** that contains the value VARIANT_TRUE if the device has one or more child devices; otherwise, it contains the value VARIANT_FALSE.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

Use this property to determine whether or not the application should access the [IUPnPDevice::Children](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_children) property.

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDevice::Children](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_children)