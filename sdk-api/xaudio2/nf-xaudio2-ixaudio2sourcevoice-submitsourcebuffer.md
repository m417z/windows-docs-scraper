# IXAudio2SourceVoice::SubmitSourceBuffer

## Description

Adds a new audio buffer to the voice queue.

## Parameters

### `pBuffer` [in]

Pointer to an [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) structure to queue.

### `X2DEFAULT`

TBD

### `pBufferWMA` [in]

Pointer to an additional [XAUDIO2_BUFFER_WMA](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer_wma) structure used when submitting WMA data.

## Return value

Returns S_OK if successful, an error code otherwise. See [XAudio2 Error Codes](https://learn.microsoft.com/windows/desktop/xaudio2/xaudio2-error-codes) for descriptions of XAudio2 specific error codes.

## Remarks

The voice processes and plays back the buffers in its queue in the order that they were submitted.

The [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) structure includes details about the audio buffer's location and size, the part of the buffer that should actually be played, the loop region (if any) and loop count, the context pointer to be used in any callbacks relating to this buffer, and an optional XAUDIO2_END_OF_STREAM flag that indicates that it is the last buffer of a contiguous sound.

If the voice is started and has no buffers queued, the new buffer will start playing immediately. If the voice is stopped, the buffer is added to the voice's queue and will be played when the voice starts.

If only part of the given buffer should be played, the **PlayBegin** and **PlayLength** fields in the [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) can be used to specify the region to be played. A **PlayLength** value of 0 means to play the entire buffer (and in this case **PlayBegin** must be 0 as well).

If all or part of the buffer should be played in a continuous loop, the **LoopBegin**, **LoopLength** and **LoopCount** fields in [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) can be used to specify the characteristics of the loop region. A **LoopBegin** value of XAUDIO2_NO_LOOP_REGION means that no looping should be performed, and in this case **LoopLength** and **LoopCount** must be given as 0. If a loop region is specified, it must be non-empty (**LoopLength** > 0), and the loop count must be between 1 and XAUDIO2_MAX_LOOP_COUNT inclusive (or XAUDIO2_LOOP_INFINITE to specify an endless loop which will only end when [IXAudio2SourceVoice::ExitLoop](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-exitloop) is called). A loop count of *N* means to skip backwards N times, i.e. to play the loop region *N*+1 times.

If an explicit play region is specified, it must begin and end within the given audio buffer (or, in the compressed case, within the set of samples that the buffer will decode to). In addition, the loop region cannot end past the end of the play region.

| Xbox 360 |
| --- |
| For certain audio formats, there may be additional restrictions on the valid endpoints of any play or loop regions; e.g. for XMA buffers, the regions can only begin or end at 128-sample boundaries in the decoded audio. |

The *pBuffer* pointer can be reused or freed immediately after calling this method, but the actual audio data referenced by *pBuffer* must remain valid until the buffer has been fully consumed by XAudio2 (which is indicated by the [IXAudio2VoiceCallback::OnBufferEnd](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voicecallback-onbufferend) callback).

Up to XAUDIO2_MAX_QUEUED_BUFFERS buffers can be queued on a voice at any one time.

**SubmitSourceBuffer** takes effect immediately when called from an XAudio2 callback with an OperationSet of XAUDIO2_COMMIT_NOW.

| Xbox 360 |
| --- |
| This method can be called from an Xbox system thread (most other XAudio2 methods cannot). However, a maximum of two source buffers can be submitted from a system thread at a time. |

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Build a Basic Audio Processing Graph](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--build-a-basic-audio-processing-graph)

[How to: Stream a Sound from Disk](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--stream-a-sound-from-disk)

[IXAudio2SourceVoice](https://learn.microsoft.com/windows/desktop/api/xaudio2/nn-xaudio2-ixaudio2sourcevoice)