# TSPI_lineSwapHold function

## Description

The
**TSPI_lineSwapHold** function swaps the specified active call with the specified call on consultation hold.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdActiveCall`

The handle to the call to be swapped with the call on consultation hold. The call state of *hdActiveCall* can be *connected*.

### `hdHeldCall`

The handle to the consultation call. The call state of *hdHeldCall* can be *onHoldPendingTransfer*, *onHoldPendingConference*, or *onHold*.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

The service provider must send
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) messages for the call transitions.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetupconference)

[TSPI_lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetuptransfer)