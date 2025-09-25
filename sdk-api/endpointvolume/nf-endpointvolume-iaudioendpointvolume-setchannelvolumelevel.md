# IAudioEndpointVolume::SetChannelVolumeLevel

## Description

The **SetChannelVolumeLevel** method sets the volume level, in decibels, of the specified channel of the audio stream that enters or leaves the audio endpoint device.

## Parameters

### `nChannel` [in]

The channel number. If the audio stream contains *n* channels, the channels are numbered from 0 to *n*– 1. To obtain the number of channels, call the [IAudioEndpointVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getchannelcount) method.

### `fLevelDB` [in]

The new volume level in decibels. To obtain the range and granularity of the volume levels that can be set by this method, call the [IAudioEndpointVolume::GetVolumeRange](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumerange) method.

### `pguidEventContext` [in]

Context value for the [IAudioEndpointVolumeCallback::OnNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolumecallback-onnotify) method. This parameter points to an event-context GUID. If the **SetChannelVolumeLevel** call changes the volume level of the endpoint, all clients that have registered [IAudioEndpointVolumeCallback](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback) interfaces with that endpoint will receive notifications. In its implementation of the **OnNotify** method, a client can inspect the event-context GUID to discover whether it or another client is the source of the volume-change event. If the caller supplies a **NULL** pointer for this parameter, the notification routine receives the context GUID value GUID_NULL.

## Return value

If the method succeeds, it returns S_OK. If the method fails, possible return codes include, but are not limited to, the values shown in the following table.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Parameter *nChannel* is greater than or equal to the number of channels in the stream; or parameter *fLevelDB* lies outside of the volume range supported by the device. |
| **E_OUTOFMEMORY** | Out of memory. |

## Remarks

If volume level *fLevelDB* falls outside of the volume range reported by the **IAudioEndpointVolume::GetVolumeRange** method, the **SetChannelVolumeLevel** call fails and returns error code E_INVALIDARG.

## See also

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolume::GetChannelCount](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getchannelcount)

[IAudioEndpointVolume::GetVolumeRange](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-getvolumerange)

[IAudioEndpointVolumeCallback Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback)

[IAudioEndpointVolumeCallback::OnNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolumecallback-onnotify)