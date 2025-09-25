# IUPnPDeviceControl::Initialize

## Description

The
**Initialize** method is used to initialize the device. The device host invokes this method.

## Parameters

### `bstrXMLDesc` [in]

Specifies the full XML device description, as published by the device host. The device description is based on the template provided by the device.

### `bstrDeviceIdentifier` [in]

Identifies the device to initialize. This is the same identifier returned by
[IUPnPRegistrar::RegisterDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-registerdevice) or
[IUPnPRegistrar::RegisterRunningDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-registerrunningdevice). It is also used to retrieve the UDN of the device using
[IUPnPRegistrar::GetUniqueDeviceName](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-getuniquedevicename).

### `bstrInitString` [in]

Specifies the initialization string used when this device was registered.

## Return value

When implementing this method, return S_OK if the method succeeds. Otherwise, return one of the COM error codes defined in WinError.h.

## Remarks

This method is invoked immediately after the device control object is instantiated. It must be invoked before
[IUPnPDeviceControl::GetServiceObject](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpdevicecontrol-getserviceobject) is invoked.

The difference between a running device and a non-running device is when the
**Initialize** method is invoked.

For running devices,
**Initialize** is invoked when
[IUPnPRegistrar::RegisterRunningDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-registerrunningdevice) is invoked, and the initialization is completed before **IUPnPRegistrar::RegisterRunningDevice** returns.

For non-running devices,
**Initialize** is not necessarily invoked when
[IUPnPRegistrar::RegisterDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-registerdevice) is invoked.
**Initialize** is invoked when the first control or event request arrives.

The *bstrDeviceIdentifier* can also be used to call
[IUPnPRegistrar::GetUniqueDeviceName](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-getuniquedevicename).

## See also

[GetServiceObject](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpdevicecontrol-getserviceobject)

[IUPnPDeviceControl](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpdevicecontrol)