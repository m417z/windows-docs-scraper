# TSPI_lineSetAppSpecific function

## Description

The
**TSPI_lineSetAppSpecific** function sets the application-specific field of the specified call's
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure.

## Parameters

### `hdCall`

The handle to the call whose application-specific field is to be set. The call state of *hdCall* can be any state.

### `dwAppSpecific`

The new content of the **dwAppSpecific** member for the call's
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure. This value is uninterpreted by the service provider. This parameter is not validated by TAPI when this function is called.

## Return value

Returns zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_OPERATIONUNAVAIL.

## Remarks

The application-specific field in the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) data structure that exists for each call is uninterpreted by the Telephony API or any of its service providers. Its usage is entirely defined by the applications. The field can be read from the
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) record returned by
[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo). However,
**TSPI_lineSetAppSpecific** must be used to set the field so that changes become visible to other applications. When this field is changed, the service provider sends a LINE_CALLINFO message with an indication that the **AppSpecific** field has changed.

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINE_CALLINFO](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725218(v=vs.85))

[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo)