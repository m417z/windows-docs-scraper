# IXAudio2VoiceCallback::OnLoopEnd

## Description

Called when the voice reaches the end position of a loop.

## Parameters

### `pBufferContext`

Context pointer that was assigned to the **pContext** member of the [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) structure when the buffer was submitted.

## Remarks

*pBufferContext* is the context pointer originally provided by the **pContext** member of the [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) structure, which may be NULL.

**OnLoopEnd** is not sample-accurate; that is, actions in the callback do not occur at the exact moment that a given sample is being processed. It is only guaranteed to be called shortly after the last sample in the loop has been processed.

For information about the [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback) interface methods, see the [XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks) section.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Use Source Voice Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--use-source-voice-callbacks)

[IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)

[XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks)