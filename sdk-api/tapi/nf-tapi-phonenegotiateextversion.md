# phoneNegotiateExtVersion function

## Description

The
**phoneNegotiateExtVersion** function allows an application to negotiate an extension version to use with the specified phone device. This operation need not be called if the application does not support extensions.

## Parameters

### `hPhoneApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Identifier of the phone device to be queried.

### `dwAPIVersion`

API version number that was negotiated for the specified phone device using
[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion).

### `dwExtLowVersion`

Least recent extension version of the extension identifier returned by
[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion) that the application is compliant with. The high-order word is the major version number; the low-order word is the minor version number.

### `dwExtHighVersion`

Most recent extension version of the extension identifier returned by
[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion) that the application is compliant with. The high-order word is the major version number; the low-order word is the minor version number.

### `lpdwExtVersion`

Pointer to a **DWORD** in which the extension version number that was negotiated is returned. If negotiation succeeds, this number is in the range *dwExtLowVersion* to *dwExtHighVersion*.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALAPPHANDLE, PHONEERR_OPERATIONFAILED, PHONEERR_BADDEVICEID, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NODRIVER, PHONEERR_NOMEM, PHONEERR_INCOMPATIBLEAPIVERSION, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INCOMPATIBLEEXTVERSION, PHONEERR_UNINITIALIZED, PHONEERR_INVALPOINTER, PHONEERR_NODEVICE.

## Remarks

The
**phoneNegotiateExtVersion** function is used to negotiate the API version number to use. It returns the extension identifier supported by the phone device, or zeros if no extensions are provided.

In order for the application to use the extensions defined by the returned extension identifier, it must call
**phoneNegotiateExtVersion** to negotiate the extension version to use.

Use
[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa) to determine the number of phone devices present in the system. The device identifier specified by *dwDeviceID* varies from zero to one less than the number of phone devices present.

The extension version number negotiated is that under which the application and service provider must both operate. If version ranges do not overlap, the application and service-provider versions are incompatible and an error is returned.

## See also

[Extended Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/extended-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa)

[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion)