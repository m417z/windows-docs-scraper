# IXAudio2VoiceCallback::OnVoiceError

## Description

Called when a critical error occurs during voice processing.

## Parameters

### `pBufferContext`

Context pointer that was assigned to the **pContext** member of the [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) structure when the buffer was submitted.

### `Error`

The HRESULT code of the error encountered.

## Remarks

**OnVoiceError** is called in the event of an error during voice processing, such as a hardware XMA decoder error on the Xbox 360. The arguments report which buffer was being processed at the time of the error, and its HRESULT code. If the error is not recoverable by destroying and re-creating the voice, the [OnCriticalError](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2enginecallback-oncriticalerror) engine callback will be called as well.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Use Source Voice Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--use-source-voice-callbacks)

[IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)

[XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks)