# ITAgent::get_State

## Description

The
**get_State** method gets the state of an agent session.

## Parameters

### `pAgentState` [out]

Pointer to an
[AGENT_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_state).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_POINTER** | The *pAgentState* parameter is not a valid pointer. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |

## See also

[AGENT_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_state)

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[put_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-put_state)