# IUPnPDeviceFinderCallback::DeviceAdded

## Description

The
**DeviceAdded** method is invoked by the UPnP framework to notify the application that a device has been added to the network.

## Parameters

### `lFindData` [in]

Specifies the search for which the UPnP framework is returning results. The value of *lFindData* is the value returned to the caller by
[IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind).

### `pDevice` [in]

Reference to a
[IUPnPDevice](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevice) object that contains the new device.

## Return value

The UPnP framework does not expect the application to return any specific value; any value returned is ignored by the UPnP framework.

## Remarks

The UPnP framework might call the [IUPnPDeviceFinderAddCallbackWithInterface::DeviceAddedWithInterface](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinderaddcallbackwithinterface-deviceaddedwithinterface) method instead of **DeviceAdded** to notify the application when a device is added to the network. The UPnP framework will query to see if the [IUPnPDeviceFinderAddCallbackWithInterface](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinderaddcallbackwithinterface) interface exists. If so, the UPnP framework will call **DeviceAddedWithInterface**. Otherwise, the UPnP framework will call **DeviceAdded**.

The UPnP framework might return two or more callbacks for the same device. This can happen if a device's IP address was changed without first removing the device, and then re-adding it to the network. If this occurs, an application should discard the old device and use the most recently returned one. An application checks for duplicate devices by comparing the UDNs.

## See also

[IUPnPDeviceFinder](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinder)

[IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind)

[IUPnPDeviceFinderCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefindercallback)