# ACDQUEUE_EVENT enumeration

## Description

The
**ACDQUEUE_EVENT** enum describes ACD queue events. The
[ITQueueEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itqueueevent-get_event) method returns a member of this enum to indicate the type of ACD queue event that occurred.

## Constants

### `ACDQE_NEW_QUEUE:0`

A new ACD queue has been added.

### `ACDQE_QUEUE_REMOVED`

An ACD queue has been removed.

## See also

[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent)

[ITCallNotificationEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallnotificationevent-get_event)

[ITQueueEvent::get_Event](https://learn.microsoft.com/windows/desktop/api/tapi3/nf-tapi3-itqueueevent-get_event)