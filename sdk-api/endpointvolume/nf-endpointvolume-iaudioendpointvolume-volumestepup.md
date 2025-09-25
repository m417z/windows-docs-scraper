# IAudioEndpointVolume::VolumeStepUp

## Description

The **VolumeStepUp** method increments, by one step, the volume level of the audio stream that enters or leaves the audio endpoint device.

## Parameters

### `pguidEventContext` [in]

Context value for the [IAudioEndpointVolumeCallback::OnNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolumecallback-onnotify) method. This parameter points to an event-context GUID. If the **VolumeStepUp** call changes the volume level of the endpoint, all clients that have registered [IAudioEndpointVolumeCallback](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback) interfaces with that endpoint will receive notifications. In its implementation of the **OnNotify** method, a client can inspect the event-context GUID to discover whether it or another client is the source of the volume-change event. If the caller supplies a **NULL** pointer for this parameter, the client's notification method receives a **NULL** context pointer.

## Return value

If the method succeeds, it returns S_OK. If it fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

To obtain the current volume step and the total number of steps in the volume range, call the [IAudioEndpointVolume::GetVolumeStepInfo](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumestepinfo) method.

If the volume level is already at the highest step in the volume range, the call to **VolumeStepUp** has no effect and returns status code S_OK.

Successive intervals between adjacent steps do not necessarily represent uniform volume increments in either linear signal amplitude or decibels. In Windows Vista, **VolumeStepUp** defines the relationship of step index to volume level (signal amplitude) to be an audio-tapered curve. Note that the shape of the curve might change in future versions of Windows. For more information about audio-tapered curves, see [Audio-Tapered Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-tapered-volume-controls).

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolume::GetVolumeStepInfo](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumestepinfo)

[IAudioEndpointVolumeCallback Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback)

[IAudioEndpointVolumeCallback::OnNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolumecallback-onnotify)