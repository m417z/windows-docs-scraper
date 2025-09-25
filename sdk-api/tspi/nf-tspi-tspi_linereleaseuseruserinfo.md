# TSPI_lineReleaseUserUserInfo function

## Description

The
**TSPI_lineReleaseUserUserInfo** function informs the service provider that the user-user information contained in the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure has been processed, and that subsequently received user-user information can now be written into that structure. The service provider sends a
[LINE_CALLINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725218(v=vs.85)) message indicating LINECALLINFOSTATE_USERUSERINFO when new information is available.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The service provider's handle to the call for which user-user information is to be released. The call state of *hdCall* can be *any*.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## Remarks

The
**TSPI_lineReleaseUserUserInfo** function permits control of the flow of incoming user-user information on an ISDN connection. When a new, complete user-user information message is received, the service provider informs TAPI using a
[LINE_CALLINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725218(v=vs.85)) message (specifying LINECALLINFOSTATE_USERUSERINFO). The user-user information and other fields in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) can be examined by multiple calls to
[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo). The service provider must not overwrite previous user-user information in
**LINECALLINFO** with newer information until after
**TSPI_lineReleaseUserUserInfo** has been called. The service provider must buffer subsequently received user-user information until the previous information is released. Any remaining buffered information can be discarded when
[TSPI_lineCloseCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineclosecall) is invoked.

If this function is invoked while there is no user-user information in
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo), the service provider should nevertheless return an indication of success.

For backward compatibility, TAPI automatically returns LINEERR_OPERATIONUNAVAIL if this function is invoked for a call on a line under the control of a service provider that does not export the function.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINE_CALLINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725218(v=vs.85))

[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo)