# TSPI_lineRedirect function

## Description

The
**TSPI_lineRedirect** function redirects the specified offering call to the specified destination address.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The handle to the call to be redirected. The call state of *hdCall* can be *offering*.

### `lpszDestAddress`

Pointer to a null-terminated Unicode string that specifies the destination address. This follows the standard link format.

### `dwCountryCode`

The country or region code of the party the call is redirected to. If a value of 0 is specified, a default is used by the implementation. This parameter is not validated by TAPI when this function is called.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_NOMEM, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCOUNTRYCODE, LINEERR_OPERATIONFAILED, LINEERR_INVALADDRESS, LINEERR_RESOURCEUNAVAIL.

## Remarks

The service provider does not redirect the call if it returns LINEERR_INVALADDRESS.

When this function is invoked, the service provider deflects the offering call to another address without first answering the call. Call redirect differs from call forwarding in that call forwarding is performed by the switch without the involvement of the called station; redirection can be done on a call-by-call basis by a client application, for example driven by caller ID information. It differs from call transfer in that transferring a call requires that the call first be answered.

After a call is successfully redirected, the call typically transitions to *idle*. The service provider indicates the new state using a
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) message.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineAccept](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineaccept)

[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop)

[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps)