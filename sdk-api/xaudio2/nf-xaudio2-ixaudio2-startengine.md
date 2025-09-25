# IXAudio2::StartEngine

## Description

Starts the audio processing thread.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

After **StartEngine** is called, all started voices begin to consume audio. All enabled effects start running, and the resulting audio is sent to any connected output devices. When XAudio2 is first initialized, the engine is already in the started state.

It is invalid to call **StartEngine** from within a callback (that is, [IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback) or [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)). If **StartEngine** is called within a callback, it returns XAUDIO2_E_INVALID_CALL.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2)