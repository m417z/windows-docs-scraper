# ITCallNotificationEvent::get_Event

## Description

The
**get_Event** method returns a
[CALL_NOTIFICATION_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_notification_event) description of whether the application owns or is monitoring the call on which the event has occurred.

## Parameters

### `pCallNotificationEvent` [out]

Pointer to the
[CALL_NOTIFICATION_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_notification_event) description of the application's privilege on the call returned by
[ITCallNotificationEvent::get_Call](https://learn.microsoft.com/windows/desktop/api/tapi3if/nf-tapi3if-itcallnotificationevent-get_call).

## Return value

This method can return one of these values.

| Value | Meaning |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_OUTOFMEMORY** | Insufficient memory exists to perform the operation. |
| **E_POINTER** | The *pCallNotificationEvent* parameter is not a valid pointer. |

## See also

[CALL_NOTIFICATION_EVENT](https://learn.microsoft.com/windows/desktop/api/tapi3if/ne-tapi3if-call_notification_event)

[Call Object](https://learn.microsoft.com/windows/desktop/Tapi/call-object)

[ITCallNotificationEvent](https://learn.microsoft.com/windows/desktop/api/tapi3if/nn-tapi3if-itcallnotificationevent)