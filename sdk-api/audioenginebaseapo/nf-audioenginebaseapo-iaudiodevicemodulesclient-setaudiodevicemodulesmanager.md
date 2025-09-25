## Description

Called by the system to pass an instance of [AudioDeviceModulesManager](https://learn.microsoft.com/uwp/api/windows.media.devices.audiodevicemodulesmanager) to Audio Processing Objects (APOs) that implement the [IAudioDeviceModulesClient](https://learn.microsoft.com/windows/win32/api/audioenginebaseapo/nn-audioenginebaseapo-iaudiodevicemodulesclient) interface.

## Parameters

### `pAudioDeviceModulesManager`

An **IUnknown** interface representing the **IAudioDeviceModulesManager**.

## Return value

An HRESULT.

## Remarks

The following code example illustrates an implementation of **IAudioDeviceModulesClient**.

```cpp
STDMETHODIMP CTestModuleAPO::SetAudioDeviceModulesManager(_In_ IUnknown* pAudioDeviceModulesManager)
{
    HRESULT hr = S_OK;
    CComQIPtr<Windows::Media::Devices::IAudioDeviceModulesManager> spModuleManager = pAudioDeviceModulesManager;
    ComPtr<IVectorView<AudioDeviceModule *>> spModules;

    // Cache the audio modules manager for later use within the apo
    m_AudioModulesManager = pAudioDeviceModulesManager;

    // Search the audio modules for a known module
    hr = m_pAudioDeviceModulesMgr->FindAllById(KNOWN_MODULE_ID, &spModules);

    if (SUCCEEDED(hr))
    {
        // do something with the module(s) returned or cache them for later usage
        m_KnownModules = spModules;
    }

    return hr;
}

```

## See also