# IUPnPRegistrar::UnregisterDeviceProvider

## Description

The
**UnregisterDeviceProvider** method permanently unregisters and unloads the device provider from the device host. The
[IUPnPDeviceProvider::Stop](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpdeviceprovider-stop) method is invoked.

## Parameters

### `bstrProviderName` [in]

Specifies the provider name. Use the same name that was used in the call to
[RegisterDeviceProvider](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-registerdeviceprovider).

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## See also

[IUPnPRegistrar](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpregistrar)