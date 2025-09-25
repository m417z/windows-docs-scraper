# ITAgentSession::get_SessionDuration

## Description

The
**get_SessionDuration** method gets the duration of the Agent session in seconds. This duration is for the active period only; timing stops when a session enters the ASST_SESSION_ENDED state of
[AGENT_SESSION_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_session_state).

## Parameters

### `plDuration` [out]

Pointer to session duration.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *plDuration* parameter is not a valid pointer. |
| **LINEERR_** | See [lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo) for error codes returned from this TAPI 2.1 function. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

This method wraps the TAPI 2.1
[lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo) function.

## See also

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)

[lineGetAgentSessionInfo](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linegetagentsessioninfo)