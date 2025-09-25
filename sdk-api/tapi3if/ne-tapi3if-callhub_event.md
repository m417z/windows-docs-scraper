# CALLHUB_EVENT enumeration

## Description

The
**CALLHUB_EVENT** enum describes CallHub events. The
[ITCallHubEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallhubevent-get_event) method returns a member of this enum to indicate the type of CallHub event that occurred.

## Constants

### `CHE_CALLJOIN:0`

A new call has joined the CallHub.

### `CHE_CALLLEAVE`

A call has left the CallHub.

### `CHE_CALLHUBNEW`

A new CallHub has appeared.

### `CHE_CALLHUBIDLE`

A CallHub has gone idle.

### `CHE_LASTITEM`

## See also

[ITCallHubEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallhubevent-get_event)