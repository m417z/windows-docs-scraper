# IAudioSessionEvents::OnSimpleVolumeChanged

## Description

The **OnSimpleVolumeChanged** method notifies the client that the volume level or muting state of the audio session has changed.

## Parameters

### `NewVolume` [in]

The new volume level for the audio session. This parameter is a value in the range 0.0 to 1.0, where 0.0 is silence and 1.0 is full volume (no attenuation).

### `NewMute` [in]

The new muting state. If **TRUE**, muting is enabled. If **FALSE**, muting is disabled.

### `EventContext` [in]

The event context value. This is the same value that the caller passed to [ISimpleAudioVolume::SetMasterVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmastervolume) or [ISimpleAudioVolume::SetMute](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmute) in the call that changed the volume level or muting state of the session. For more information, see Remarks.

## Return value

If the method succeeds, it returns S_OK. If it fails, it returns an error code.

## Remarks

The session manager calls this method each time a call to the [ISimpleAudioVolume::SetMasterVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmastervolume) or [ISimpleAudioVolume::SetMute](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmute) method changes the volume level or muting state of the session.

The *EventContext* parameter provides a means for a client to distinguish between a volume or mute change that it initiated and one that some other client initiated. When calling the [ISimpleAudioVolume::SetMasterVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmastervolume) or [ISimpleAudioVolume::SetMute](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmute) method, a client passes in an *EventContext* parameter value that its implementation of the **OnSimpleVolumeChanged** method can recognize.

For a code example that implements the methods in the [IAudioSessionEvents](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents) interface, see [Audio Session Events](https://learn.microsoft.com/windows/desktop/CoreAudio/audio-session-events).

## See also

[IAudioSessionEvents Interface](https://learn.microsoft.com/windows/desktop/api/audiopolicy/nn-audiopolicy-iaudiosessionevents)

[ISimpleAudioVolume::SetMasterVolume](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmastervolume)

[ISimpleAudioVolume::SetMute](https://learn.microsoft.com/windows/desktop/api/audioclient/nf-audioclient-isimpleaudiovolume-setmute)