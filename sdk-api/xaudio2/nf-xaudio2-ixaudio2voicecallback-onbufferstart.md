# IXAudio2VoiceCallback::OnBufferStart

## Description

Called when the voice is about to start processing a new audio buffer.

## Parameters

### `pBufferContext`

Context pointer that was assigned to the pContext member of the [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) structure when the buffer was submitted.

## Remarks

*pBufferContext* is the context pointer originally provided by the **pContext** member of the [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) structure, which may be NULL.

**OnBufferStart** is guaranteed to be called just before the first byte of the current buffer is consumed. It is appropriate to use this callback for changes to the voice state such as the following.

* Submitting a new buffer to the voice
* Adjusting the volume, pitch, and effect parameters of the voice
* Enabling or disabling an effect in the voice's effect chain

All the actions listed above are synchronous when performed in an XAudio2 callback, so the changes will take effect immediately, affecting the buffer that is about to start.

It is also safe to use this callback to write audio data to the buffer directly, which can be useful for low-latency streaming scenarios. However, as with all XAudio2 callbacks, no work should be done that uses a significant amount of processor time or could block execution, including synchronous disk or network reads.

For information about the [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback) interface methods, see the [XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks) section.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Use Source Voice Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--use-source-voice-callbacks)

[IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)

[XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks)