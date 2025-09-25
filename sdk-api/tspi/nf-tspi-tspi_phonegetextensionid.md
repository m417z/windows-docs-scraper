# TSPI_phoneGetExtensionID function

## Description

The
**TSPI_phoneGetExtensionID** function retrieves the extension identifier that the service provider supports for the indicated phone device.

## Parameters

### `dwDeviceID`

The phone device to be queried.

### `dwTSPIVersion`

Specifies an interface version number that is negotiated for this device using
[TSPI_phoneNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiatetspiversion). This function operates according to the interface specification at this version level.

### `lpExtensionID`

A pointer to a structure of type
[PHONEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneextensionid). If the service provider supports provider-specific extensions, it fills this structure with the extension identifier of these extensions. If the service provider does not support extensions, it fills this structure with all zeros. An extension identifier of all zeros is not a legal extension identifier, since the all-zeros value is used to indicate that the service provider does not support extensions.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INCOMPATIBLEAPIVERSION, PHONEERR_RESOURCEUNAVAIL, PHONEERR_NODRIVER, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL.

## Remarks

This function is typically called by TAPI in response to an application calling the
[phoneNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-phonenegotiateapiversion) function. The result returned by the service provider should be appropriate for use in a subsequent call to
[TSPI_phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiateextversion).

## See also

[PHONEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-phoneextensionid)

[TSPI_phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiateextversion)

[TSPI_phoneNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiatetspiversion)