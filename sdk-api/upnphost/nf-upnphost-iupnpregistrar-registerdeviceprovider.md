# IUPnPRegistrar::RegisterDeviceProvider

## Description

The
**RegisterDeviceProvider** method registers a device provider with the device host. The device provider is not published on the network. Instead, it creates devices dynamically and registers them using
[RegisterRunningDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-registerrunningdevice).

## Parameters

### `bstrProviderName` [in]

Specifies the name of the device provider.

### `bstrProgIDProviderClass` [in]

Specifies the ProgID of object that implements the
[IUPnPDeviceProvider](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpdeviceprovider) interface. This object must already be registered with COM. This object must be an in-process COM server (CLSCTX_INPROC_SERVER) and must be accessible to [LocalService](https://learn.microsoft.com/windows/desktop/Services/localservice-account).

### `bstrInitString` [in]

Identifies an initialization string specific to a device provider.

### `bstrContainerId` [in]

Specifies a string that identifies the process group in which the device provider belongs. All devices and device providers with the same container ID are contained in the same process.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h.

## Remarks

Common errors that can occur when invoking this function include:

* The necessary COM object was not found.
* There is no access to the COM object for [LocalService](https://learn.microsoft.com/windows/desktop/Services/localservice-account).
* Subordinate COM interfaces.

## See also

[IUPnPRegistrar](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpregistrar)

[IUPnPRegistrar::UnregisterDeviceProvider](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-unregisterdeviceprovider)