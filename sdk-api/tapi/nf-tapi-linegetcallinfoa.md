# lineGetCallInfoA function

## Description

The
**lineGetCallInfo** function enables an application to obtain fixed information about the specified call.

## Parameters

### `hCall`

Handle to the call to be queried. The call state of *hCall* can be any state.

### `lpCallInfo`

Pointer to a variably sized data structure of type
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo). Upon successful completion of the request, this structure is filled with call-related information. Prior to calling
**lineGetCallInfo**, the application should set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns zero if the request succeeds or a negative error number if an error occurs. Possible return values are:

LINEERR_INVALCALLHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_STRUCTURETOOSMALL, LINEERR_NOMEM, LINEERR_UNINITIALIZED, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL.

## Remarks

A separate
[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo) structure exists for every incoming or outgoing call. The structure contains primarily fixed information about the call. An application would typically be interested in checking this information when it receives its handle for a call by the
[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate) message, or each time it receives notification by a
[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo) message that parts of the call information structure have changed. These messages supply the handle for the call as a parameter.

> [!NOTE]
> The tapi.h header defines lineGetCallInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Basic Telephony Services Reference](https://learn.microsoft.com/windows/desktop/Tapi/basic-telephony-services-reference)

[LINECALLINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-linecallinfo)

[LINE_CALLINFO](https://learn.microsoft.com/windows/desktop/Tapi/line-callinfo)

[LINE_CALLSTATE](https://learn.microsoft.com/windows/desktop/Tapi/line-callstate)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)