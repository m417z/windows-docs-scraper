# lineSwapHold function

## Description

The
**lineSwapHold** function swaps the specified active call with the specified call on consultation hold.

## Parameters

### `hActiveCall`

Handle to the active call. The application must be an owner of the call. The call state of *hActiveCall* must be *connected*.

### `hHeldCall`

Handle to the consultation call. The application must be an owner of the call. The call state of *hHeldCall* can be *onHoldPendingTransfer*, *onHoldPendingConference*, or *onHold*.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONFAILED, LINEERR_NOMEM, LINEERR_RESOURCEUNAVAIL, LINEERR_NOTOWNER, LINEERR_UNINITIALIZED.

## Remarks

Swapping the active call with the call on consultation hold allows the application to alternate or toggle between these two calls. This is typical in call waiting.

## See also

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)