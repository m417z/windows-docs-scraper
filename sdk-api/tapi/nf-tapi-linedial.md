# lineDial function

## Description

The
**lineDial** function dials the specified dialable number on the specified call.

## Parameters

### `hCall`

Handle to the call on which a number is to be dialed. The application must be an owner of the call. The call state of *hCall* can be any state except *idle* and *disconnected*.

### `lpszDestAddress`

Destination to be dialed using the standard dialable number format.

### `dwCountryCode`

Country or region code of the destination. This is used by the implementation to select the call progress protocols for the destination address. If a value of 0 is specified, a service provider-defined default call progress protocol is used.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_ADDRESSBLOCKED, LINEERR_INVALPOINTER, LINEERR_DIALBILLING, LINEERR_NOMEM, LINEERR_DIALDIALTONE, LINEERR_NOTOWNER, LINEERR_DIALPROMPT, LINEERR_OPERATIONFAILED, LINEERR_DIALQUIET, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_UNINITIALIZED, LINEERR_INVALCOUNTRYCODE.

## Remarks

If LINEERR_INVALADDRESS is returned, no dialing has been done. If LINEERR_DIALBILLING, LINEERR_DIALQUIET, LINEERR_DIALDIALTONE, or LINEERR_DIALPROMPT is returned, none of the actions otherwise performed by
**lineDial** have occurred. For example, none of the dialable addresses prior to the offending character has been dialed, no hookswitch state has changed, and so on.

The
**lineDial** function is used for dialing on an existing call appearance. For example, after a call has been set up for transfer or conference, a consultation call is automatically allocated, and the
**lineDial** function would be used to perform the dialing of this consultation call. The
**lineDial** function can be invoked multiple times in the course of multistage dialing, if the line's device capabilities allow it. Also, multiple addresses can be provided in a single dial string separated by CRLF. Service providers that provide inverse multiplexing can establish individual physical calls with each of the addresses and can return a single call handle to the aggregate of all calls to the application. All addresses would use the same country or region code.

Dialing is considered complete after the address has been passed to the service provider; not after the call is finally connected. Service providers that provide inverse multiplexing can allow multiple addresses to be provided at once. The service provider sends LINE_CALLSTATE messages to the application to inform it about the progress of the call. To abort a call attempt while a call is being established, the invoking application should use
[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop).

An application can set the *lpszDestAddress* parameter of the
**lineDial** function to the address of an empty string to indicate that dialing is complete, but only if the previous calls to the
[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) and
**lineDial** functions have had the strings specified by *lpszDestAddress* terminated with semicolons.

The **lineDial** function can also be used in partial dialing. To initiate a call using partial dialing, the application calls [lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) and specifies a partial dialing string. A partial dial string is any dial string terminated by a semicolon. The call will typically transition to LINECALLSTATE_DIALING after which **lineDial** can be called to specify more dialing strings, each terminated by a semicolon. Dialing is completed by calling **lineDial** with a dial string that is not terminated with a semicolon (such as an empty string). This technique allows applications to perform interactive partial dialing with the user or enable more sophisticated dialing than a TSP may be capable of.

If a null destination string, or an empty string terminated with a semicolon (";") is entered in [lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall) the application transitions to LINE_CALLSTATE_DIALTONE. The **lineDial** function can be called in this state to enter a single dial string or multiple partial dial strings, each separated by a semicolon. The application transitions to the LINECALLSTATE_DIALING state after the first digit is entered.

**Note** The **lineDial** function is only available when a call is in LINECALLSTATE_DIALING or LINE_CALLSTATE_DIALTONE. If DTMF is needed while a call is connected (LINECALLSTATE_CONNECTED), use [lineGenerateDigits](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegeneratedigits).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[Dial Overview](https://learn.microsoft.com/windows/desktop/Tapi/dial-ovr)

[Dialable Addresses](https://learn.microsoft.com/windows/win32/tapi/address-ovr)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineDrop](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linedrop)

[lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linemakecall)