# KSRTAUDIO_NOTIFICATION_EVENT_PROPERTY structure

## Description

The KSRTAUDIO_NOTIFICATION_EVENT_PROPERTY structure appends an event handle to a [KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure) structure

## Members

### `Property`

A KSPROPERTY structure that the client initializes appropriately prior to calling [KSPROPERTY_RTAUDIO_REGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-register-notification-event) or [KSPROPERTY_RTAUDIO_UNREGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-unregister-notification-event).

### `NotificationEvent`

Specifies a user-mode event handle to be registered or unregistered for event notifications.

## Remarks

The KSPROPERTY_RTAUDIO_REGISTER_NOTIFICATION_EVENT and KSPROPERTY_RTAUDIO_UNREGISTER_NOTIFICATION_EVENT property requests use the KSRTAUDIO_NOTIFICATION_EVENT_PROPERTY structure to pass a user-mode event handle from the client to the driver.

The **NotificationEvent** member is a user-mode event handle that, when registered, receives signals as buffer DMA progresses. The notification capability is only available upon a successful call to [KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer-with-notification).

## See also

[KSPROPERTY](https://learn.microsoft.com/windows-hardware/drivers/stream/ksproperty-structure)

[KSPROPERTY_RTAUDIO_BUFFER_WITH_NOTIFICATION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-buffer-with-notification)

[KSPROPERTY_RTAUDIO_REGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-register-notification-event)

**KSPROPERTY_RTAUDIO_UNREGISTER_NOTIFICATION_EVENT**