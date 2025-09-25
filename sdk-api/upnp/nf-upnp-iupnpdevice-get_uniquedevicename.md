# IUPnPDevice::get_UniqueDeviceName

## Description

The
**UniqueDeviceName** property specifies the unique device name (UDN) of the device. A UDN is unique; no two devices can have the same UDN.

## Parameters

### `pbstr` [out]

Receives a reference to a string that contains the UDN of the device. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)