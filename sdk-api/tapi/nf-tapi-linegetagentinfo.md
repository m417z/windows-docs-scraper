# lineGetAgentInfo function

## Description

The
**lineGetAgentInfo** function returns a structure holding the ACD information associated with a particular agent handle. It generates a
[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest) message to be sent to a registered proxy function handler, referencing a
[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest) structure of type LINEPROXYREQUEST_GETAGENTINFO.

## Parameters

### `hLine`

Handle to the line device.

### `hAgent`

Identifier of the agent whose information is to be retrieved.

### `lpAgentInfo`

Pointer to a structure of type
[LINEAGENTINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentinfo). If the request succeeds, this structure is filled with the agent statistics.

## Return value

Returns a request identifier if the asynchronous operation starts; otherwise, the function returns one of the following error values:

LINEERR_INVALLINEHANDLE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## Remarks

Prior to calling the
**lineGetAgentInfo** function, the application should set the **dwTotalSize** member of the
[LINEAGENTINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentinfo) structure to indicate the amount of memory available to TAPI for returning information.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEAGENTINFO](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentinfo)

[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest)

[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest)