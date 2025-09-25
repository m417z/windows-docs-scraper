# IUPnPDevice::get_SerialNumber

## Description

The
**SerialNumber** property specifies a human-readable form of the serial number of the device.

## Parameters

### `pbstr` [out]

Receives a reference to a string that contains the serial number. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer used. This property is optional and the device may not have a serial number.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. If the device did not specify a serial number, the return value is S_FALSE. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

This property is optional and *pbstr* may be **NULL**.

It is possible for multiple devices to have the same serial number. To determine if two device objects describe the same device, use the unique device name. For more information, see
[UniqueDeviceName](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_uniquedevicename).

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDevice::UniqueDeviceName](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_uniquedevicename)