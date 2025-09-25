# TSPI_lineNegotiateExtVersion function

## Description

The
**TSPI_lineNegotiateExtVersion** function returns the highest extension version number the service provider can operate under for this device, given the range of possible extension versions.

## Parameters

### `dwDeviceID`

Identifies the line device for which interface version negotiation is to be performed. The value
[INITIALIZE_NEGOTIATION](https://learn.microsoft.com/windows/desktop/Tapi/initialize-negotiation) may not be used for this function.

### `dwTSPIVersion`

An interface version number that has already been negotiated for this device using
[TSPI_lineNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiatetspiversion). This function operates according to the interface specification at this version level.

### `dwLowVersion`

The lowest extension version number under which TAPI or its client application can operate. The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number. TAPI does not validate this parameter when this function is called.

### `dwHighVersion`

The highest extension version number under which TAPI or its client application can operate. The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number. TAPI does not validate this parameter when this function is called.

### `lpdwExtVersion`

A pointer to a **DWORD**. Upon a successful return from this function, the service provider fills this location with the highest extension version number, within the range requested by the caller, under which the service provider can operate. The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number. If the requested range does not overlap the range supported by the service provider, the function returns LINEERR_INCOMPATIBLEEXTVERSION.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_OPERATIONUNAVAIL, LINEERR_INCOMPATIBLEEXTVERSION, LINEERR_OPERATIONFAILED, LINEERR_NODRIVER, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM.

## Remarks

This function can be called before or after the device is opened by TAPI. If the device is currently open and has an extension version selected, the function gives that version number if it is within the requested range. If the selected version number is outside the requested range, the function returns LINEERR_INCOMPATIBLEEXTVERSION.

## See also

[INITIALIZE_NEGOTIATION](https://learn.microsoft.com/windows/desktop/Tapi/initialize-negotiation)

[TSPI_lineNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiatetspiversion)