# IUPnPDeviceProvider::Start

## Description

The
**Start** method starts the device provider. The device host invokes this method after it loads the device provider This method performs any initialization required by the device provider.

## Parameters

### `bstrInitString` [in]

Identifies the initialization string specific to a device provider. This string is the same as the one passed to
[IUPnPRegistrar::RegisterDeviceProvider](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-registerdeviceprovider) at registration.

## Return value

When implementing this method, return S_OK if the method succeeds. Otherwise, return one of the COM error codes defined in WinError.h.

## See also

[IUPnPDeviceProvider](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpdeviceprovider)

[IUPnPDeviceProvider::Stop](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpdeviceprovider-stop)