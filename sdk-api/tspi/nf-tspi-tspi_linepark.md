# TSPI_linePark function

## Description

The
**TSPI_linePark** function parks the specified call according to the specified park mode.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The handle to the call to be parked. The call state of *hdCall* can be *connected*.

### `dwParkMode`

The park mode with which the call is to be parked, only one of the
[LINEPARKMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineparkmode--constants).

### `lpszDirAddress`

A pointer to **null**-terminated Unicode string that indicates the address where the call is to be parked when using directed park. The address is in dialable address format. This parameter is ignored for nondirected park.

### `lpNonDirAddress`

A pointer to a structure of type
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring). For nondirected park, the address where the call is parked is returned in this structure. This parameter is ignored for directed park. Within the
**VARSTRING** structure, *dwStringFormat* must be set to STRINGFORMAT_ASCII (an ASCII string buffer containing a **null**-terminated string), and the terminating **NULL** is accounted for in the *dwStringSize*. If the memory pointed to by the *lpNonDirAddress* parameter is not large enough for the requested address, the
**TSPI_linePark** function returns LINEERR_STRUCTURETOOSMALL.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_NOMEM, LINEERR_INVALPARKMODE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_INVALADDRESS, LINEERR_RESOURCEUNAVAIL, LINEERR_STRUCTURETOOSMALL.

## Remarks

All members of the
[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring) structure, except **dwTotalSize**, are filled in by the service provider. The **dwTotalSize** member is filled in by TAPI, and the service provider must not overwrite this value.

Under directed park, the client application (through TAPI) specifies the address at which it wants to park the call. Under nondirected park, the switch determines the address and provides this to TAPI. In either case, a parked call can be unparked by specifying this address.

The parked call typically enters the *idle* call state after it is successfully parked. The service provider reports the new state using a
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) message. A subsequent
[TSPI_lineUnpark](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineunpark) creates a new, distinct call handle, regardless of whether
[TSPI_lineCloseCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosecall) has destroyed the old handle.

Some switches can remind the user after a call has been parked for some long amount of time. The service provider reports this to TAPI as an *offering* call with a call reason set to *reminder* (if this is known).

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINEPARKMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineparkmode--constants)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineCloseCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosecall)

[TSPI_lineUnpark](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineunpark)

[VARSTRING](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-varstring)