# IUPnPDeviceFinderCallback::SearchComplete

## Description

The
**SearchComplete** method is invoked by the UPnP framework to notify the application that the initial search for network devices has been completed.

This method is invoked when the UPnP framework has finished sending [IUPnPDeviceFinderCallback::DeviceAdded](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefindercallback-deviceadded) or [IUPnPDeviceFinderAddCallbackWithInterface::DeviceAddedWithInterface](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinderaddcallbackwithinterface-deviceaddedwithinterface) callbacks for all devices that were present on the network at the time the search was started. These callbacks reflect the state of the network at the time the search was started.

## Parameters

### `lFindData` [in]

Specifies the search for which the UPnP framework is returning results. The value of *lFindData* is the value returned to the caller by
[IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind).

## Return value

The application should return S_OK.

## Remarks

This method simply provides information. It does not indicate that the asynchronous search has ended, but rather that the initial probe has completed. The asynchronous search continues to report devices being added to and removed from the network until the application calls
[IUPnPDeviceFinder::CancelAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-cancelasyncfind).

The initial search can take a long time to complete. The **SearchComplete** callback is invoked when the description document for the last device found (that is, the last device found to be present on the network at the time the search was started) has either been loaded or has failed to load.

## See also

[IUPnPDeviceFinder](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefinder)

[IUPnPDeviceFinder::CreateAsyncFind](https://learn.microsoft.com/windows/desktop/api/upnp/nf-upnp-iupnpdevicefinder-createasyncfind)

[IUPnPDeviceFinderCallback](https://learn.microsoft.com/windows/desktop/api/upnp/nn-upnp-iupnpdevicefindercallback)