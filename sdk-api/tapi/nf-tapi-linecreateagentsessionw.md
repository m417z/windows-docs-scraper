# lineCreateAgentSessionW function

## Description

The
**lineCreateAgentSession** function creates a new AgentSession object. It generates a
[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest) message to be sent to a registered proxy function handler, referencing a
[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest) structure of type LINEPROXYREQUEST_CREATEAGENTSESSION.

## Parameters

### `hLine`

Handle to the line device.

### `hAgent`

Identifier of the agent for whom the session is to be created.

### `lpszAgentPIN`

Pointer to a **null**-terminated Unicode string containing the agent PIN or password. Used when working with legacy ACD systems that require a separate PIN for each session created (or group logged into). With an ACD system that uses the operating system's user login for authentication, *lpszAgentPIN* is set to **NULL**.

### `dwWorkingAddressID`

Identifier of the address on which the agent will receive calls for this session.

### `lpGroupID`

Pointer to a GUID that identifies the group for which the session is being created.

### `lphAgentSession`

Handle to the created agent session, returned by the ACD proxy. It is the responsibility of the agent handler proxy application to generate and maintain uniqueness of these identifiers.

## Return value

Returns a request identifier if the asynchronous operation starts; otherwise, the function returns one of the following error values:

LINEERR_INVALLINEHANDLE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[About Call Center Controls](https://learn.microsoft.com/windows/desktop/Tapi/about-call-center-controls)

[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest)

[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest)

## Remarks

> [!NOTE]
> The tapi.h header defines lineCreateAgentSession as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).