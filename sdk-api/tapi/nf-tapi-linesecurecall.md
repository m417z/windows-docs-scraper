# lineSecureCall function

## Description

The
**lineSecureCall** function secures the call from any interruptions or interference that can affect the call's media stream.

## Parameters

### `hCall`

Handle to the call to be secured. The application must be an owner of the call. The call state of *hCall* can be any state.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_NOTOWNER, LINEERR_UNINITIALIZED.

## Remarks

A call can be secured to avoid interference. For example, in an analog environment, call-waiting tones can destroy a fax or modem session on the original call. The
**lineSecureCall** function allows an existing call to be secured. The
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) function provides the option to secure the call from the time of call setup. The securing of a call remains in effect for the duration of the call.

## See also

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Secure a Session overview](https://learn.microsoft.com/windows/desktop/Tapi/secure-a-session-ovr)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)