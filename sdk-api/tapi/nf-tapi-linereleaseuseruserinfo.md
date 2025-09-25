# lineReleaseUserUserInfo function

## Description

The
**lineReleaseUserUserInfo** function informs the service provider that the application has processed the user-user information contained in the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure, and that subsequently received user-user information can now be written into that structure. The service provider sends a
[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo) message indicating LINECALLINFOSTATE_USERUSERINFO when new information is available.

## Parameters

### `hCall`

Handle to the call. The application must be an owner of the call. The call state of *hCall* can be any state.

## Return value

Returns a positive request identifier if the function is completed asynchronously or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_NOTOWNER, LINEERR_UNINITIALIZED, LINEERR_OPERATIONUNAVAIL.

## Remarks

The
**lineReleaseUserUserInfo** function allows the application to control the flow of incoming user-user information on an ISDN connection. When a new, complete user-user information message is received, the service provider informs the application using a
[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo) message (specifying LINECALLINFOSTATE_USERUSERINFO). Any number of applications can examine the information (using
[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo)), but the application owning the call controls when the information is released so that subsequent information can be reported. The service provider will not overwrite previous user-user information in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) with newer information until after
**lineReleaseUserUserInfo** has been called. It is the responsibility of the service provider to buffer subsequently received user-user information until the previous information is released by the application owning the call.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo)