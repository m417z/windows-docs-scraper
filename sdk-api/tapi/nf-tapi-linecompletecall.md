# lineCompleteCall function

## Description

The
**lineCompleteCall** function specifies how a call that could not be connected normally should be completed instead. The network or switch may not be able to complete a call because network resources are busy or the remote station is busy or doesn't answer. The application can request that the call be completed in one of a number of ways.

## Parameters

### `hCall`

Handle to the call whose completion is requested. The application must be an owner of the call. The call state of *hCall* must be *busy* or *ringback*.

### `lpdwCompletionID`

Pointer to a **DWORD**-sized memory location. The completion identifier is used to identify individual completion requests in progress. A completion identifier becomes invalid and can be reused after the request completes or after an outstanding request is canceled.

### `dwCompletionMode`

Way in which the call is to be completed. This parameter uses one and only one of the
[LINECALLCOMPLMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallcomplmode--constants).

### `dwMessageID`

Message that is to be sent when completing the call using LINECALLCOMPLMODE_MESSAGE. This identifier selects the message from a small number of predefined messages.

## Return value

Returns a positive request identifier if the function is completed asynchronously, or a negative error number if an error occurs. The *dwParam2* parameter of the corresponding
[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply) message is zero if the function succeeds or it is a negative error number if an error occurs. Possible return values are:

LINEERR_COMPLETIONOVERRUN, LINEERR_NOMEM, LINEERR_INVALCALLCOMPLMODE, LINEERR_NOTOWNER, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLHANDLE, LINEERR_OPERATIONFAILED, LINEERR_INVALMESSAGEID, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_UNINITIALIZED.

## Remarks

This function is considered complete when the request has been accepted by the network or switch; not when the request is fully completed in the way specified. After this function completes, the call typically transitions to *idle*. When the called station or network enters a state where the call can be completed as requested, the application is notified by a
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message with the call state equal to *offering*. The call's
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) record lists the reason for the call as CALLCOMPLETION and provides the completion identifier as well. It is possible to have multiple outstanding call completion requests; the maximum number is device dependent. The completion identifier is also used to refer to each individual request so requests can be canceled by calling
[lineUncompleteCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineuncompletecall).

## See also

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[LINE_REPLY](https://learn.microsoft.com/windows/desktop/Tapi/line-reply)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineUncompleteCall](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-lineuncompletecall)