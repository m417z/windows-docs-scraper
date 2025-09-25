# IUPnPRegistrar::RegisterRunningDevice

## Description

The
**RegisterRunningDevice** method registers a running device with the device host. The device information is stored by the device host. Then, the device host returns a device identifier and publishes and announces the device on the network. The publication of this device does not persist across system boots.

## Parameters

### `bstrXMLDesc` [in]

Specifies the XML device description template of the device to register.

### `punkDeviceControl` [in]

Specifies the **IUnknown** pointer to the device's device control object.

### `bstrInitString` [in]

Identifies the initialization string specific to the device. This string is later passed to
[IUPnPDeviceControl::Initialize](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpdevicecontrol-initialize).

### `bstrResourcePath` [in]

Specifies the location of the resource directory of the device. This resource directory contains the icon files and service descriptions that are specified in the device description template *bstrXMLDesc*.

### `nLifeTime` [in]

Specifies the lifetime of the device announcement, in seconds. After the timeout expires, the announcements are refreshed. If you specify zero, the default value of 1800 (30 minutes) is used. The minimum allowable value is 900 (15 minutes); if you specify anything less than 900, an error is returned.

### `pbstrDeviceIdentifier` [out]

Receives the device identifier. Use this identifier when unregistering or re-registering the device. Save this Device ID; you must use it when calling
[UnregisterDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-unregisterdevice).

## Return value

If the method succeeds, the return value is S_OK. Otherwise, the method returns one of the COM error codes defined in WinError.h, or one of the following UPnP-specific error codes.

**Note** If bstrResourcePath is too long, this method returns the value 0x80070002.

| Return code | Description |
| --- | --- |
| **UPNP_E_DUPLICATE_NOT_ALLOWED** | A duplicate element exists. |
| **UPNP_E_DUPLICATE_SERVICE_ID** | A duplicate service ID for a service within the same parent device exists. |
| **UPNP_E_INVALID_DESCRIPTION** | The device description is not valid. |
| **UPNP_E_INVALID_ICON** | An error is present in the icon element of the device description. |
| **UPNP_E_INVALID_SERVICE** | An error is present in a service element in the device description. |
| **UPNP_E_REQUIRED_ELEMENT_ERROR** | A required element is missing. |

## Remarks

The client that invokes this method must be able to impersonate [LocalService](https://learn.microsoft.com/windows/desktop/Services/localservice-account) in order to complete the processing of this method.

The
[IUPnPDeviceControl::Initialize](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpdevicecontrol-initialize) method is invoked when the first control or event request is received.

Use the identifier returned in *pbstrDeviceIdentifier* when invoking
[UnregisterDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-unregisterdevice) or
[IUPnPReregistrar::ReregisterRunningDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpreregistrar-reregisterrunningdevice).

The registration of this device does not persist across system boots.

Common errors that can occur when invoking this function include:

* The necessary COM object was not found.
* There is no access to the COM object for [LocalService](https://learn.microsoft.com/windows/desktop/Services/localservice-account).
* Subordinate COM interfaces.
* The XML description limits (see
  [Creating a Device Description](https://learn.microsoft.com/windows/desktop/UPnP/creating-a-device-description)).
* Evented variables did not return success codes and the device was shut down.
* The service description was invalid. Use validatesd.exe to ensure that service descriptions are valid.
* The service did not implement IUPnPEventSource and did not return a success code to
  [IUPnPEventSource::Advise](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpeventsource-advise) and the device was shut down.

## See also

[IUPnPRegistrar](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpregistrar)

[IUPnPRegistrar::UnregisterDevice](https://learn.microsoft.com/windows/desktop/api/upnphost/nf-upnphost-iupnpregistrar-unregisterdevice)

[IUPnPReregistrar](https://learn.microsoft.com/windows/desktop/api/upnphost/nn-upnphost-iupnpreregistrar)