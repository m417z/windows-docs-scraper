# IUPnPDeviceFinderAddCallbackWithInterface::DeviceAddedWithInterface

## Description

The **DeviceAddedWithInterface** method is invoked by the UPnP framework to notify the application that a device has been added to the network.

## Parameters

### `lFindData` [in]

Specifies the search for which the UPnP framework is returning results. The value of *lFindData* is the value returned to the caller by
[IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind).

### `pDevice` [in]

Pointer to a [IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice) object that contains the new device.

### `pguidInterface` [in]

GUID of the network adapter through which the device advertisement came.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

The UPnP framework will query to see if the [IUPnPDeviceFinderAddCallbackWithInterface](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinderaddcallbackwithinterface) interface exists. If you have implemented the interface, the UPnP framework will call the **DeviceAddedWithInterface** method. Otherwise, the UPnP framework will call the [IUPnPDeviceFinderCallback::DeviceAdded](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefindercallback-deviceadded) method.

## See also

[IUPnPDeviceFinder](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinder)

[IUPnPDeviceFinderAddCallbackWithInterface](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinderaddcallbackwithinterface)