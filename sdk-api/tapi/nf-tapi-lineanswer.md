# lineAnswer function

## Description

The
**lineAnswer** function answers the specified offering call.

## Parameters

### `hCall`

Handle to the call to be answered. The application must be an owner of this call. The call state of *hCall* must be *offering* or *accepted*.

### `lpsUserUserInfo`

Pointer to a **null**-terminated string containing user-user information to be sent to the remote party at the time the call is answered. This pointer can be left **NULL** if no user-user information is to be sent. User-user information is only sent if supported by the underlying network (see
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)). The protocol discriminator field for the user-user information, if required, should appear as the first byte of the buffer pointed to by *lpsUserUserInfo*, and must be accounted for in *dwSize*.

### `dwSize`

Size of the user-user information in *lpsUserUserInfo* (including the **null** terminator), in bytes If *lpsUserUserInfo* is **NULL**, no user-user information is sent to the calling party and *dwSize* is ignored.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INUSE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALCALLSTATE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NOMEM, LINEERR_USERUSERINFOTOOBIG, LINEERR_NOTOWNER.

## Remarks

When a new call arrives, applications with an interest in the call are sent a
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message to provide the new call handle and to inform the application about the call's state and the privileges to the new call (such as monitor or owner). The application with owner privilege for the call can answer this call using
**lineAnswer**. After the call has been successfully answered, the call typically transitions to the *connected* state. Initially, only one application is given owner privilege to the incoming call.

In some telephony environments (like ISDN), where user alerting is separate from call offering, the application can have the option to accept a call prior to answering or to reject or redirect the offering call.

If a call comes in (is offered) at the time another call is already active, invoking
**lineAnswer** connects to the new call. The effect this has on the existing active call depends on the line's device capabilities. The first call can be unaffected, it can automatically be dropped, or it can automatically be placed on hold. The appropriate LINE_CALLSTATE messages report state transitions to the application about both calls.

In a bridged situation, if a call is connected but in the LINECONNECTEDMODE_INACTIVE state, it can be joined using the
**lineAnswer** function.

The application has the option to send user-user information at the time of the answer. Even if user-user information can be sent, there is no guarantee that the network will deliver this information to the calling party. An application should consult a line's device capabilities to determine whether sending user-user information upon answering the call is available.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)