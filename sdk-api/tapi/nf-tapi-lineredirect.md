# lineRedirect function

## Description

The
**lineRedirect** function redirects the specified offering call to the specified destination address.

## Parameters

### `hCall`

Handle to the call to be redirected. The application must be an owner of the call. The call state of *hCall* must be *offering*.

### `lpszDestAddress`

Pointer to the destination address. This follows the standard dialable number format.

### `dwCountryCode`

Country/region code of the party the call is redirected to. If a value of 0 is specified, a default is used by the implementation.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALADDRESS, LINEERR_NOTOWNER, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_INVALCOUNTRYCODE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED, LINEERR_NOMEM.

## Remarks

Call redirect allows an application to deflect an offering call to another address without first answering the call. Call redirect differs from call forwarding in that call forwarding is performed by the switch without the involvement of the application; redirection can be done on a call-by-call basis by the application, for example, driven by caller ID information. It differs from call transfer in that transferring a call requires the call first be answered.

After a call has been successfully redirected, the call typically transitions to idle.

Besides redirecting an incoming call, an application may have the option to accept the call using
[lineAccept](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineaccept), reject the call using
[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop), or answer the call using
[lineAnswer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineanswer). The availability of these operations is dependent on device capabilities.

## See also

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Redirect overview](https://learn.microsoft.com/windows/desktop/Tapi/redirect-ovr)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineAccept](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineaccept)

[lineAnswer](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineanswer)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)