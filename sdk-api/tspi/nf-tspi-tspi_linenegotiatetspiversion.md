# TSPI_lineNegotiateTSPIVersion function

## Description

The
**TSPI_lineNegotiateTSPIVersion** function returns the highest SPI version the service provider can operate under for this device, given the range of possible SPI versions.

## Parameters

### `dwDeviceID`

Identifies the line device for which interface version negotiation is to be performed. In addition to device identifiers within the range the service provider supports, this may be the value:

#### INITIALIZE_NEGOTIATION

This value is used to signify that an overall interface version is to be negotiated.

### `dwLowVersion`

The lowest TSPI version number under which TAPI can operate. The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number.

### `dwHighVersion`

The highest TSPI version number under which TAPI can operate. The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number.

### `lpdwTSPIVersion`

A pointer to a **DWORD**. The service provider fills this location with the highest TSPI version number, within the range requested by the caller, under which the service provider can operate. The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number. If the requested range does not overlap the range supported by the service provider, the function returns LINEERR_INCOMPATIBLEAPIVERSION.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_OPERATIONUNAVAIL, LINEERR_NODRIVER, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

When *dwDeviceID* is
[INITIALIZE_NEGOTIATION](https://learn.microsoft.com/windows/desktop/Tapi/initialize-negotiation), this function must not return LINEERR_OPERATIONUNAVAIL, because this function (with that value) is mandatory for negotiating the overall interface version even if the service provider supports no line devices.

## See also

[INITIALIZE_NEGOTIATION](https://learn.microsoft.com/windows/desktop/Tapi/initialize-negotiation)

[TSPI Versioning](https://learn.microsoft.com/windows/desktop/Tapi/tspi-versioning)

[TSPI_lineGetExtensionID](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetextensionid)

[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion)

[TSPI_providerInit](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_providerinit)