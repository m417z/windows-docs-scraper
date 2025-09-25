# CALL_STATE_EVENT_CAUSE enumeration

## Description

The
**CALL_STATE_EVENT_CAUSE** enum is returned by the
[ITCallStateEvent::get_Cause](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallstateevent-get_cause) method.

## Constants

### `CEC_NONE:0`

No call event has occurred.

### `CEC_DISCONNECT_NORMAL`

The call was disconnected as part of the normal life cycle of the call (that is, the call was over, so it was disconnected).

### `CEC_DISCONNECT_BUSY`

An outgoing call failed to connect because the remote end was busy.

### `CEC_DISCONNECT_BADADDRESS`

An outgoing call failed because the destination address was bad.

### `CEC_DISCONNECT_NOANSWER`

An outgoing call failed because the remote end was not answered.

### `CEC_DISCONNECT_CANCELLED`

An outgoing call failed because the caller disconnected.

### `CEC_DISCONNECT_REJECTED`

The outgoing call was rejected by the remote end.

### `CEC_DISCONNECT_FAILED`

The call failed to connect for some other reason.

### `CEC_DISCONNECT_BLOCKED`

## See also

[ITCallStateEvent::get_Cause](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallstateevent-get_cause)