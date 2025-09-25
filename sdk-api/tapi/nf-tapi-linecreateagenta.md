# lineCreateAgentA function

## Description

The
**lineCreateAgent** function creates a new Agent object. It generates a
[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest) message to be sent to a registered proxy function handler, referencing a
[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest) structure of type LINEPROXYREQUEST_CREATEAGENT.

## Parameters

### `hLine`

Handle to the line device.

### `lpszAgentID`

Pointer to a **null**-terminated Unicode string containing the agent identifier. Used when working with legacy ACD systems. With an ACD system that uses the operating system's user login for authentication, *lpszAgentID* is set to **NULL**.

### `lpszAgentPIN`

Pointer to a **null**-terminated Unicode string containing the agent PIN or password. Used when working with legacy ACD systems. With an ACD system that uses the operating system's user login for authentication, *lpszAgentPIN* is set to **NULL**.

### `lphAgent`

Handle to the created agent, returned by the ACD proxy. It is the responsibility of the agent handler proxy application to generate and maintain uniqueness of this identifier.

## Return value

Returns a request identifier if the asynchronous operation starts; otherwise, the function returns one of the following error values:

LINEERR_INVALLINEHANDLE, LINEERR_INVALPARAM, LINEERR_NOMEM, LINEERR_OPERATIONFAILED, LINEERR_OPERATIONUNAVAIL, LINEERR_RESOURCEUNAVAIL, LINEERR_UNINITIALIZED.

## See also

[LINEPROXYREQUEST](https://learn.microsoft.com/windows/desktop/api/tapi/ns-tapi-lineproxyrequest)

[LINE_PROXYREQUEST](https://learn.microsoft.com/windows/desktop/Tapi/line-proxyrequest)

## Remarks

> [!NOTE]
> The tapi.h header defines lineCreateAgent as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).