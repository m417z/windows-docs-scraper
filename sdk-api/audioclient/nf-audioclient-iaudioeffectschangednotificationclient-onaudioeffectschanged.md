## Description

Called by the system when the list of audio effects changes or the resources needed to enable an effect changes, i.e. when the value of the *canSetState* field of the associated [AUDIO_EFFECT](https://learn.microsoft.com/windows/win32/api/audioclient/ns-audioclient-audio_effect) changes.

## Return value

An HRESULT.

## Remarks

Register the callback interface by calling [IAudioEffectsManager::RegisterAudioEffectsChangedNotificationCallback](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioeffectsmanager-registeraudioeffectschangednotificationcallback).

## Example

The following code example demonstrates a class that implements [IAudioEffectsChangedNotificationClient](https://learn.microsoft.com/windows/win32/api/audioclient/nn-audioclient-iaudioeffectschangednotificationclient) to receive notifications when the list of audio effects changes or the resources needed to enable an effect changes. In the **OnAudioStreamEffectsChanged** callback, the example calls [GetAudioEffects](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioeffectsmanager-getaudioeffects) to get the current list of effects.

```cpp
class AudioEffectsChangedHandler :
    public winrt::implements<AudioEffectsChangedHandler, IAudioEffectsChangedNotificationClient>
{

    public:
    AudioEffectsChangedHandler(_In_ IAudioClient *client) : m_client(client){}
    STDMETHOD(OnAudioEffectsChanged)()
    {
        OnAudioStreamEffectsChanged(m_client.get());
        return S_OK;
    }
    private:
    wil::com_ptr_nothrow<IAudioClient> m_client;

};

wil::com_ptr_nothrow<IAudioEffectsChangedNotificationClient> g_effectsChangedHandler;

HRESULT RegisterAudioStreamEffectsChangedEvent(_In_ IAudioClient *client)
{
    if (!g_effectsChangedHandler)
    {
        wil::com_ptr_nothrow<IAudioEffectsManager> audioEffectsManager;
        RETURN_IF_FAILED(client->GetService(IID_PPV_ARGS(&audioEffectsManager)));

        // Register for the audio effects changed notification
        g_effectsChangedHandler = winrt::make<AudioEffectsChangedHandler>(client).get();
        RETURN_IF_NULL_ALLOC(g_effectsChangedHandler);

        return audioEffectsManager->RegisterAudioEffectsChangedNotificationCallback(
            g_effectsChangedHandler.get());
    }
    return S_OK;
}

HRESULT UnregisterAudioStreamEffectsChangedEvent(_In_ IAudioClient *client)
{
    if (g_effectsChangedHandler != nullptr)
    {
        wil::com_ptr_nothrow<IAudioEffectsManager> audioEffectsManager;
        RETURN_IF_FAILED(client->GetService(IID_PPV_ARGS(&audioEffectsManager)));

        // Unregister from the audio effects changed notification
        return audioEffectsManager->UnregisterAudioEffectsChangedNotificationCallback(
            g_effectsChangedHandler.get());
        }

        return S_OK;
}

HRESULT OnAudioStreamEffectsChanged(_In_ IAudioClient *client)
{
    // Re-query the list of effects since there was some change
    wil::com_ptr_nothrow<IAudioEffectsManager> audioEffectsManager;
    RETURN_IF_FAILED(client->GetService(IID_PPV_ARGS(&audioEffectsManager)));
    wil::unique_cotaskmem_array_ptr<AUDIO_EFFECT> effects;
    UINT32 numEffects;
    RETURN_IF_FAILED(audioEffectsManager->GetAudioEffects(&effects, &numEffects));

    for (UINT32 i = 0; i < numEffects; i++)
    {

        // Here the app can check which effects are still enabled, and check if there are new
        // effects that now can be enabled.
        // As an example, the following code enables any effect that can be enabled, if it is not
        // already enabled.
        if (effects[i].canSetState && effects[i].state == AUDIO_EFFECT_STATE_OFF)
        {
            HRESULT hr = audioEffectsManager->SetAudioEffectState(effects[i].id, AUDIO_EFFECT_STATE_ON));
            if (hr == AUDCLNT_E_EFFECT_NOT_AVAILABLE || hr == AUDCLNT_E_EFFECT_STATE_READ_ONLY)
            {
                hr = S_OK;
            }
            RETURN_IF_FAILED(hr);

        }
    }

    return S_OK;
}
```

## See also