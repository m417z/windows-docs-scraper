# IUPnPReregistrar::ReregisterDevice

## Description

The
**ReregisterDevice** method re-registers a device with the device host. The device information is stored by the device host. Then, the device host returns a device identifier and publishes and announces the device on the network.

## Parameters

### `bstrDeviceIdentifier` [in]

Specifies the device identifier of the device. Use the identifier returned by
[IUPnPRegistrar::RegisterDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-registerdevice).

### `bstrXMLDesc` [in]

Specifies the XML device description template of the device to register.

### `bstrProgIDDeviceControlClass` [in]

Specifies the ProgID of a device control object that implements the
[IUPnPDeviceControl](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpdevicecontrol) interface. This interface must be an in-process COM server (CLSCTX_INPROC_SERVER) and must be accessible to [LocalService](https://learn.microsoft.com/windows/desktop/Services/localservice-account).

### `bstrInitString` [in]

Identifies the initialization string specific to the device. This string is later passed to
[IUPnPDeviceControl::Initialize](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpdevicecontrol-initialize).

### `bstrContainerId` [in]

Specifies a string that identifies the process group in which the device belongs. All devices with the same container ID are contained in the same process.

### `bstrResourcePath` [in]

Specifies the location of the resource directory of the device. This resource directory contains the icon files and service descriptions that are specified in the device description template *bstrXMLDesc*. The resource directory may also contain the presentation files. However, this is optional.

### `nLifeTime` [in]

Specifies the lifetime of the device announcement, in seconds. After the timeout expires, the announcements are refreshed. If you specify zero, the default value of 1800 (30 minutes) is used. The minimum allowable value is 900 (15 minutes); if you specify anything less than 900, an error is returned.

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h, or one of the following UPnP-specific error codes.

| Return code | Description |
| --- | --- |
| **UPNP_E_DEVICE_NOTREGISTERED** | The device has not been registered. Use [RegisterRunningDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-registerrunningdevice) to register an unregistered device. |
| **UPNP_E_DEVICE_RUNNING** | The device is currently running. Use [ReregisterRunningDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpreregistrar-reregisterrunningdevice) to reregister a device while it is running. |
| **UPNP_E_DUPLICATE_NOT_ALLOWED** | A duplicate element exists. |
| **UPNP_E_DUPLICATE_SERVICE_ID** | A duplicate service ID for a service within the same parent device exists. |
| **UPNP_E_INVALID_DESCRIPTION** | The device description is not valid. |
| **UPNP_E_INVALID_ICON** | An error is present in the icon element of the device description. |
| **UPNP_E_INVALID_SERVICE** | An error is present in a service element in the device description. |
| **UPNP_E_REQUIRED_ELEMENT_ERROR** | A required element is missing. |

## Remarks

Use the identifier returned in *pbstrDeviceIdentifier* when invoking
[IUPnPRegistrar::UnregisterDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-unregisterdevice).

Common errors that can occur when invoking this function include:

* The necessary COM object was not found.
* There is no access to the COM object for [LocalService](https://learn.microsoft.com/windows/desktop/Services/localservice-account).
* Subordinate COM interfaces.
* The XML description limits (see
  [Creating a Device Description](https://learn.microsoft.com/windows/desktop/UPnP/creating-a-device-description)).

## See also

[IUPnPRegistrar](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpregistrar)

[IUPnPReregistrar](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpreregistrar)