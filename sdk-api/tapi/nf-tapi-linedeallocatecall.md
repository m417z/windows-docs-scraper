# lineDeallocateCall function

## Description

The
**lineDeallocateCall** function deallocates the specified call handle.

## Parameters

### `hCall`

The call handle to be deallocated. An application with monitoring privileges for a call can always deallocate its handle for that call. An application with owner privilege for a call can deallocate its handle unless it is the sole owner of the call and the call is not in the *idle* state. The call handle is no longer valid after it has been deallocated.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values include:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLSTATE, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## Remarks

The deallocation does not affect the call state of the physical call. It does, however, release internal resources related to the call.

In API versions, earlier than 2.0, if the application is the sole owner of a call and the call is not in the *idle* state, LINEERR_INVALCALLSTATE is returned. In this case, the application can first drop the call using
[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop) and deallocate its call handle afterward. An application that has monitor privilege for a call can always deallocate its handle for the call.

In API versions 2.0 or later, the sole owner of the call can deallocate its handle even though the call is not in the *idle* state. This enables distributed control of the call in a client/server environment.

**Note** Leaving the call without an owner can result in the user being unable to terminate the call if there are monitoring applications open preventing TAPI from calling
[TSPI_lineCloseCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosecall). Use this feature only if the application can determine that the call can be controlled externally by the user. For more information, see LINEADDRCAPFLAGS_CLOSEDROP.

In API versions earlier than 2.0, when the
**lineDeallocateCall** function deallocates a call handle, it also suspends further processing of any outstanding LINE_REPLY messages for the call. An application must be designed not to wait indefinitely for LINE_REPLY messages for each corresponding call to an asynchronous function if it also uses the
**lineDeallocateCall** function to deallocate handles.

In API versions 2.0 or later,
**lineDeallocateCall** does not suspend outstanding LINE_REPLY messages; every asynchronous function that returns a *dwRequestID* to the application always results in the delivery of the associated LINE_REPLY message unless the application calls
[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[Terminate a Session Overview](https://learn.microsoft.com/windows/desktop/Tapi/terminate-a-session-ovr)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)

[lineShutdown](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineshutdown)