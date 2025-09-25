# phoneNegotiateAPIVersion function

## Description

The
**phoneNegotiateAPIVersion** allows an application to negotiate an API version to use for the specified phone device.

## Parameters

### `hPhoneApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Identifier of the phone device to be queried.

### `dwAPILowVersion`

Least recent API version the application is compliant with. The high-order word is the major version number, the low-order word is the minor version number.

### `dwAPIHighVersion`

Most recent API version the application is compliant with. The high-order word is the major version number, the low-order word is the minor version number.

### `lpdwAPIVersion`

Pointer to a **DWORD** in which the API version number that was negotiated will be returned. If negotiation succeeds, this number is in the range *dwAPILowVersion* to *dwAPIHighVersion*.

### `lpExtensionID`

Pointer to a structure of type
[PHONEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneextensionid). If the service provider for the specified *dwDeviceID* parameter supports provider-specific extensions, this structure is filled with the extension identifier of these extensions when negotiation succeeds. This structure contains all zeros if the line provides no extensions. An application can ignore the returned parameter if it does not use extensions.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

PHONEERR_INVALAPPHANDLE, PHONEERR_OPERATIONFAILED, PHONEERR_BADDEVICEID, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NODRIVER, PHONEERR_NOMEM, PHONEERR_INVALPOINTER, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INCOMPATIBLEAPIVERSION, PHONEERR_UNINITIALIZED, PHONEERR_NODEVICE.

## Remarks

The
**phoneNegotiateAPIVersion** function is used to negotiate the API version number to use with the specified phone device. It returns the extension identifier supported by the phone device, or zeros if no extensions are provided.

If the application wants to use the extensions defined by the returned extension identifier, it must call
[phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateextversion) to negotiate the extension version to use.

Use
[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa) to determine the number of phone devices present in the system. The device identifier specified by *dwDeviceID* varies from zero to one less than the number of phone devices present.

The API version number negotiated is that under which TAPI can operate. If version ranges do not overlap, the application, API, or service-provider versions are incompatible and an error is returned.

## See also

[PHONEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneextensionid)

[Supplementary Phone Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-phone-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[TAPI Versioning](https://learn.microsoft.com/windows/desktop/Tapi/tapi-versioning)

[phoneInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phoneinitializeexa)

[phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateextversion)