# lineGetAgentGroupListA function

## Description

The
**lineGetAgentGroupList** function obtains the identities of agent groups (combination of queue, supervisor, skill level, and so on) into which the agent currently logged in on the workstation is permitted to log into on the automatic call distributor.

## Parameters

### `hLine`

Handle to the open line device.

### `dwAddressID`

Address on the open line device whose agent status is to be queried.

### `lpAgentGroupList`

Pointer to a variably sized structure of type
[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist). Upon successful completion of the request, this structure is filled with a list of the agent groups into which the agent can log in at this time (which should include any groups into which the agent is already logged in, if any).

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, this function returns one of these negative error values:

LINEERR_INVALADDRESSID, LINEERR_INVALAGENTID, LINEERR_INVALLINEHANDLE, LINEERR_INVALPOINTER, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_STRUCTURETOOSMALL, LINEERR_UNINITIALIZED.

## See also

[LINEAGENTGROUPLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentgrouplist)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

## Remarks

> [!NOTE]
> The tapi.h header defines lineGetAgentGroupList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).