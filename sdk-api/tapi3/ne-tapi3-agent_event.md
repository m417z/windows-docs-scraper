# AGENT_EVENT enumeration

## Description

The
**AGENT_EVENT** enum describes agent events. The
[ITAgentEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagentevent-get_event) method returns a member of this enum to indicate the type of agent event that occurred.

## Constants

### `AE_NOT_READY:0`

The agent is unable to handle calls.

### `AE_READY`

The agent is able to handle calls.

### `AE_BUSY_ACD`

The agent is active handling an ACD call.

### `AE_BUSY_INCOMING`

The agent is active handling an incoming non-ACD call.

### `AE_BUSY_OUTGOING`

The agent is active handling an outgoing non-ACD call.

### `AE_UNKNOWN`

Unknown state.

## See also

[ITAgentEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagentevent-get_event)

[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent)