# TSPI_lineOpen function

## Description

The
**TSPI_lineOpen** function opens the line device whose device identifier is given, returning the service provider's handle for the device. The service provider must retain the TAPI handle for the device for use in subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) callback procedure.

## Parameters

### `dwDeviceID`

Identifies the line device to be opened.

### `htLine`

The TAPI handle for the line device to be used in subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) callback procedure to identify the device.

### `lphdLine`

A pointer to an
[HDRVLINE](https://learn.microsoft.com/windows/desktop/Tapi/hdrvline) where the service provider fills in its handle for the line device.

### `dwTSPIVersion`

The TSPI version.

### `lpfnEventProc`

A pointer to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) callback procedure supplied by TAPI that the service provider calls to report subsequent events on the line.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_ALLOCATED, LINEERR_OPERATIONUNAVAIL, LINEERR_NODRIVER, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

The service provider should reserve any non-sharable resources that are required to manage the line. However, any actions that can be postponed to
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) should be. It is a design assumption in TAPI that
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen) is an "inexpensive" operation. For example, if the line is opened in monitor mode only, it should not be necessary for a COMM-port-based service provider to open the COMM port.

This procedure does not correspond directly to any procedure at the TAPI level, at which the functions of enabling device-specific extensions, selecting line characteristics, and setting media type detection are included in the functionality defined by
[lineOpen](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineopen). At the TSPI level, these additional capabilities are separated out into
[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion),
[TSPI_lineSetDefaultMediaDetection](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdefaultmediadetection) and
[TSPI_lineConditionalMediaDetection](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineconditionalmediadetection).

## See also

[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent)

[LINE_CLOSE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725220(v=vs.85))

[TSPI_lineClose](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclose)

[TSPI_lineConditionalMediaDetection](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineconditionalmediadetection)

[TSPI_lineNegotiateExtVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiateextversion)

[TSPI_lineNegotiateTSPIVersion](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linenegotiatetspiversion)

[TSPI_lineSetDefaultMediaDetection](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetdefaultmediadetection)