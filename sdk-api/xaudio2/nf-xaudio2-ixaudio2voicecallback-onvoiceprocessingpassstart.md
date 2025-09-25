# IXAudio2VoiceCallback::OnVoiceProcessingPassStart

## Description

Called during each processing pass for each voice, just before XAudio2 reads data from the voice's buffer queue.

## Parameters

### `BytesRequired`

The number of bytes that must be submitted immediately to avoid starvation. This allows the implementation of just-in-time streaming scenarios; the client can keep the absolute minimum data queued on the voice at all times, and pass it fresh data just before the data is required. This model provides the lowest possible latency attainable with XAudio2. For xWMA and XMA data *BytesRequired* will always be zero, since the concept of a frame of xWMA or XMA data is meaningless.

**Note** In a situation where there is always plenty of data available on the source voice, *BytesRequired* should always report zero, because it doesn't need any samples immediately to avoid glitching.

## Remarks

For information about [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback) interface methods, see the [XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks) topic.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Use Source Voice Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--use-source-voice-callbacks)

[IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)

[XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks)