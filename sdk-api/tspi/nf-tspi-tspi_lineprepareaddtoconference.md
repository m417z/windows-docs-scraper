# TSPI_linePrepareAddToConference function

## Description

The
**TSPI_linePrepareAddToConference** function prepares an existing conference call for the addition of another party. It creates a new, temporary consultation call. The new consultation call can be subsequently added to the conference call.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdConfCall`

The handle to a conference call. The call state of *hdConfCall* can be *connected*.

### `htConsultCall`

The TAPI handle to the new, temporary consultation call. The service provider must save this and use it in all subsequent calls to the
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) procedure reporting events on the new call. The call state of *hdAddCall* is not applicable.

### `lphdConsultCall`

A pointer to an
[HDRVCALL](https://learn.microsoft.com/windows/desktop/Tapi/hdrvline) representing the service provider's identifier for the new, temporary consultation call. The service provider must fill this location with its handle for the new call before this procedure returns. This handle is invalid if the function results in an error.

### `lpCallParams`

A pointer to a
[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams) containing call parameters to use when establishing the consultation call. This parameter is set to **NULL** if no special call setup parameters are desired.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_BEARERMODEUNAVAIL, LINEERR_INVALLINESTATE, LINEERR_CALLUNAVAIL, LINEERR_INVALMEDIAMODE, LINEERR_CONFERENCEFULL, LINEERR_INVALRATE, LINEERR_INUSE, LINEERR_NOMEM, LINEERR_INVALADDRESSMODE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALBEARERMODE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLPARAMS, LINEERR_RATEUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCONFCALLHANDLE, LINEERR_USERUSERINFOTOOBIG.

## Remarks

The service provider returns LINEERR_INVALLINESTATE if the line is currently not in a state in which this operation can be performed. The service provider must indicate a list of currently valid operations in the **dwLineFeatures** member (of the type **LINEFEATURE**) in the
[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus) structure.

The service provider returns LINEERR_INVALCALLSTATE if the conference call is not in a valid state for the requested operation.

This function places an existing conference call in the *onHoldPendingConference* state and creates a consultation call that can be added later to the existing conference call with
[TSPI_lineAddToConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineaddtoconference).

The consultation call can be canceled using
[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop). It may also be possible for TAPI to swap between the consultation call and the held conference call with
[TSPI_lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineswaphold). The service provider initially does media monitoring on the new call for at least the set of media types that were monitored for on the line.

This function differs from the corresponding TAPI function in that it follows the TSPI model for beginning the lifetime of a call. TAPI and the service provider exchange opaque handles representing the call with one another. In addition, the service provider is permitted to do callbacks for the new call before it returns from this procedure. In any case, the service provider must also treat the handle it returned as "not yet valid" until after the matching
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) message reports success. In other words, it must not issue any
[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent) messages for the new call or include it in call counts in messages or status data structures for the line.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINECALLPARAMS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallparams)

[LINEDEVSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevstatus)

[LINEEVENT](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-lineevent)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineAddToConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineaddtoconference)

[TSPI_lineDial](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedial)

[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop)

[TSPI_lineRemoveFromConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineremovefromconference)

[TSPI_lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetupconference)

[TSPI_lineSwapHold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineswaphold)