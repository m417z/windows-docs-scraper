# lineSetAgentGroup function

## Description

The
**lineSetAgentGroup** function sets the agent groups into which the agent is logged into on a particular address.

## Parameters

### `hLine`

Handle to the line device.

### `dwAddressID`

Identifier of the address for which the agent information is to be changed. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `lpAgentGroupList`

Pointer to a
[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist) structure identifying the groups into which the current agent is to be logged in on the address. If the pointer is **NULL** or the number of groups in the indicated structure is zero, then the agent is logged out of any ACD groups into which it is currently logged in.

The "Name" fields in the
[LINEAGENTGROUPENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgroupentry) items in the list are ignored for purposes of this function; the control of the logged-in groups is based on the group identifier values only.

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, the function returns one of these negative error values:

LINEERR_INVALADDRESSID, LINEERR_INVALADDRESSSTATE, LINEERR_INVALAGENTGROUP, LINEERR_INVALAGENTID, LINEERR_INVALLINEHANDLE, LINEERR_INVALPARAM, LINEERR_INVALPASSWORD, LINEERR_INVALPOINTER, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[LINEAGENTGROUPENTRY](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgroupentry)

[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)