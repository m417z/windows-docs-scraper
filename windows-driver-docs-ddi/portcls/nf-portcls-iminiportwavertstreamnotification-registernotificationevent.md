# IMiniportWaveRTStreamNotification::RegisterNotificationEvent

## Description

The `RegisterNotificationEvent` method registers an event to be notified for DMA-driven event notification.

## Parameters

### `NotificationEvent` [in]

A pointer to a kernel event (PKEVENT) to be registered for notification as DMA progresses.

## Return value

`RegisterNotificationEvent` returns a status value of STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error status code.

## Remarks

The port driver calls this method in response to a [KSPROPERTY_RTAUDIO_REGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-register-notification-event) property request from a client. The port driver maps the user-mode event handle to a kernel event pointer and passes the pointer in with the *NotificationEvent* parameter.

Typically, when DMA-driven event notification is enabled, the DMA hardware is programmed to generate hardware interrupts at the intended notification points in the cyclic audio buffer. When the driver interrupt service routine (ISR) detects this interrupt, it queues a deferred procedure call (DPC). The DPC, in turn, signals each registered event. We recommend using a try/except construct around the event that signals the call.

For more information about the behavior of the KSPROPERTY_RTAUDIO_REGISTER_NOTIFICATION_EVENT property, see the [KSRTAUDIO_NOTIFICATION_EVENT_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksrtaudio_notification_event_property).

## See also

[IMiniportWaveRTStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstreamnotification)

[KSPROPERTY_RTAUDIO_REGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-register-notification-event)

[KSRTAUDIO_NOTIFICATION_EVENT_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksrtaudio_notification_event_property)