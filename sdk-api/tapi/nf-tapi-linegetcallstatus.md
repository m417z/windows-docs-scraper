# lineGetCallStatus function

## Description

The
**lineGetCallStatus** function returns the current status of the specified call.

## Parameters

### `hCall`

Handle to the call to be queried. The call state of *hCall* can be any state.

### `lpCallStatus`

Pointer to a variably sized data structure of type
[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus). Upon successful completion of the request, this structure is filled with call status information. Prior to calling
**lineGetCallStatus**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that data could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_STRUCTURETOOSMALL, LINEERR_NOMEM, LINEERR_UNINITIALIZED, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL.

## Remarks

The
**lineGetCallStatus** function returns the dynamic status of a call, whereas
[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo) returns primarily static information about a call. Call status information includes the current call state, detailed mode information related to the call while in this state (if any), as well as a list of the available API functions the application can invoke on the call while the call is in this state. An application would typically be interested in requesting this information when it receives notification about a call state change by the LINE_CALLSTATE message.

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINECALLSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallstatus)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineGetCallInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetcallinfo)