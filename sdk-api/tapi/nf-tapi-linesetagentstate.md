# lineSetAgentState function

## Description

The
**lineSetAgentState** function sets the agent state associated with a particular address.

## Parameters

### `hLine`

Handle to the line device.

### `dwAddressID`

Identifier of the address for which the agent information is to be changed. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `dwAgentState`

New agent state. Must be one of the
[LINEAGENTSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstate--constants), or zero to leave the agent state unchanged and modify only the next state.

### `dwNextAgentState`

The agent state that should be automatically set when the current call on the address becomes *idle*. For example, if it is known that after-call work must be performed, this field can be set to LINEAGENTSTATE_WORKAFTERCALL so that a new call is not assigned to the agent after the current call. Must be one of the
[LINEAGENTSTATE_ Constants](https://learn.microsoft.com/windows/desktop/Tapi/lineagentstate--constants), or zero to use the default next state configured for the agent.

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, the function returns one of these negative error values:

LINEERR_INVALADDRESSID, LINEERR_INVALADDRESSSTATE, LINEERR_INVALAGENTSTATE, LINEERR_INVALLINEHANDLE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)