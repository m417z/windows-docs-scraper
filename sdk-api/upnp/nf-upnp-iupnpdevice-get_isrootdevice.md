# IUPnPDevice::get_IsRootDevice

## Description

The
**IsRootDevice** property specifies whether the device is the topmost device in the device tree.

## Parameters

### `pvarb` [out]

Receives a reference to a **VARIANT_BOOL** that contains the value VARIANT_TRUE if the device is the topmost device in the device tree; otherwise, it contains the value VARIANT_FALSE.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDevice::Children](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_children)

[IUPnPDevice::RootDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_rootdevice)