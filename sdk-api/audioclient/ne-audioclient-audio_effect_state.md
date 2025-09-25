## Description

Specifies the state of an audio effect.

## Constants

### `AUDIO_EFFECT_STATE_OFF`

The audio effect is off.

### `AUDIO_EFFECT_STATE_ON`

The audio effect is on.

## Remarks

Get the state of an audio effect by calling [IAudioEffectsManager::GetAudioEffects](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioeffectsmanager-getaudioeffects) and checking the *state* field of the returned [AUDIO_EFFECT](https://learn.microsoft.com/windows/win32/api/audioclient/ns-audioclient-audio_effect) structures.

Set the state of an audio effect by calling [IAudioEffectsManager::SetAudioEffectState](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioeffectsmanager-setaudioeffectstate).

## See also

[IAudioEffectsManager::GetAudioEffects](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioeffectsmanager-getaudioeffects)

[IAudioEffectsManager::SetAudioEffectState](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioeffectsmanager-setaudioeffectstate)

[AUDIO_EFFECT](https://learn.microsoft.com/windows/win32/api/audioclient/ns-audioclient-audio_effect)