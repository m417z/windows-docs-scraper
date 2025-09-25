# lineSetAgentSessionState function

## Description

The
**lineSetAgentSessionState** function sets the agent session state associated with a particular agent session handle. It generates a
[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest) message to be sent to a registered proxy function handler, referencing a
[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest) structure of type LINEPROXYREQUEST_SETAGENTSESSIONSTATE.

## Parameters

### `hLine`

Handle to the line device.

### `hAgentSession`

Identifier of the agent session whose information is to be changed.

### `dwAgentSessionState`

New agent session state. Must be one of the
[LINEAGENTSESSIONSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentsessionstate--constants) or zero to leave the agent session state unchanged and modify only the next state.

### `dwNextAgentSessionState`

Next agent session state. Must be one of the
[LINEAGENTSESSIONSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentsessionstate--constants) or zero.

## Return value

Returns a request identifier if the asynchronous operation starts; otherwise, the function returns one of the following error values:

LINEERR_INVALAGENTSTATE, LINEERR_INVALLINEHANDLE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEAGENTSESSIONSTATE_ constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentsessionstate--constants)

[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest)

[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest)