## Description

Sets the state of the specified audio effect.

## Parameters

### `effectId`

The GUID identifier of the effect for which the state is being changed. Audio effect GUIDs are defined in [ksmedia.h](https://learn.microsoft.com/windows-hardware/drivers/audio/ksmedia-h).

### `state`

A value from the [AUDIO_EFFECT_STATE](https://learn.microsoft.com/windows/win32/api/audioclient/ne-audioclient-audio_effect_state) enumerating specifying the state to set.

## Return value

Returns an HRESULT including but not limited to the following.

| Value | Description |
|-------|-------------|
| S_OK | Success |
| AUDCLNT_E_EFFECT_NOT_AVAILABLE | The specified effect is not available |
| AUDCLNT_E_EFFECT_STATE_READ_ONLY | The specified effect has a state that is read-only |
| AUDCLNT_E_DEVICE_INVALIDATED | The associated audio stream has been destroyed. |

## Remarks

Get the current list of audio effects for the associated audio stream by calling [GetAudioEffects](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioeffectsmanager-getaudioeffects).

## Examples

The following example demonstrates using **IAudioEffectsManager.SetAudioEffectState** to disable the **AUDIO_EFFECT_TYPE_DEEP_NOISE_SUPPRESSION** effect.

```cpp
HRESULT TryDisablePlatformDeepNoiseSuppression(_In_ IAudioClient *client)
{
    wil::com_ptr_nothrow<IAudioEffectsManager> audioEffectsManager;
    RETURN_IF_FAILED(client->GetService(IID_PPV_ARGS(&audioEffectsManager)));
    wil::unique_cotaskmem_array_ptr<AudioEffect> effects;
    UINT32 numEffects;
    RETURN_IF_FAILED(audioEffectsManager->GetAudioEffects(&effects, &numEffects));

    for (UINT32 i = 0; i < numEffects; i++)
    {
        if (effects[i].id == AUDIO_EFFECT_TYPE_DEEP_NOISE_SUPPRESSION)
        {
            // Check if deep noise suppression can be set and if it is currently on
            if (effects[i].canSetState && effects[i].state == AUDIO_EFFECT_STATE_ON)
            {
                HRESULT hr = audioEffectsManager->SetAudioEffectState(effects[i].id, AUDIO_EFFECT_STATE_OFF);

                // If canSetState changed to false, or the effect was removed, SetAudioEffectState
                // can fail with one of the following error codes.
                if (hr != AUDCLNT_E_EFFECT_NOT_AVAILABLE && hr != AUDCLNT_E_EFFECT_STATE_READ_ONLY)
                {
                    return hr;
                }
            }

            return S_OK;
        }
    }

    return S_OK;
}
```

The following example demonstrates using **IAudioEffectsManager.SetAudioEffectState** to enable the **AUDIO_EFFECT_TYPE_DEEP_NOISE_SUPPRESSION** effect.

```cpp
HRESULT TryEnablePlatformDeepNoiseSuppression(_In_ IAudioClient *client)
{
    wil::com_ptr_nothrow<IAudioEffectsManager> audioEffectsManager;
    RETURN_IF_FAILED(client->GetService(IID_PPV_ARGS(&audioEffectsManager)));
    wil::unique_cotaskmem_array_ptr<AUDIO_EFFECT> effects;
    UINT32 numEffects;
    RETURN_IF_FAILED(audioEffectsManager->GetAudioEffects(&effects, &numEffects));

    for (UINT32 i = 0; i < numEffects; i++)
    {
        if (effects[i].id == AUDIO_EFFECT_TYPE_DEEP_NOISE_SUPPRESSION)
        {
            // Check if deep noise suppression can be set and if it is currently off
            if (effects[i].canSetState && effects[i].state == AUDIO_EFFECT_STATE_OFF)
            {
                HRESULT hr = audioEffectsManager->SetAudioEffectState(effects[i].id, AUDIO_EFFECT_STATE_ON);

                // If canSetState changed to false, or the effect was removed, SetAudioEffectState
                // can fail with one of the following error codes.
                if (hr != AUDCLNT_E_EFFECT_NOT_AVAILABLE && hr != AUDCLNT_E_EFFECT_STATE_READ_ONLY)
                {
                    return hr;
                }
            }

            return S_OK;
        }
        }

        return S_OK;
}
```

## See also