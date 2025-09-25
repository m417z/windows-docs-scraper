# lineNegotiateAPIVersion function

## Description

The
**lineNegotiateAPIVersion** function allows an application to negotiate an API version to use.

## Parameters

### `hLineApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Identifier of the line device to be queried.

### `dwAPILowVersion`

Earliest TAPI version with which the application is compliant. The high-order word is the major version number; the low-order word is the minor version number.

### `dwAPIHighVersion`

Latest TAPI version with which the application is compliant. The high-order word is the major version number; the low-order word is the minor version number.

### `lpdwAPIVersion`

Pointer to a variable that contains the TAPI version number that was negotiated. If negotiation succeeds, this number is in the range between *dwAPILowVersion* and *dwAPIHighVersion*.

### `lpExtensionID`

Pointer to a structure of type
[LINEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineextensionid). If the service provider for the specified *dwDeviceID* supports provider-specific extensions, then, upon a successful negotiation, this structure is filled with the extension identifier of these extensions. This structure contains all zeros if the line provides no extensions. An application can ignore the returned parameter if it does not use extensions.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_NODRIVER, LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_OPERATIONFAILED, LINEERR_INVALAPPHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NOMEM, LINEERR_OPERATIONUNAVAIL, LINEERR_NODEVICE.

## Remarks

Use
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa) to determine the number of line devices present in the system. The device identifier specified by *dwDeviceID* varies from zero to one less than the number of line devices present.

The
**lineNegotiateAPIVersion** function is used to negotiate the API version number to use. It also retrieves the extension identifier supported by the line device, and returns zeros if no extensions are supported. If the application wants to use the extensions defined by the returned extension identifier, it must call
[lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateextversion) to negotiate the extension version to use.

The API version number negotiated is that under which TAPI can operate. If version ranges do not overlap, the application and API or service provider versions are incompatible and an error is returned.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineextensionid)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[TAPI Versioning](https://learn.microsoft.com/windows/desktop/Tapi/tapi-versioning)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)

[lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateextversion)