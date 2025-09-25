# TSPI_lineDrop function

## Description

The
**TSPI_lineDrop** function drops or disconnects the specified call. User-user information can optionally be transmitted as part of the call disconnect. This function can be called by the application at any time. When
**TSPI_lineDrop** returns, the call should be *idle*.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The service provider's handle to the call to be dropped. The call state of *hdCall* can be any state except *idle*.

### `lpsUserUserInfo`

This pointer is only valid if **dwSize** is nonzero. It specifies a pointer to a **null**-terminated string containing user-user information to be sent to the remote party as part of the call disconnect. This pointer is **NULL** if no user-user information is to be sent. User-user information is only sent if supported by the underlying network (see
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)).

### `dwSize`

The size in bytes of the user-user information in *lpsUserUserInfo*. If *lpsUserUserInfo* is **NULL**, *dwSize* is ignored.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLSTATE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_USERUSERINFOTOOBIG, LINEERR_OPERATIONUNAVAIL.

## Remarks

The service provider returns LINEERR_INVALCALLSTATE if the current state of the call does not allow the call to be dropped.

When invoking
**TSPI_lineDrop**, related calls can sometimes be affected as well. For example, dropping a conference call may drop all individual participating calls.
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) messages are sent to TAPI for all calls whose call state is affected. Typically, a dropped call transitions to the *idle* state. Invoking
**TSPI_lineDrop** on a call in the *offering* state rejects the call. Not all telephone networks provide this capability.

In situations where the call to be dropped is a consultation call established during transfer or conference call establishment, the original call that was placed in the *OnHoldPending* state is reconnected to and it typically re-enters the *connected* call state.

TAPI has the option to send user-user information at the time of the drop. Even if user-user information can be sent, there is no guarantee that the network will deliver this information to the remote party.

**Note** In various bridged or party line configurations when multiple parties are on the call,
**TSPI_lineDrop** may not actually clear the call.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineGetDevCaps](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetdevcaps)