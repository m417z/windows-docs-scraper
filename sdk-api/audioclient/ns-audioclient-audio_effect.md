## Description

Represents an audio effect.

## Members

### `id`

The GUID identifier for an audio effect. Audio effect GUIDs are defined in [ksmedia.h](https://learn.microsoft.com/windows-hardware/drivers/audio/ksmedia-h).

### `canSetState`

A boolean value specifying whether the effect state can be modified.

### `state`

A member of the [AUDIO_EFFECT_STATE](https://learn.microsoft.com/windows/win32/api/audioclient/ne-audioclient-audio_effect_state) enumeration specifying the state of the audio effect.

## Remarks

Get a list of **AUDIO_EFFECT** structures by calling [IAudioEffectsManager::GetAudioEffects](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioeffectsmanager-getaudioeffects).

## See also

[IAudioEffectsManager::GetAudioEffects](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioeffectsmanager-getaudioeffects)