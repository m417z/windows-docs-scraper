# IAudioEndpointVolume::SetMasterVolumeLevelScalar

## Description

The **SetMasterVolumeLevelScalar** method sets the master volume level of the audio stream that enters or leaves the audio endpoint device. The volume level is expressed as a normalized, audio-tapered value in the range from 0.0 to 1.0.

## Parameters

### `fLevel` [in]

The new master volume level. The level is expressed as a normalized value in the range from 0.0 to 1.0.

### `pguidEventContext` [in]

Context value for the [IAudioEndpointVolumeCallback::OnNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolumecallback-onnotify) method. This parameter points to an event-context GUID. If the **SetMasterVolumeLevelScalar** call changes the volume level of the endpoint, all clients that have registered [IAudioEndpointVolumeCallback](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback) interfaces with that endpoint will receive notifications. In its implementation of the **OnNotify** method, a client can inspect the event-context GUID to discover whether it or another client is the source of the volume-change event. If the caller supplies a **NULL** pointer for this parameter, the notification routine receives the context GUID value GUID_NULL.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *fLevel* is outside the range from 0.0 to 1.0. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

The volume level is normalized to the range from 0.0 to 1.0, where 0.0 is the minimum volume level and 1.0 is the maximum level. Within this range, the relationship of the normalized volume level to the attenuation of signal amplitude is described by a nonlinear, audio-tapered curve. Note that the shape of the curve might change in future versions of Windows. For more information about audio-tapered curves, see [Audio-Tapered Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-tapered-volume-controls).

The normalized volume levels that are passed to this method are suitable to represent the positions of volume controls in application windows and on-screen displays.

For a code example that calls **SetMasterVolumeLevelScalar**, see [Endpoint Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/endpoint-volume-controls).

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolumeCallback Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback)

[IAudioEndpointVolumeCallback::OnNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolumecallback-onnotify)