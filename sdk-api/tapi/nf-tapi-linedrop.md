# lineDrop function

## Description

The
**lineDrop** function drops or disconnects the specified call. The application has the option to specify user-user information to be transmitted as part of the call disconnect.

## Parameters

### `hCall`

Handle to the call to be dropped. The application must be an owner of the call. The call state of *hCall* can be any state except *idle*.

### `lpsUserUserInfo`

Pointer to a string containing user-user information to be sent to the remote party as part of the call disconnect. This pointer can be left **NULL** if no user-user information is to be sent. User-user information is only sent if supported by the underlying network (see
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)). The protocol discriminator field for the user-user information, if required, should appear as the first byte of the buffer pointed to by *lpsUserUserInfo*, and must be accounted for in *dwSize*.

### `dwSize`

Size of the user-user information in *lpsUserUserInfo*, in bytes. If *lpsUserUserInfo* is **NULL**, no user-user information is sent to the calling party and *dwSize* is ignored.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_NOTOWNER, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_USERUSERINFOTOOBIG, LINEERR_INVALCALLSTATE, LINEERR_UNINITIALIZED.

## Remarks

When invoking
**lineDrop**, related calls can sometimes be affected as well. For example, dropping a conference call can drop all individual participating calls.
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) messages are sent to the application for all calls whose call state is affected. A dropped call typically transitions to the *idle* state. Invoking
**lineDrop** on a call in the *offering* state rejects the call. Not all telephone networks provide this capability.

A call in the *onholdpending* state typically reverts to the *connected* state. When dropping the consultation call to the third party for a conference call or when removing the third party in a previously established conference call, the provider (and switch) can release the conference bridge and revert the call back to a normal two-party call. If this is the case, *hConfCall* transitions to the *idle* state, and the only remaining participating call transitions to the *connected* state. Some switches automatically "unhold" the other call.

The application has the option to send user-user information at the time of the drop. Even if user-user information can be sent, there is no guarantee that the network will deliver this information to the remote party.

In various bridged or party-line configurations when multiple parties are on the call,
**lineDrop** may not actually clear the call. For example, in a bridged situation, a
**lineDrop** operation may not actually drop the call because the status of other stations on the call may govern; instead, the call may simply be changed to the LINECONNECTEDMODE_INACTIVE mode if it remains *connected* at other stations.

## See also

[Drop overview](https://learn.microsoft.com/windows/desktop/Tapi/drop-ovr)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[Terminate a Session overview](https://learn.microsoft.com/windows/desktop/Tapi/terminate-a-session-ovr)