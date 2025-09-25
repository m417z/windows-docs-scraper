# CALL_STATE enumeration

## Description

The
**CALL_STATE** enum is used by the
[ITCallInfo::get_CallState](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callstate) and
[ITCallStateEvent::get_State](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallstateevent-get_state) methods.

## Constants

### `CS_IDLE:0`

The call has been created, but
[Connect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-connect) has not been called yet. A call can never transition into the idle state. This is the initial state for both incoming and outgoing calls.

### `CS_INPROGRESS`

[Connect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-connect) has been called, and the service provider is working on making a connection. This state is valid only on outgoing calls. This message is optional, because a service provider may have a call transition directly to the connected state.

### `CS_CONNECTED`

Call has been connected to the remote end and communication can take place.

### `CS_DISCONNECTED`

Call has been disconnected. There are several causes for disconnection. See the table of valid call state transitions below.

### `CS_OFFERING`

A new call has appeared, and is being offered to an application. If the application has owner privileges on the call, it can either call
[Answer](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-answer) or
[Disconnect](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itbasiccallcontrol-disconnect) while the call is in the offering state. Current call privilege can be determined by calling
[ITCallInfo::get_Privilege](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_privilege).

### `CS_HOLD`

The call is in the hold state.

### `CS_QUEUED`

The call is queued.

### `CS_LASTITEM:CS_QUEUED`

## Remarks

Following is a table of all valid call state transitions.

| From state | To state |
| --- | --- |
| CS_IDLE | INPROGRESS<br><br>CONNECTED<br><br>DISCONNECTED<br><br>OFFERING<br><br>HOLD |
| CS_INPROGRESS | CONNECTED<br><br>DISCONNECTED<br><br>HOLD |
| CS_CONNECTED | HOLD<br><br>DISCONNECTED |
| CS_DISCONNECTED | Nothing—call should be freed |
| CS_OFFERING | CONNECTED<br><br>DISCONNECTED<br><br>HOLD |
| CS_HOLD | CONNECTED<br><br>DISCONNECTED |
| CS_QUEUED | CONNECTED<br><br>DISCONNECTED<br><br>HOLD |

## See also

[ITCallInfo::get_CallState](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallinfo-get_callstate)

[ITCallStateEvent::get_State](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallstateevent-get_state)