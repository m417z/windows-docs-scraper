# IUPnPDevice::get_FriendlyName

## Description

The
**FriendlyName** property specifies the device display name for the device.

## Parameters

### `pbstr` [out]

Receives a reference to a string that contains the device display name. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

It is possible for multiple devices to have the same display name. To determine if two device objects describe the same device, use the unique device name. For more information, see
[UniqueDeviceName](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_uniquedevicename).

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[UniqueDeviceName](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_uniquedevicename)