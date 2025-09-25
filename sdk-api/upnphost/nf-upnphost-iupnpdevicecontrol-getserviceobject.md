# IUPnPDeviceControl::GetServiceObject

## Description

The
**GetServiceObject** method is used to obtain the **IDispatch** pointer to a specific service object. The device host invokes this method once per service, the first time it receives a request for a service.

## Parameters

### `bstrUDN` [in]

Specifies the UDN of the device.

### `bstrServiceId` [in]

Specifies the Service ID of the service for which to obtain the pointer.

### `ppdispService` [out]

Receives the **IDispatch** pointer to the service object.

## Return value

When implementing this method, return S_OK if the method succeeds. Otherwise, return one of the COM error codes defined in WinError.h.

## Remarks

This method is invoked by the device host when a control request or event subscription is received for a particular service.

Embedded devices are differentiated by their UDNs.

## See also

[IUPnPDeviceControl](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpdevicecontrol)

[Initialize](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpdevicecontrol-initialize)