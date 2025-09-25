# TSPI_lineSendUserUserInfo function

## Description

The
**TSPI_lineSendUserUserInfo** function sends user-user information to the remote party on the specified call.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The handle to the call on which to send user-user information. The call state of *hdCall* can be *connected*, *offering*, *accepted*, or *ringback*.

### `lpsUserUserInfo`

A pointer to a **null**-terminated Unicode string containing user-user information to be sent to the remote party. User-user information is only sent if supported by the underlying network (see
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)).

### `dwSize`

The size, in bytes, including the **null** terminator, of the user-user information in *lpsUserUserInfo*.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLSTATE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_USERUSERINFOTOOBIG, LINEERR_OPERATIONUNAVAIL.

## Remarks

This function can be used to send user-user information at any time during a connected call. If the size of the specified information to be sent is larger than what can fit into a single network message (as in ISDN), the service provider is responsible for breaking the information up into a sequence of chained network messages (using "more data").

User-user information can also be sent as part of call accept, call reject, call redirect, and when making calls. User-user information can also be received. The received information is reported in the call's
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure. Whenever user-user information arrives after call offering or prior to call disconnect, a
[LINE_CALLINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725218(v=vs.85)) message with a *UserUserInfo* parameter notifies TAPI that user-user information in the call-information record has changed. If multiple network messages are chained, the information is assembled by the service provider and a single message is sent to TAPI.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINE_CALLINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725218(v=vs.85))

[TSPI_lineAccept](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineaccept)

[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop)

[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo)

[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall)

[TSPI_lineRedirect](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineredirect)