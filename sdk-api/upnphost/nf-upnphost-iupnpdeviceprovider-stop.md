# IUPnPDeviceProvider::Stop

## Description

The
**Stop** method stops the device provider. This method is invoked by the device host before it unloads the device provider. This method is invoked when a service stops or the computer is shut down, and performs any cleanup processing required by the device provider.

## Return value

When implementing this method, return S_OK if the method succeeds. Otherwise, return one of the COM error codes defined in WinError.h.

## See also

[IUPnPDeviceProvider](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpdeviceprovider)

[IUPnPDeviceProvider::Start](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpdeviceprovider-start)