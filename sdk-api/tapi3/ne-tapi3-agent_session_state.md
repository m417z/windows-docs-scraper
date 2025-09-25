# AGENT_SESSION_STATE enumeration

## Description

This
**AGENT_SESSION_STATE** enum defines the agent session indicators used by the
[ITAgentSession::get_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagentsession-get_state) and the
[ITAgentSession::put_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagentsession-put_state) methods.

## Constants

### `ASST_NOT_READY:0`

The agent is unable to handle calls for this session.

### `ASST_READY`

The agent is able to handle calls for this session.

### `ASST_BUSY_ON_CALL`

The agent is active in this session handling an ACD call.

### `ASST_BUSY_WRAPUP`

The agent is active in this session handling the wrap-up of an ACD call.

### `ASST_SESSION_ENDED`

The session has completed.

## Remarks

Following is a table of all valid AgentSession state transitions.

| From state | To state |
| --- | --- |
| ASST_NOT_READY | ASST_READY<br><br>ASST_SESSION_ENDED |
| ASST_READY | ASST_BUSY_ON_CALL<br><br>ASST_NOT_READY<br><br>ASST_SESSION_ENDED |
| ASST_BUSY_ON_CALL | ASST_BUSY_WRAPUP<br><br>ASST_READY<br><br>ASST_NOT_READY<br><br>ASST_SESSION_ENDED |
| ASST_BUSY_WRAPUP | ASST_READY<br><br>ASST_NOT_READY<br><br>ASST_SESSION_ENDED |

## See also

[ITAgentSession::get_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagentsession-get_state)

[ITAgentSession::put_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagentsession-put_state)