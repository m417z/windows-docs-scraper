# TSPI_lineGetExtensionID function

## Description

The
**TSPI_lineGetExtensionID** function returns the extension identifier that the service provider supports for the indicated line device.

## Parameters

### `dwDeviceID`

The line device to be queried.

### `dwTSPIVersion`

An interface version number that was already negotiated for this device using
[TSPI_lineNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiatetspiversion). This function operates according to the interface specification at this version level.

### `lpExtensionID`

A pointer to a structure of type
[LINEEXTENSIONID](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineextensionid). If the service provider supports provider-specific extensions, it fills this structure with the extension identifier of these extensions. If the service provider does not support extensions, it fills this structure with all zeros. (Therefore, a valid extension identifier cannot consist of all zeros.)

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL.

## Remarks

This function is typically called by TAPI in response to an application calling the
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) function. The result returned by the service provider should be appropriate for use in a subsequent call to
[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion). An extension identifier of all zeros is not a legal extension identifier, because the all-zeros value is used to indicate that the service provider does not support extensions.

## See also

[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion)

[TSPI_lineNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiatetspiversion)