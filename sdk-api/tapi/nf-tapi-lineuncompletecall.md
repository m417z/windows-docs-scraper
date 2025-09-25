# lineUncompleteCall function

## Description

The
**lineUncompleteCall** function cancels the specified call completion request on the specified line.

## Parameters

### `hLine`

Handle to the line device on which a call completion is to be canceled.

### `dwCompletionID`

Completion identifier for the request that is to be canceled.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALLINEHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALCOMPLETIONID, LINEERR_RESOURCEUNAVAIL, LINEERR_NOMEM, LINEERR_UNINITIALIZED, LINEERR_OPERATIONUNAVAIL.

## See also

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)