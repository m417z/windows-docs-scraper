# TSPI_lineDial function

## Description

The
**TSPI_lineDial** function dials the specified dialable number on the specified call.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The service provider's handle to the call to be dialed. The call state of *hdCall* can be any state except *idle* and *disconnected*.

### `lpszDestAddress`

Pointer to a **null**-terminated Unicode string that specifies the destination to be dialed using the standard dialable number format.

### `dwCountryCode`

The country or region code of the destination. The implementation uses this to select the call progress protocols for the destination address. If a value of 0 is specified, a default call-progress protocol defined by the service provider is used. TAPI does not validate this parameter when this function is called.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALADDRESS, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCOUNTRYCODE, LINEERR_DIALBILLING, LINEERR_INVALCALLSTATE, LINEERR_DIALQUIET, LINEERR_ADDRESSBLOCKED, LINEERR_DIALDIALTONE, LINEERR_NOMEM, LINEERR_DIALPROMPT, LINEERR_OPERATIONUNAVAIL.

## Remarks

The service provider returns LINEERR_INVALCALLSTATE if the current state of the call does not allow dialing.

The service provider carries out no dialing if it returns LINEERR_INVALADDRESS.

If the service provider returns LINEERR_DIALBILLING, LINEERR_DIALQUIET, LINEERR_DIALDIALTONE, or LINEERR_DIALPROMPT, it should perform none of the actions otherwise performed by
**TSPI_lineDial** (for example, no partial dialing, and no going offhook). This is because the service provider should pre-scan the number for unsupported characters first.

**TSPI_lineDial** is used for dialing on an existing call appearance; for example, call handles returned from
[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall) with **NULL** as the *lpszDestAddress* or ending in ';', call handles returned from
[TSPI_lineSetupTransfer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetuptransfer) or
[TSPI_lineSetupConference](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linesetupconference).
**TSPI_lineDial** can be invoked multiple times in the course of dialing in the case of multistage dialing, if the line's device capabilities permit it.

If the string pointed to by the *lpszDestAddress* parameter in the previous call to the
[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall) or
**TSPI_lineDial** function is terminated with a semicolon, an empty string in the current call to
**TSPI_lineDial** indicates that dialing is complete.

Multiple addresses can be provided in a single dial string separated by CRLF. Service providers that provide inverse multiplexing can establish individual physical calls with each of the addresses, and return a single call handle to the aggregate of all calls to the application. All addresses would use the same country or region code.

Dialing is considered complete after the address has been accepted by the service provider, not after the call is finally connected. Service providers that provide inverse multiplexing may allow multiple addresses to be provided at once. The service provider must send
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) messages to TAPI to inform it about the progress of the call.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall)