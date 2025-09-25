# AGENT_STATE enumeration

## Description

The
**AGENT_STATE** enum is used by the
[ITAgent::put_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-put_state) and
[ITAgent::get_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-get_state) methods to describe the agent state.

## Constants

### `AS_NOT_READY:0`

Agent is not ready

### `AS_READY`

Agent is ready

### `AS_BUSY_ACD`

Agent is busy with an ACD call.

### `AS_BUSY_INCOMING`

Agent has a call incoming.

### `AS_BUSY_OUTGOING`

Agent has a call that is outgoing.

### `AS_UNKNOWN`

Agent state unknown.

## See also

[ITAgent::get_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-get_state)

[ITAgent::put_State](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagent-put_state)