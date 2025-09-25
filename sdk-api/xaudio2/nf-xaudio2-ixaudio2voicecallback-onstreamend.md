# IXAudio2VoiceCallback::OnStreamEnd

## Description

Called when the voice has just finished playing a contiguous audio stream.

## Remarks

**OnStreamEnd** is triggered when XAudio2 processes an [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) with the XAUDIO2_END_OF_STREAM flag set. See the [IXAudio2SourceVoice::SubmitSourceBuffer](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-submitsourcebuffer) method for more information.

The **OnStreamEnd** callback indicates that XAudio2 has finished consuming the last buffer submitted to the voice. With PCM data, all audio is guaranteed to have been played and the voice can be stopped or destroyed safely.

The **OnStreamEnd** callback only indicates that an [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) with the XAUDIO2_END_OF_STREAM flag set has been processed. The callback is strictly informational and does not change the state of the source voice that triggered it. A voice stays in the start state until [IXAudio2SourceVoice::Stop](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-stop) is called and will continue to play submitted source buffers and to trigger additional callbacks.

**OnStreamEnd** is guaranteed to be called just after the last byte of the current buffer has been consumed.

For information about [IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback) interface methods, see the [XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks) topic.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Use Source Voice Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--use-source-voice-callbacks)

[IXAudio2VoiceCallback](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2voicecallback)

[XAudio2 Callbacks](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-callbacks)