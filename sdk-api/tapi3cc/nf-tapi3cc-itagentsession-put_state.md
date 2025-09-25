# ITAgentSession::put_State

## Description

The
**put_State** method sets the state of the agent session.

## Parameters

### `SessionState` [in]

[AGENT_SESSION_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_session_state).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_INVALIDARG** | The *SessionState* parameter is not a valid session state. |
| **LINEERR_** | See [lineSetAgentSessionState](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentstate) for error codes returned from this TAPI 2.1 function. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

This method wraps the TAPI 2.1
[lineSetAgentSessionState](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentstate) function.

## See also

[AGENT_SESSION_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_session_state)

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)

[get_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagentsession-get_state)

[lineSetAgentSessionState](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentstate)