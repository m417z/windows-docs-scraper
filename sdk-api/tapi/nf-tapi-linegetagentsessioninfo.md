# lineGetAgentSessionInfo function

## Description

The
**lineGetAgentSessionInfo** function returns a structure that holds the ACD information associated with a particular agent session handle. It generates a
[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest) message to be sent to a registered proxy function handler, referencing a
[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest) structure of type LINEPROXYREQUEST_GETAGENTSESSIONINFO.

## Parameters

### `hLine`

Handle to the line device.

### `hAgentSession`

Identifier of the agent session whose information is to be retrieved.

### `lpAgentSessionInfo`

Pointer to a structure of type
[LINEAGENTSESSIONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentsessioninfo). Upon successful completion of the request, this structure is filled with the agent session statistics. Prior to calling the
**lineGetAgentSessionInfo** function, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that memory could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns a request identifier if the asynchronous operation starts; otherwise, the function returns one of the following error values:

LINEERR_INVALLINEHANDLE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEAGENTSESSIONINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentsessioninfo)

[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest)

[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest)