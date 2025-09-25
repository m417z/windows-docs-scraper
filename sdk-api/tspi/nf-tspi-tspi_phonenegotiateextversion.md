# TSPI_phoneNegotiateExtVersion function

## Description

The
**TSPI_phoneNegotiateExtVersion** function returns the highest extension version number the service provider can operate under for this device, given the range of possible extension versions.

## Parameters

### `dwDeviceID`

Identifies the phone device for which interface version negotiation is to be performed.

### `dwTSPIVersion`

Specifies an interface version number that is negotiated for this device using
[TSPI_phoneNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiatetspiversion). This function operates according to the interface specification at this version level.

### `dwLowVersion`

The lowest extension version number under which TAPI or its client application can operate. The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number.

### `dwHighVersion`

The highest extension version number under which TAPI or its client application can operate. The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number.

### `lpdwExtVersion`

A pointer to a **DWORD**. Upon a successful return from this function, the service provider fills this location with the highest extension version number, within the range requested by the caller, under which the service provider can operate. The most-significant **WORD** is the major version number and the least-significant **WORD** is the minor version number. If the requested range does not overlap the range supported by the service provider, the function returns PHONEERR_INCOMPATIBLEEXTVERSION.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

PHONEERR_INCOMPATIBLEAPIVERSION, PHONEERR_RESOURCEUNAVAIL, PHONEERR_INCOMPATIBLEEXTVERSION, PHONEERR_OPERATIONFAILED, PHONEERR_NODRIVER, PHONEERR_OPERATIONUNAVAIL, PHONEERR_NOMEM.

## Remarks

This function can be called before or after the device has been opened by TAPI. If the device is currently open and has an extension version selected, the function should return that version number if it is within the requested range. If the selected version number is outside the requested range, the function returns PHONEERR_INCOMPATIBLEEXTVERSION.

## See also

[TSPI_phoneNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_phonenegotiatetspiversion)