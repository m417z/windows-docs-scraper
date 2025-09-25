# TSPI_lineAnswer function

## Description

The
**TSPI_lineAnswer** function answers the specified offering call.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The service provider's handle to the call to be answered. The call state of *hdCall* can be *offering* or *accepted*.

### `lpsUserUserInfo`

A pointer to a **null**-terminated string containing user-user information to be sent to the remote party at the time of answering the call. If this pointer is **NULL**, it indicates that no user-user information is to be sent. User-user information is only sent if supported by the underlying network (as indicated in
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)).

### `dwSize`

The size in bytes of the user-user information in *lpsUserUserInfo*. If *lpsUserUserInfo* is **NULL**, *dwSize* is ignored.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_INUSE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_USERUSERINFOTOOBIG.

## Remarks

When a new call arrives, the service provider sends TAPI a
[LINE_NEWCALL](https://learn.microsoft.com/windows/desktop/Tapi/line-newcall) message to exchange handles for the call. The service provider follows this with a
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) message to inform TAPI and its client applications of the call's state. A client application typically answers the call using
**TSPI_lineAnswer**. Typically, after the call is successfully answered, the call transitions to the *connected* state.

In some telephony environments (like ISDN) where user alerting is separate from call offering, TAPI and its client applications may have the option to first accept a call prior to answering, or instead to reject or redirect the *offering* call.

If a call is offered at the time another call is already active, the new call is connected to by invoking
**TSPI_lineAnswer**. The effect this has on the existing active call depends on the line's device capabilities. The first call may be unaffected, it may automatically be dropped, or it may automatically be placed on hold. The appropriate LINE_CALLSTATE messages are used to report state transitions to TAPI about both calls.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[LINE_NEWCALL](https://learn.microsoft.com/windows/desktop/Tapi/line-newcall)