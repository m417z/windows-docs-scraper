# IXAudio2SourceVoice::FlushSourceBuffers

## Description

Removes all pending audio buffers from the voice queue.

## Return value

Returns S_OK if successful, an error code otherwise.

## Remarks

If the voice is started, the buffer that is currently playing is not removed from the queue.

**FlushSourceBuffers** can be called regardless of whether the voice is currently started or stopped.

For every buffer removed, an [OnBufferEnd](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voicecallback-onbufferend) callback will be made, but none of the other per-buffer callbacks ([OnBufferStart](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voicecallback-onbufferstart), [OnStreamEnd](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voicecallback-onstreamend) or [OnLoopEnd](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voicecallback-onloopend)) will be made.

**FlushSourceBuffers** does not change a the voice's running state, so if the voice was playing a buffer prior to the call, it will continue to do so, and will deliver all the callbacks for the buffer normally. This means that the [OnBufferEnd](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voicecallback-onbufferend) callback for this buffer will take place after the **OnBufferEnd** callbacks for the buffers that were removed. Thus, an XAudio2 client that calls **FlushSourceBuffers** cannot expect to receive **OnBufferEnd** callbacks in the order in which the buffers were submitted.

No warnings for starvation of the buffer queue will be emitted when the currently playing buffer completes; it is assumed that the client has intentionally removed the buffers that followed it. However, there may be an audio pop if this buffer does not end at a zero crossing. If the application must ensure that the flush operation takes place while a specific buffer is playing—perhaps because the buffer ends with a zero crossing—it must call **FlushSourceBuffers** from a callback, so that it executes synchronously.

Calling **FlushSourceBuffers** after a voice is stopped and then submitting new data to the voice resets all of the voice's internal counters.

A voice's state is not considered reset after calling **FlushSourceBuffers** until the [OnBufferEnd](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voicecallback-onbufferend) callback occurs (if a buffer was previously submitted) or [IXAudio2SourceVoice::GetState](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-getstate) returns with [XAUDIO2_VOICE_STATE](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_voice_state). **BuffersQueued** == 0. For example, if you stop a voice and call **FlushSourceBuffers**, it's still not legal to immediately call [IXAudio2SourceVoice::SetSourceSampleRate](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-setsourcesamplerate) (which requires the voice to not have any buffers currently queued), until either of the previously mentioned conditions are met.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice)