# lineSetAgentActivity function

## Description

The
**lineSetAgentActivity** function sets the agent activity code associated with a particular address.

## Parameters

### `hLine`

Handle to the line device.

### `dwAddressID`

Identifier of the address for which the agent activity code is to be changed. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `dwActivityID`

New agent activity. The meaning of all values of this parameter are specific to the application and call center server.

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, the function returns one of these negative error values:

LINEERR_INVALADDRESSID, LINEERR_INVALADDRESSSTATE, LINEERR_INVALAGENTACTIVITY, LINEERR_INVALLINEHANDLE, LINEERR_INVALPOINTER, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)