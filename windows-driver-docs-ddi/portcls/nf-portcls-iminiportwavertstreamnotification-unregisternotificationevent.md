# IMiniportWaveRTStreamNotification::UnregisterNotificationEvent

## Description

The `UnregisterNotificationEvent` method unregisters an event from DMA driven event notification.

## Parameters

### `NotificationEvent` [in]

A pointer to a previously registered kernel event (PKEVENT) to be unregistered from notification as DMA progresses.

## Return value

`UnregisterNotificationEvent` returns a status value of STATUS_SUCCESS if the call was successful. Otherwise, the method returns an appropriate error status code.

## Remarks

The port driver calls this method in response to a [KSPROPERTY_RTAUDIO_UNREGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-unregister-notification-event) property request from a client. The port driver maps the user-mode event handle to a kernel event pointer and passes the pointer in with the *NotificationEvent* parameter.

## See also

[IMiniportWaveRTStreamNotification](https://learn.microsoft.com/windows-hardware/drivers/ddi/portcls/nn-portcls-iminiportwavertstreamnotification)

[KSPROPERTY_RTAUDIO_UNREGISTER_NOTIFICATION_EVENT](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-rtaudio-unregister-notification-event)