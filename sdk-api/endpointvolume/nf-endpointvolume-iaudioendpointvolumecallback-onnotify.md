# IAudioEndpointVolumeCallback::OnNotify

## Description

The **OnNotify** method notifies the client that the volume level or muting state of the audio endpoint device has changed.

## Parameters

### `pNotify` [in]

Pointer to the volume-notification data. This parameter points to a structure of type [AUDIO_VOLUME_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/endpointvolume/ns-endpointvolume-audio_volume_notification_data).

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The *pNotify* parameter points to a structure that describes the volume change event that initiated the call to **OnNotify**. This structure contains an event-context GUID. This GUID enables a client to distinguish between a volume (or muting) change that it initiated and one that some other client initiated. When calling an [IAudioEndpointVolume](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume) method that changes the volume level of the stream, a client passes in a pointer to an event-context GUID that its implementation of the **OnNotify** method can recognize. The structure pointed to by *pNotify* contains this context GUID. If the client that changes the volume level supplies a **NULL** pointer value for the pointer to the event-context GUID, the value of the event-context GUID in the structure pointed to by *pNotify* is GUID_NULL.

The Windows 7, the system's volume user interface does not specify GUID_NULL when it changes the volume in the system. A third-party OSD application can differentiate between master volume control changes that result from the system's volume user interface, and other volume changes such as changes from the built-in volume control handler.

For a code example that implements the **OnNotify** method, see [Endpoint Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-volume-controls).

## See also

[AUDIO_VOLUME_NOTIFICATION_DATA](https://learn.microsoft.com/windows/desktop/api/endpointvolume/ns-endpointvolume-audio_volume_notification_data)

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolumeCallback Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback)