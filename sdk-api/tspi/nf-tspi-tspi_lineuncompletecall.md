# TSPI_lineUncompleteCall function

## Description

The
**TSPI_lineUncompleteCall** function is used to cancel the specified call completion request on the specified line.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdLine`

The handle to the line on which a call completion is to be canceled.

### `dwCompletionID`

The completion identifier for the request that is to be canceled. TAPI does not validate this parameter when this function is called.

## Return value

Returns *dwRequestID*, or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds, or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCOMPLETIONID, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL.

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[TSPI_lineCompleteCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linecompletecall)