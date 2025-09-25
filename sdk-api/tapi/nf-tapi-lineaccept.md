# lineAccept function

## Description

The
**lineAccept** function accepts the specified offered call. It can optionally send the specified user-user information to the calling party.

## Parameters

### `hCall`

Handle to the call to be accepted. The application must be an owner of the call. Call state of *hCall* must be *offering*.

### `lpsUserUserInfo`

Pointer to a **null**-terminated string containing user-user information to be sent to the remote party as part of the call accept. This pointer can be left **NULL** if no user-user information is to be sent. User-user information is only sent if supported by the underlying network (see
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)). The protocol discriminator member for the user-user information, if required, should appear as the first byte of the buffer pointed to by *lpsUserUserInfo*, and must be accounted for in *dwSize*.

### `dwSize`

Size of the user-user information in *lpsUserUserInfo* (including the **null** terminator), in bytes. If *lpsUserUserInfo* is **NULL**, no user-user information is sent to the calling party and *dwSize* is ignored.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds, or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_INVALCALLSTATE, LINEERR_INVALPOINTER, LINEERR_NOMEM, LINEERR_NOTOWNER, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED, LINEERR_USERUSERINFOTOOBIG.

## Remarks

The
**lineAccept** function is used in telephony environments like Integrated Services Digital Network (ISDN) that allow alerting associated with incoming calls to be separate from the initial offering of the call. When a call comes in, it is first offered. For some small amount of time, the application may have the option to reject the call using
[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop), redirect the call to another station using
[lineRedirect](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineredirect), answer the call using
[lineAnswer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineanswer), or accept the call using
**lineAccept**. After a call has been successfully accepted by an application, alerting begins at both the called and calling device and the call state typically transitions to *accepted*.

Alerting is reported to the application by the
[LINE_LINEDEVSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-linedevstate) message with the *ringing* indication.

The
**lineAccept** function may also be supported by non-ISDN service providers. The call state transition to accepted can be used by other applications as an indication that another application has claimed responsibility for the call and has presented the call to the user.

The application has the option to send user-user information at the time of the accept. Even if user-user information is sent, there is no guarantee that the network will deliver this information to the calling party. An application should consult a line's device capabilities to determine whether call accept is available.

## See also

[Accept overview](https://learn.microsoft.com/windows/desktop/Tapi/accept-ovr)

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[lineAnswer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineanswer)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)

[lineRedirect](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineredirect)