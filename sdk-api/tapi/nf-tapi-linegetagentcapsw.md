# lineGetAgentCapsW function

## Description

The
**lineGetAgentCaps** function obtains the agent-related capabilities supported on the specified line device. If a specific agent is named, the capabilities include a listing of ACD groups into which the agent is permitted to log in.

## Parameters

### `hLineApp`

Handle to the application's registration with TAPI.

### `dwDeviceID`

Line device containing the address to be queried.

### `dwAddressID`

Address on the given line device whose capabilities are to be queried. An address identifier is permanently associated with an address; the identifier remains constant across operating system upgrades.

### `dwAppAPIVersion`

Highest API version supported by the application. This should not be the value negotiated using
[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion) on the device being queried.

### `lpAgentCaps`

Pointer to a variably sized structure of type
[LINEAGENTCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentcaps). Upon successful completion of the request, this structure is filled with agent capabilities information. Prior to calling
**lineGetAgentCaps**, the application should set the **dwTotalSize** member of this structure to indicate the amount of memory available to TAPI for returning information.

## Return value

Returns a positive request identifier if the asynchronous operation starts; otherwise, this function returns one of these negative error values:

LINEERR_BADDEVICEID, LINEERR_INCOMPATIBLEAPIVERSION, LINEERR_INVALADDRESSID, LINEERR_INVALAPPHANDLE, LINEERR_INVALPOINTER, LINEERR_NODEVICE, LINEERR_NODRIVER, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_STRUCTURETOOSMALL, LINEERR_UNINITIALIZED.

## See also

[LINEAGENTCAPS](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineagentcaps)

[Supplementary Line Service Functions](https://learn.microsoft.com/windows/desktop/Tapi/supplementary-line-service-functions)

[TAPI 2.2 Reference Overview](https://learn.microsoft.com/windows/desktop/Tapi/tapi-2-2-reference)

[lineNegotiateAPIVersion](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linenegotiateapiversion)

## Remarks

> [!NOTE]
> The tapi.h header defines lineGetAgentCaps as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).