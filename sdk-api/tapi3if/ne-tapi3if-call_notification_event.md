# CALL_NOTIFICATION_EVENT enumeration

## Description

The
**CALL_NOTIFICATION_EVENT** enum describes call notification events. The
[ITCallNotificationEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallnotificationevent-get_event) method returns a member of this enum to indicate the type of call notification event that occurred.

## Constants

### `CNE_OWNER:0`

The current application owns the call on which the event occurred.

### `CNE_MONITOR`

The current application is monitoring the call on which the event occurred.

### `CNE_LASTITEM`

## See also

[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent)

[ITCallNotificationEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallnotificationevent-get_event)