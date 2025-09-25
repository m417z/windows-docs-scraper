# lineSendUserUserInfo function

## Description

 The
**lineSendUserUserInfo** function sends user-user information to the remote party on the specified call.

## Parameters

### `hCall`

Handle to the call on which to send user-user information. The application must be an owner of the call. The call state of *hCall* must be *connected*, *offering*, *accepted*, or *ringback*.

### `lpsUserUserInfo`

Pointer to a string containing user-user information to be sent to the remote party. User-user information is only sent if supported by the underlying network (see
[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)). The protocol discriminator field for the user-user information, if required, should appear as the first byte of the buffer pointed to by *lpsUserUserInfo*, and must be accounted for in *dwSize*.

### `dwSize`

Size of the user-user information in *lpsUserUserInfo*, in bytes.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_INVALPOINTER, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_USERUSERINFOTOOBIG, LINEERR_NOTOWNER, LINEERR_UNINITIALIZED.

## Remarks

This function can be used to send user-user information at any time during a connected call. If the size of the specified information to be sent is larger than what can fit into a single network message (as in ISDN), the service provider is responsible for dividing the information into a sequence of chained network messages (using "more data").

User-user information can also be sent as part of call accept, call reject, and call redirect, and when making calls. User-user information can also be received. The received information is available through the call's call-information record. Whenever user-user information arrives after call offering or prior to call disconnect, a
[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo) message with a *UserUserInfo* parameter notifies the application that user-user information in the call-information record has changed. If multiple network messages are chained, the information is assembled by the service provider and a single message is sent to the application.

This function may send data over the wire in unencrypted form; therefore, someone eavesdropping on the network may be able to read the data. The security risk of sending the data in clear text should be considered before using this method.

## See also

[LINEDEVCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linedevcaps)

[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)