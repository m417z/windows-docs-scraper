# lineNegotiateExtVersion function

## Description

The
**lineNegotiateExtVersion** function allows an application to negotiate an extension version to use with the specified line device. This operation need not be called if the application does not support extensions.

## Parameters

### `hLineApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Identifier of the line device to be queried.

### `dwAPIVersion`

TAPI version number that was negotiated for the specified line device using
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion).

### `dwExtLowVersion`

Earliest extension version of the extension identifier returned by
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) with which the application is compliant. The high-order word is the major version number; the low-order word is the minor version number.

### `dwExtHighVersion`

Latest extension version of the extension identifier returned by
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) with which the application is compliant. The high-order word is the major version number; the low-order word is the minor version number.

### `lpdwExtVersion`

Pointer to a variable that contains the extension version number that was negotiated. If negotiation succeeds, this number is in the range between *dwExtLowVersion* and *dwExtHighVersion*.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_BADDEVICEID, LINEERR_NOMEM, LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_NODRIVER, LINEERR_INCOMPATIBLEEXTVERSION, LINEERR_OPERATIONFAILED, LINEERR_INVALAPPHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NODEVICE, LINEERR_OPERATIONUNAVAIL.

## Remarks

Use
[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa) to determine the number of line devices present in the system. The device identifier specified by *dwDeviceID* varies from zero to one less than the number of line devices present.

The
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) function negotiates the API version number to use. It also retrieves the extension identifier supported by the line device, which is zeros if no extensions are provided. Version numbers should be incremented by one for each release. Leaving gaps in release version numbering can cause unexpected results.

If the application wants to use the extensions defined by the returned extension identifier, it must call
**lineNegotiateExtVersion** to negotiate the extension version to use.

The extension version number negotiated is that under which the application and service provider must both operate. If version ranges do not overlap, the application and service provider versions are incompatible and an error is returned.

## See also

[Extended Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/extended-telephony-services-reference)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineInitializeEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineinitializeexa)

[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion)