# TSPI_lineSecureCall function

## Description

The
**TSPI_lineSecureCall** function secures the call from any interruptions or interference that can affect the call's media stream.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The handle to the call to be secured. The call state of *hdCall* can be any state except *idle*.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

A call can be secured to avoid interference. For example, in an analog environment, call waiting tones can destroy a fax or modem session on the original call.
**TSPI_lineSecureCall** allows an existing call to be secured,
[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall) provides the option to secure the call from the time of call setup. The securing of a call remains in effect for the duration of the call.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[TSPI_lineMakeCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linemakecall)