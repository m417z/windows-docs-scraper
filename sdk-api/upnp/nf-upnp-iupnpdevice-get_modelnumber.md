# IUPnPDevice::get_ModelNumber

## Description

The
**ModelNumber** property specifies a human-readable form of the model number of the device.

## Parameters

### `pbstr` [out]

Receives a reference to a string that contains the model number. Release this string with [SysFreeString](https://learn.microsoft.com/previous-versions/windows/desktop/api/oleauto/nf-oleauto-sysfreestring) when it is no longer required. If the device does not specify a model number, this parameter is set to **NULL**.

## Return value

For C++: If this property's "get" method succeeds, the return value is S_OK. If the device does not specify a model number, the return value is S_FALSE and *pbstr* is **NULL**. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

This property is optional and *pbstr* can return **NULL**.

## See also

[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice)

[IUPnPDevice::ModelName](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_modelname)

[IUPnPDevice::ModelURL](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevice-get_modelurl)