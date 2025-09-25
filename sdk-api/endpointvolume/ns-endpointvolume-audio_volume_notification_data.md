# AUDIO_VOLUME_NOTIFICATION_DATA structure

## Description

The **AUDIO_VOLUME_NOTIFICATION_DATA** structure describes a change in the volume level or muting state of an audio endpoint device.

## Members

### `guidEventContext`

Context value for the [IAudioEndpointVolumeCallback::OnNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolumecallback-onnotify) method. This member is the value of the event-context GUID that was provided as an input parameter to the [IAudioEndpointVolume](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume) method call that changed the endpoint volume level or muting state. For more information, see Remarks.

### `bMuted`

Specifies whether the audio stream is currently muted. If **bMuted** is **TRUE**, the stream is muted. If **FALSE**, the stream is not muted.

### `fMasterVolume`

Specifies the current master volume level of the audio stream. The volume level is normalized to the range from 0.0 to 1.0, where 0.0 is the minimum volume level and 1.0 is the maximum level. Within this range, the relationship of the normalized volume level to the attenuation of signal amplitude is described by a nonlinear, audio-tapered curve. For more information about audio tapers, see [Audio-Tapered Volume Controls](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-tapered-volume-controls).

### `nChannels`

Specifies the number of channels in the audio stream, which is also the number of elements in the **afChannelVolumes** array. If the audio stream contains *n* channels, the channels are numbered from 0 to *n*-1. The volume level for a particular channel is contained in the array element whose index matches the channel number.

### `afChannelVolumes`

The first element in an array of channel volumes. This element contains the current volume level of channel 0 in the audio stream. If the audio stream contains more than one channel, the volume levels for the additional channels immediately follow the **AUDIO_VOLUME_NOTIFICATION_DATA** structure. The volume level for each channel is normalized to the range from 0.0 to 1.0, where 0.0 is the minimum volume level and 1.0 is the maximum level. Within this range, the relationship of the normalized volume level to the attenuation of signal amplitude is described by a nonlinear, audio-tapered curve.

## Remarks

This structure is used by the **IAudioEndpointVolumeCallback::OnNotify** method.

A client can register to be notified when the volume level or muting state of an endpoint device changes. The following methods can cause such a change:

* [IAudioEndpointVolume::SetChannelVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setchannelvolumelevel)
* [IAudioEndpointVolume::SetChannelVolumeLevelScalar](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setchannelvolumelevelscalar)
* [IAudioEndpointVolume::SetMasterVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setmastervolumelevel)
* [IAudioEndpointVolume::SetMasterVolumeLevelScalar](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setmastervolumelevelscalar)
* [IAudioEndpointVolume::SetMute](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setmute)
* [IAudioEndpointVolume::VolumeStepDown](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepdown)
* [IAudioEndpointVolume::VolumeStepUp](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepup)

When a call to one of these methods causes a volume-change event (that is, a change in the volume level or muting state), the method sends notifications to all clients that have registered to receive them. The method notifies a client by calling the client's **IAudioEndpointVolumeCallback::OnNotify** method. Through the **OnNotify** call, the client receives a pointer to an **AUDIO_VOLUME_NOTIFICATION_DATA** structure that describes the change.

Each of the methods in the preceding list accepts an input parameter named *pguidEventContext*, which is a pointer to an event-context GUID. Before sending notifications to clients, the method copies the event-context GUID pointed to by *pguidEventContext* into the **guidEventContext** member of the **AUDIO_VOLUME_NOTIFICATION_DATA** structure that it supplies to clients through their **OnNotify** methods. If *pguidEventContext* is **NULL**, the value of the **guidEventContext** member is set to GUID_NULL.

In its implementation of the **OnNotify** method, a client can inspect the event-context GUID from that call to discover whether it or another client is the source of the volume-change event.

## See also

[Core Audio Structures](https://learn.microsoft.com/windows/desktop/CoreAudio/core-audio-structures)

[IAudioEndpointVolume Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolume)

[IAudioEndpointVolume::SetChannelVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setchannelvolumelevel)

[IAudioEndpointVolume::SetChannelVolumeLevelScalar](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setchannelvolumelevelscalar)

[IAudioEndpointVolume::SetMasterVolumeLevel](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setmastervolumelevel)

[IAudioEndpointVolume::SetMasterVolumeLevelScalar](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setmastervolumelevelscalar)

[IAudioEndpointVolume::SetMute](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-setmute)

[IAudioEndpointVolume::VolumeStepDown](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepdown)

[IAudioEndpointVolume::VolumeStepUp](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolume-volumestepup)

[IAudioEndpointVolumeCallback Interface](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nn-endpointvolume-iaudioendpointvolumecallback)

[IAudioEndpointVolumeCallback::OnNotify](https://learn.microsoft.com/windows/desktop/api/endpointvolume/nf-endpointvolume-iaudioendpointvolumecallback-onnotify)