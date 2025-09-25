# AGENTHANDLER_EVENT enumeration

## Description

The
**AGENTHANDLER_EVENT** enum describes agent handler events. The
[ITAgentHandlerEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandlerevent-get_event) method returns a member of this enum to indicate the type of agent handler event that occurred.

## Constants

### `AHE_NEW_AGENTHANDLER:0`

A new AgentHandler object has been added.

### `AHE_AGENTHANDLER_REMOVED`

An AgentHandler object has been removed.

## See also

[ITAgentHandlerEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itagenthandlerevent-get_event)

[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent)