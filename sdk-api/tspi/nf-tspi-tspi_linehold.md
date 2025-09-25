# TSPI_lineHold function

## Description

The
**TSPI_lineHold** function places the specified call on hold.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The service provider's handle to the call to be placed on hold. The call state of *hdCall* can be *connected*.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

The call on hold is temporarily disconnected, allowing TAPI to use the line device for making or answering other calls.
**TSPI_lineHold** performs a *hard hold* of the specified call, as opposed to a *consultation call*. A call on hard hold typically cannot be transferred or included in a conference call, whereas a consultation call can. Consultation calls are initiated using
[TSPI_lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetuptransfer),
[TSPI_lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetupconference), or
[TSPI_linePrepareAddToConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineprepareaddtoconference).

After a call is successfully placed on hold, the call state typically transitions to *onHold*. A held call is retrieved through
[TSPI_lineUnhold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineunhold). While a call is on hold, the service provider can send
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) messages about state changes of the held call. For example, if the held party hangs up, the call state can transition to *disconnected*, and the service provider can send a LINE_CALLSTATE message indicating the new state.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetupconference)

[TSPI_lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetuptransfer)

[TSPI_lineUnhold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineunhold)