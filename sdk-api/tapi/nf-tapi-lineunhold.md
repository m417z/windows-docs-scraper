# lineUnhold function

## Description

The
**lineUnhold** function retrieves the specified held call.

## Parameters

### `hCall`

Handle to the call to be retrieved. The application must be an owner of this call. The call state of *hCall* must be *onHold*, *onHoldPendingTransfer*, or *onHoldPendingConference*.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding [LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_NOTOWNER, LINEERR_UNINITIALIZED.

## See also

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)