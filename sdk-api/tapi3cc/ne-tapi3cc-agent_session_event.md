# AGENT_SESSION_EVENT enumeration

## Description

The
**AGENT_SESSION_EVENT** enum describes agent session events. The
[ITAgentSessionEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagentsessionevent-get_event) method returns a member of this enum to indicate the type of agent session event that occurred.

## Constants

### `ASE_NEW_SESSION:0`

A new agent session has been created.

### `ASE_NOT_READY`

The agent is unable to handle calls for this session.

### `ASE_READY`

The agent is able to handle calls for this session.

### `ASE_BUSY`

The agent is active in this session handling an ACD call.

### `ASE_WRAPUP`

The agent is active in this session handling the wrap-up of an ACD call.

### `ASE_END`

The session has completed.

## See also

[ITAgentSessionEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagentsessionevent-get_event)

[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent)