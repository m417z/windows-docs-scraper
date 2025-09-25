# TSPI_phoneNegotiateTSPIVersion function

## Description

The
**TSPI_phoneNegotiateTSPIVersion** function returns the highest SPI version the service provider can operate under for this device, given the range of possible SPI versions.

## Parameters

### `dwDeviceID`

The phone device for which interface version negotiation is to be performed. Permitted values are strictly within the range of phone devices identifiers for this service provider; the value
[INITIALIZE_NEGOTIATION](https://learn.microsoft.com/windows/desktop/Tapi/initialize-negotiation) is never passed to this function.

### `dwLowVersion`

The lowest TSPI version number under which TAPI can operate. The most significant **WORD** is the major version number and the least significant **WORD** is the minor version number.

### `dwHighVersion`

The highest TSPI version number under which TAPI can operate. The most significant **WORD** is the major version number and the least significant **WORD** is the minor version number.

### `lpdwTSPIVersion`

A pointer to a **DWORD**. Upon a successful return from this function the service provider fills this location with the highest TSPI version number, within the range requested by the caller, under which the service provider can operate. The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number. If the requested range does not overlap the range supported by the service provider, the function returns PHONEERR_INCOMPATIBLEAPIVERSION.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INCOMPATIBLEAPIVERSION, PHONEERR_RESOURCEUNAVAIL, PHONEERR_NODRIVER, PHONEERR_OPERATIONFAILED, PHONEERR_NOMEM, PHONEERR_OPERATIONUNAVAIL.

## Remarks

The service provider returns PHONEERR_OPERATIONUNAVAIL if the operation is not available. However, if the service provider supports any phone devices, it must also support this function and the function must not return PHONEERR_OPERATIONUNAVAIL.

TAPI calls this function early in the initialization sequence for each phone device.

Negotiation of an extension version is done through the separate procedure
[TSPI_phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiateextversion).

The corresponding function at the TAPI level is an overloaded function that also retrieves the extension identifier, if any, supported by the service provider. At the TSPI level, retrieving the extension identifier is accomplished through a separate procedure, namely,
[TSPI_phoneGetExtensionID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetextensionid).

## See also

[INITIALIZE_NEGOTIATION](https://learn.microsoft.com/windows/desktop/Tapi/initialize-negotiation)

[TSPI_phoneGetExtensionID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonegetextensionid)

[TSPI_phoneNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiateextversion)