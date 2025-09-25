# IAudioSessionEvents::OnChannelVolumeChanged

## Description

The **OnChannelVolumeChanged** method notifies the client that the volume level of an audio channel in the session submix has changed.

## Parameters

### `ChannelCount` [in]

The channel count. This parameter specifies the number of audio channels in the session submix.

### `NewChannelVolumeArray` [in]

Pointer to an array of volume levels. Each element is a value of type **float** that specifies the volume level for a particular channel. Each volume level is a value in the range 0.0 to 1.0, where 0.0 is silence and 1.0 is full volume (no attenuation). The number of elements in the array is specified by the *ChannelCount* parameter. If an audio stream contains *n* channels, the channels are numbered from 0 to *n*– 1. The array element whose index matches the channel number, contains the volume level for that channel. Assume that the array remains valid only for the duration of the call.

### `ChangedChannel` [in]

The number of the channel whose volume level changed. Use this value as an index into the *NewChannelVolumeArray* array. If the session submix contains *n* channels, the channels are numbered from 0 to *n*– 1. If more than one channel might have changed (for example, as a result of a call to the [IChannelAudioVolume::SetAllVolumes](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setallvolumes) method), the value of *ChangedChannel* is (**DWORD**)(–1).

### `EventContext` [in]

The event context value. This is the same value that the caller passed to the [IChannelAudioVolume::SetChannelVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setchannelvolume) or **IChannelAudioVolume::SetAllVolumes** method in the call that initiated the change in volume level of the channel. For more information, see Remarks.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The session manager calls this method each time a call to the **IChannelAudioVolume::SetChannelVolume** or **IChannelAudioVolume::SetAllVolumes** method successfully updates the volume level of one or more channels in the session submix. Note that the **OnChannelVolumeChanged** call occurs regardless of whether the new channel volume level or levels differ in value from the previous channel volume level or levels.

The *EventContext* parameter provides a means for a client to distinguish between a channel-volume change that it initiated and one that some other client initiated. When calling the **IChannelAudioVolume::SetChannelVolume** or **IChannelAudioVolume::SetAllVolumes** method, a client passes in an *EventContext* parameter value that its implementation of the **OnChannelVolumeChanged** method can recognize.

For a code example that implements the methods in the **IAudioSessionEvents** interface, see [Audio Session Events](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-session-events).

## See also

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)

[IChannelAudioVolume::SetAllVolumes](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setallvolumes)

[IChannelAudioVolume::SetChannelVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-ichannelaudiovolume-setchannelvolume)