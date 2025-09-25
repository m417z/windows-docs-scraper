# IUPnPDeviceFinderCallback::DeviceRemoved

## Description

The
**DeviceRemoved** method is invoked by the UPnP framework to notify the application that a device has been removed from the network.

## Parameters

### `lFindData` [in]

Specifies the search for which the UPnP framework is returning results. The value of *lFindData* is the value returned to the caller by
[IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind).

### `bstrUDN` [in]

Specifies the UDN of the device that was removed from the network.

## Return value

The application should return S_OK.

## Remarks

The UPnP framework might return two or more callbacks for the same device. An application can ignore subsequent device-removal callbacks.

## See also

[IUPnPDeviceFinder](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinder)

[IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind)

[IUPnPDeviceFinderCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefindercallback)