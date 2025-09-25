## Description

Associates the specified [HWND](https://docs.microsoft.com/en-us/windows/win32/winprog/windows-data-types) window handle with an audio stream.

## Parameters

### `hwnd`

The [HWND](https://docs.microsoft.com/en-us/windows/win32/winprog/windows-data-types) with which the audio stream wll be associated.

## Return value

## Remarks

An app can choose to associate audio streams with a particular window of their app for proper audio location representation in a Mixed Reality scenario

Get an instance of the [IAudioViewManagerService](https://learn.microsoft.com/windows/win32/api/audioclient/nn-audioclient-iaudioviewmanagerservice) by calling [GetService](https://learn.microsoft.com/windows/win32/api/audioclient/nf-audioclient-iaudioclient-getservice) on the [IAudioClient](https://learn.microsoft.com/windows/win32/api/audioclient/nn-audioclient-iaudioclient) instance representing the stream you want to associate a window with. The following code example illustrates creating an audio stream on the default audio render endpoint and associating it with an **HWND**.

```cpp
#include <audioclient.h>

HRESULT CreateAudioStreamAndAttachToHwnd(_In_ HWND hwnd, _Out_ IAudioClient **audioStream)
{

    wil::com_ptr_nothrow<IMMDeviceEnumerator> enumerator;
    RETURN_IF_FAILED(CoCreateInstance(__uuidof(IMMDeviceEnumerator),
    NULL,
    CLSCTX_ALL,
    IID_PPV_ARGS(&enumerator)));

    wil::com_ptr_nothrow<IMMDevice> device;
    RETURN_IF_FAILED(enumerator->GetDefaultAudioEndpoint(eRender, eConsole, &device));

    wil::com_ptr_nothrow<IAudioClient> audioClient;
    RETURN_IF_FAILED(device->Activate(__uuidof(IAudioClient),
    CLSCTX_ALL,
    NULL,
    (void**)&audioClient));

    wil::unique_cotaskmem_ptr<WAVEFORMATEX> wfx;
    RETURN_IF_FAILED(audioClient->GetMixFormat(wil::out_param_ptr<WAVEFORMATEX**>(wfx)));

    constexpr REFERENCE_TIME hnsRequestedDuration = 10000000;
    RETURN_IF_FAILED(audioClient->Initialize(AUDCLNT_SHAREMODE_SHARED,
    0,
    hnsRequestedDuration,
    0,
    wfx.get(),
    NULL));

    wil::com_ptr_nothrow<IAudioViewManagerService> audioViewManagerService;
    RETURN_IF_FAILED(audioClient->GetService(IID_PPV_ARGS(&audioViewManagerService)));
    RETURN_IF_FAILED(audioViewManagerService->SetAudioStreamWindow(hwnd));

    *audioStream = spAudioClient.detach();

    return S_OK;
}
```

## See also