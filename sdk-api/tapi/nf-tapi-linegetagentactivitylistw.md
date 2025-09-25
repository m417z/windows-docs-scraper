# lineGetAgentActivityListW function

## Description

The
**lineGetAgentActivityList** function obtains the identities of activities that the application can select using
[lineSetAgentActivity](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentactivity) to indicate what function the agent is actually performing at the moment.

## Parameters

### `hLine`

Handle to the open line device.

### `dwAddressID`

Address on the open line device whose agent status is to be queried. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `lpAgentActivityList`

Pointer to a variably sized structure of type
[LINEAGENTACTIVITYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentactivitylist). Upon successful completion of the request, this structure is filled with a list of the agent activity codes that can be selected using
[lineSetAgentActivity](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentactivity). Prior to calling
**lineGetAgentActivityList**, the application should set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, this function returns one of these negative error values:

LINEERR_INVALADDRESSID, LINEERR_OPERATIONFAILED, LINEERR_INVALAGENTID, LINEERR_OPERATIONUNAVAIL, LINEERR_INVALLINEHANDLE, LINEERR_RESOURCEUNAVAIL, LINEERR_INVALPOINTER, LINEERR_STRUCTURETOOSMALL, LINEERR_NOMEM, LINEERR_UNINITIALIZED.

## See also

[LINEAGENTACTIVITYLIST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentactivitylist)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineSetAgentActivity](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentactivity)

## Remarks

> [!NOTE]
> The tapi.h header defines lineGetAgentActivityList as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).