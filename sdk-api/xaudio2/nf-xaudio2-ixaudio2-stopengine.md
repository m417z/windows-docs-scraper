# IXAudio2::StopEngine

## Description

Stops the audio processing thread.

## Remarks

When **StopEngine** is called, all output is stopped immediately. However, the audio graph is left untouched, preserving effect parameters, effect histories (for example, the data stored by a reverb effect in order to emit echoes of a previous sound), voice states, pending source buffers, cursor positions, and so forth. When the engine is restarted, the resulting audio output will be identical—apart from a period of silence—to the output that would have been produced if the engine had never been stopped.

It is invalid to call **StopEngine** from within a callback (that is, [IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback) or [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)).

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2)

[XAPO Overview](https://learn.microsoft.com/windows/desktop/xaudio2/xapo-overview)