# IXAudio2EngineCallback::OnCriticalError

## Description

Called if a critical system error occurs that requires XAudio2 to be closed down and restarted.

## Parameters

### `Error`

Error code returned by XAudio2.

## Remarks

If you provide the ID of a specific device in the *szDeviceId* parameter to [IXAudio2::CreateMasteringVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-createmasteringvoice) or use the XAUDIO2_NO_VIRTUAL_AUDIO_CLIENT flag, then a critical error will occur and **OnCriticalError** is raised if the underlying WASAPI rendering device becomes unavailable. This can occur when a headset or speaker is unplugged or when a USB audio device is removed, for example. Once a critical error has occurred, audio processing stops and all further calls to XAudio2 fail. The only way to recover in this situation is to release the XAudio2 instance and create a new one.

If you specified NULL or *szDeviceId* parameter to [IXAudio2::CreateMasteringVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-createmasteringvoice), then the system uses a Virtual Audio Client to represent the audio endpoint. In this case, if the underlying WASAPI rendering device becomes unavailable, the system automatically selects a new audio rendering device for rendering, audio processing continues, and **OnCriticalError** is not raised.

On the mobile device family, a Virtual Audio Client is always used and **OnCriticalError** is never raised, regardless of the values you provide to [CreateMasteringVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2-createmasteringvoice).

For information about the [IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback) interface methods, see the [XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks) section.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback)

[XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks)