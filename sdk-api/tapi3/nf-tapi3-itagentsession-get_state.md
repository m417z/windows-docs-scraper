# ITAgentSession::get_State

## Description

The
**get_State** method gets the current state of this session.

## Parameters

### `pSessionState` [out]

Pointer to an
[AGENT_SESSION_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_session_state).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pSessionState* parameter is not a valid pointer. |

## See also

[AGENT_SESSION_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_session_state)

[ITAgentSession](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagentsession)

[put_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagentsession-put_state)