# IUPnPDevice::get_UPC

## Description

The
**UPC** property specifies a human-readable form of the product code.

## Parameters

### `pbstr` [out]

Receives a reference to a string that contains the product code. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required. If the device does not specify a product code, this parameter receives an empty string.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. If the device did not specify a product code, the return value is S_FALSE. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

This property is optional and *pbstr* may be **NULL**.

It is possible for multiple devices to have the same product code. To determine if two device objects describe the same device, use the unique device name. For more information, see
[UniqueDeviceName](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_uniquedevicename).

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDevice::UniqueDeviceName](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_uniquedevicename)