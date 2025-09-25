# IXAudio2::Release

## Description

Releases a reference to the XAudio2 object.

## Return value

Always returns 0.

## Remarks

When the final **Release** is called on a given XAudio2 object, all voice objects that are associated with it are destroyed. Any pointers to these objects that are still held by the client become invalid immediately. Any calls that are made to them cause undefined behavior. The audio processing engine is also stopped. This is so that after **Release** is returned, the client can safely free any data that is referenced by the graph (for example, audio source buffers or callback handling objects).

**Release** is a synchronous call. While glitching should not occur (since it only briefly takes the processing lock), a title can avoid potential thread wait times by calling this method in an XAudio2 callback.

It is invalid to call **Release** from within a callback (that is, [IXAudio2EngineCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2enginecallback) or [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)).

### Platform Requirements

Windows 10 (XAudio2.9);
Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2)