# TSPI_lineUnhold function

## Description

The
**TSPI_lineUnhold** function retrieves the specified held call.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The handle to the call to be retrieved. The call state of *hdCall* can be *onHold*.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

The service provider returns LINEERR_INVALCALLSTATE if the call is not currently on hold.

This operation works for calls on hard hold (calls placed on hold using
[TSPI_lineHold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linehold)) and on soft hold. The service provider should check that the call is currently in the *onHold*, *onHoldPendingTransfer*, or *onHoldPendingConference* state, change the state to *connected*, and send a LINECALLSTATE message for the new call state.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineHold](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linehold)