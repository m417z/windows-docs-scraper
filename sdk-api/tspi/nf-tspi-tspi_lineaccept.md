# TSPI_lineAccept function

## Description

The
**TSPI_lineAccept** function accepts the specified offered call. It can optionally send the specified user-user information to the calling party.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The handle to the call to be accepted. The call state of *hdCall* can be *offering*.

### `lpsUserUserInfo`

A pointer to a **null**-terminated Unicode string containing user-user information to be sent to the remote party as part of the call accept. This pointer is **NULL** if no user-user information is to be sent. User-user information is only sent if supported by the underlying network (see
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)).

### `dwSize`

The size in bytes of the user-user information in *lpsUserUserInfo*. If *lpsUserUserInfo* is **NULL**, *dwSize* is ignored.

## Return value

Returns *dwRequestID* if the function is completed asynchronously or an error number if an error occurs. The *lResult* parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLSTATE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_USERUSERINFOTOOBIG, LINEERR_OPERATIONUNAVAIL.

## Remarks

The
**TSPI_lineAccept** function is used in telephony environments (such as ISDN) that allow alerting associated with incoming calls to be separate from the initial offering of the call. When a call comes in, the call is first offered. For some small time duration, the client application may have the option to reject the call using
[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop), redirect the call to another station using
[TSPI_lineRedirect](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineredirect), answer the call using
[TSPI_lineAnswer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineanswer), or accept the call using
**TSPI_lineAccept**. After a call has been successfully accepted, alerting at both the called and calling device begins, and typically the call state transitions to the *accepted* state. The service provider must set the flag LINEADDRCAPFLAGS_ACCEPTTOALERT in the **dwAddrCapFlags** member of the
[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps) data structure if the application must call
**TSPI_lineAccept** for alerting to begin.

To TAPI, alerting is reported using the
[LINE_LINEDEVSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725231(v=vs.85)) message with the *ringing* indication.

**TSPI_lineAccept** may also be supported by non-ISDN service providers. The call state transition to the *accepted* state can be used by other of the TAPI clients as an indication that some application has claimed responsibility for the call and has presented the call to the user.

The client application has the option to send user-user information at the time of the accept. Even if user-user information can be sent, often no guarantees are made that the network will deliver this information to the calling party. The client application may consult a line's device capabilities to determine whether call accept is available.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINEADDRESSCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineaddresscaps)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[LINE_LINEDEVSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725231(v=vs.85))

[TSPI_lineAnswer](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineanswer)

[TSPI_lineDrop](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linedrop)

[TSPI_lineOpen](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineopen)

[TSPI_lineRedirect](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineredirect)