# TSPI_lineCompleteCall function

## Description

The
**TSPI_lineCompleteCall** function is used to specify how a call that cannot be connected normally is to be completed instead. The network or switch may not be able to complete a call because network resources are busy or the remote station is busy or doesn't answer.

## Parameters

### `dwRequestID`

The identifier of the asynchronous request.

### `hdCall`

The service provider's handle to the call whose completion is requested. The call state of *hdCall* can be *busy*, *ringback*, or *proceeding*.

### `lpdwCompletionID`

A pointer to a **DWORD**-sized memory location where the service provider writes a completion identifier. This uniquely identifies a completion request in progress on the line that contains the *hdCall*. In particular, a completion identifier becomes invalid after the request completes or is canceled using the
[TSPI_lineUncompleteCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineuncompletecall) function. The service provider is free to reuse the completion identifier as soon as it becomes invalid.

### `dwCompletionMode`

The way in which the call is to be completed. This parameter uses one and only one of the
[LINECALLCOMPLMODE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallcomplmode--constants).

### `dwMessageID`

The message that is to be sent when completing the call using LINECALLCOMPLMODE_MESSAGE. This identifier selects the message from a small number of predefined messages. This parameter is not validated by TAPI when this function is called.

## Return value

Returns *dwRequestID* or an error number if an error occurs. The *lResult* actual parameter of the corresponding
[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion) is zero if the function succeeds or an error number if an error occurs. Possible return values are as follows:

LINEERR_INVALCALLHANDLE, LINEERR_NOMEM, LINEERR_INVALCALLSTATE, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALCALLCOMPLMODE, LINEERR_OPERATIONFAILED, LINEERR_INVALPOINTER, LINEERR_RESOURCEUNAVAIL, LINEERR_COMPLETIONOVERRUN, LINEERR_INVALMESSAGEID.

## Remarks

This function is considered complete when the request is accepted by the network or switch; not when the request is fully completed in the way specified. When the called station or network enters a state where the call can be completed as requested, the service provider must send a
[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85)) message with the call state equal to *offering*. The call's
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) record lists the reason for the call as CALLCOMPLETION and provides the completion identifier as well. It is possible to have multiple call completion requests outstanding at any given time; the maximum number is device dependent. The completion identifier is also used to refer to each individual request so requests can be canceled by calling
[TSPI_lineUncompleteCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineuncompletecall).

## See also

[ASYNC_COMPLETION](https://learn.microsoft.com/windows/desktop/api/tspi/nc-tspi-async_completion)

[LINECALLCOMPLMODE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/linecallcomplmode--constants)

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus)

[LINE_CALLSTATE](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ms725219(v=vs.85))

[TSPI_lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_linegetcallinfo)

[TSPI_lineUncompleteCall](https://learn.microsoft.com/windows/desktop/api/tspi/nf-tspi-tspi_lineuncompletecall)