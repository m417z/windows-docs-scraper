# lineGetAgentStatusW function

## Description

The
**lineGetAgentStatus** function obtains the agent-related status on the specified address.

## Parameters

### `hLine`

Handle to the open line device.

### `dwAddressID`

Address on the open line device whose agent status is to be queried. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `lpAgentStatus`

Pointer to a variably sized structure of type
[LINEAGENTSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentstatus). Upon successful completion of the request, this structure is filled with agent status information. Prior to calling
**lineGetAgentStatus**, the application must set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

**Note** If the size parameters in the structure are not correct, there is a possibility that memory could get overwritten. For more information on setting structure sizes, see the
[memory allocation](https://learn.microsoft.com/windows/desktop/Tapi/memory-allocation) topic.

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, one of these negative error values:

LINEERR_INVALADDRESSID, LINEERR_INVALLINEHANDLE, LINEERR_INVALPOINTER, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_STRUCTURETOOSMALL, LINEERR_UNINITIALIZED.

## See also

[LINEAGENTSTATUS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentstatus)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

## Remarks

> [!NOTE]
> The tapi.h header defines lineGetAgentStatus as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).