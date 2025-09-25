## Description

Gets the current list of audio effects for the associated audio stream.

## Parameters

### `effects`

Receives a pointer to an array of [AUDIO_EFFECT](https://learn.microsoft.com/windows/win32/api/audioclient/ns-audioclient-audio_effect) structures representing the current list of audio effects.

### `numEffects`

Receives the number of **AUDIO_EFFECT** structures returned in *effects*.

## Return value

Returns an HRESULT including but not limited to the following.

| Value | Description |
|-------|-------------|
| S_OK | Success |
| AUDCLNT_E_DEVICE_INVALIDATED | The associated audio stream has been destroyed. |

## Remarks

The caller is responsible for freeing the array using [CoTaskMemFree](https://learn.microsoft.com/windows/win32/api/combaseapi/nf-combaseapi-cotaskmemfree).

Register an **IAudioEffectsChangedNotificationClient** to receive notifications when the list of audio effects changes.

## Examples

The following example demonstrates using **IAudioEffectsManager.GetAudioEffects** to detect whether the [AUDIO_EFFECT_TYPE_DEEP_NOISE_SUPPRESSION](https://learn.microsoft.com/windows-hardware/drivers/audio/audio-signal-processing-modes#clsids-for-system-effects) effect is present on the specified audio stream.

```cpp
HRESULT IsPlatformDeepNoiseSuppressionPresent(_In_ IAudioClient *client, _Out_ bool *isPresent)
{
    *isPresent = false;
    wil::com_ptr_nothrow<IAudioEffectsManager> audioEffectsManager;
    RETURN_IF_FAILED(client->GetService(IID_PPV_ARGS(&audioEffectsManager)));
    wil::unique_cotaskmem_array_ptr<AUDIO_EFFECT> effects;
    UINT32 numEffects;
    RETURN_IF_FAILED(audioEffectsManager->GetAudioEffects(&effects, &numEffects));

    for (UINT32 i = 0; i < numEffects; i++)
    {
        // Check if noise suppression is part of the current effects
        if (effects[i].id == AUDIO_EFFECT_TYPE_DEEP_NOISE_SUPPRESSION)
        {
            *isPresent = true;
            return S_OK;
        }
    }

    return S_OK;
}
```

## See also

[AUDIO_EFFECT](https://learn.microsoft.com/windows/win32/api/audioclient/ns-audioclient-audio_effect)
[IAudioEffectsChangedNotificationClient](https://learn.microsoft.com/windows/win32/api/audioclient/nn-audioclient-iaudioeffectschangednotificationclient)