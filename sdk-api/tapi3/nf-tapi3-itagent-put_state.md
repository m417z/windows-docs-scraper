# ITAgent::put_State

## Description

The
**put_State** method sets the state of an agent session.

## Parameters

### `AgentState` [in]

[AGENT_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_state).

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_INVALIDARG** | Agent session state is incorrect. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **TAPI_E_TIMEOUT** | The operation failed because the TAPI 3 DLL timed it out. The timeout interval is two minutes. |

## Remarks

The **ITAgent::put_State** method is a COM wrapper for the TAPI 2.1
[lineSetAgentStateEx](https://learn.microsoft.com/windows/desktop/api/tapi/nf-tapi-linesetagentstateex) function.

## See also

[AGENT_STATE](https://learn.microsoft.com/windows/desktop/api/tapi3/ne-tapi3-agent_state)

[ITAgent](https://learn.microsoft.com/windows/desktop/api/tapi3/nn-tapi3-itagent)

[get_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-get_state)