# IXAudio2VoiceCallback::OnBufferEnd

## Description

Called when the voice finishes processing a buffer.

## Parameters

### `pBufferContext`

Context pointer assigned to the **pContext** member of the [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) structure when the buffer was submitted.

## Remarks

After an **OnBufferEnd** callback the audio memory for the buffer associated with *pBufferContext* can safely be released.

*pBufferContext* is the context pointer originally provided by the **pContext**  member of the [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) structure, which may be NULL.

**OnBufferEnd** is guaranteed to be called just after the last byte of the current buffer has been consumed and before the first byte of the next buffer is consumed. This callback can be used to overwrite or release the audio data referenced by the completed buffer, and to update other state associated with the voice as appropriate.

For information about [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback) interface methods, see the [XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks) topic.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Stream a Sound from Disk](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--stream-a-sound-from-disk)

[How to: Use Source Voice Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--use-source-voice-callbacks)

[IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)