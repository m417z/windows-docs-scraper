# XAUDIO2_BUFFER structure

## Description

Represents an audio data buffer, used with [IXAudio2SourceVoice::SubmitSourceBuffer](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-submitsourcebuffer).

## Members

### `Flags`

Flags that provide additional information about the audio buffer. May be 0, or the following value.

| Value | Description |
| --- | --- |
| XAUDIO2_END_OF_STREAM | Indicates that there cannot be any buffers in the queue after this buffer. The only effect of this flag is to suppress debug output warnings caused by starvation of the buffer queue. |

### `AudioBytes`

Size of the audio data, in bytes. Must be no larger than XAUDIO2_MAX_BUFFER_BYTES (defined in xaudio2.h) for PCM data and no larger than XMA_READBUFFER_MAX_BYTES (defined in xma2defs.h) for XMA data.

**Note** XMA buffers submitted to an XAudio2 voice using [IXAudio2SourceVoice::SubmitSourceBuffer](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-submitsourcebuffer) must contain complete XMA blocks. A complete XMA block must be equal in size to the **XMA2WAVEFORMATEX.BytesPerBlock** value, except for the last XMA block in a file, which may be shorter but will still be considered complete.

### `pAudioData`

Pointer to the audio data.

| Xbox 360 |
| --- |
| The memory allocated for a buffer containing XMA data must have a block alignment of 2048. This is accomplished using **XPhysicalAlloc** with the *ulAlignment* argument set to 2048. |

### `PlayBegin`

First sample in the buffer that should be played.

For XMA buffers this value must be a multiple of 128 samples.

### `PlayLength`

Length of the region to be played, in samples. A value of zero means to play the entire buffer, and, in this case, *PlayBegin* must be zero as well.
For ADPCM data this value must be a multiple of **wSamplesPerBlock** in the **ADPCMWAVEFORMAT** structure that contains this **XAUDIO2_BUFFER** structure.

### `LoopBegin`

First sample of the region to be looped. The value of *LoopBegin* must be less than *PlayBegin* + *PlayLength*. *LoopBegin* can be less than *PlayBegin*. *LoopBegin* must be 0 if *LoopCount* is 0.

### `LoopLength`

Length of the loop region, in samples. The value of *LoopBegin*+*LoopLength* must be greater than *PlayBegin* and less than *PlayBegin* + *PlayLength*. *LoopLength* must be zero if LoopCount is 0. If *LoopCount* is not 0 then a loop length of zero indicates the entire sample should be looped.
For ADPCM data this value must be a multiple of **wSamplesPerBlock** in the **ADPCMWAVEFORMAT** structure that contains this **XAUDIO2_BUFFER** structure.

### `LoopCount`

Number of times to loop through the loop region. This value can be between 0 and XAUDIO2_MAX_LOOP_COUNT. If *LoopCount* is zero no looping is performed and *LoopBegin* and *LoopLength* must be 0. To loop forever, set *LoopCount* to XAUDIO2_LOOP_INFINITE.

### `pContext`

Context value to be passed back in callbacks to the client. This may be NULL.

## Remarks

XAudio2 audio data is interleaved, data from each channel is adjacent for a particular sample number. For example if there was a 4 channel wave playing into an XAudio2 source voice, the audio data would be a sample of channel 0, a sample of channel 1, a sample of channel 2, a sample of channel 3, and then the next sample of channels 0, 1, 2, 3, etc.

The **AudioBytes** and **pAudioData** members of **XAUDIO2_BUFFER** correspond to the size in bytes and contents of the 'data' RIFF chunk of the file being played. The contents of the chunk may need to be byte swapped when loading the file on Xbox 360.

Memory allocated to hold a **XAUDIO2_BUFFER** or [XAUDIO2_BUFFER_WMA](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer_wma) structure can be freed as soon as the [IXAudio2SourceVoice::SubmitSourceBuffer](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-submitsourcebuffer) call it is passed to returns. The data the structure points to (**pAudioData** and **pDecodedPacketCumulativeBytes**, respectively) can't be freed until the buffer completes (as signaled by the [IXAudio2VoiceCallback::OnBufferEnd](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2voicecallback-onbufferend) callback) or the voice is stopped or destroyed.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[How to: Build a Basic Audio Processing Graph](https://learn.microsoft.com/windows/desktop/xaudio2/how-to--build-a-basic-audio-processing-graph)

[IXAudio2SourceVoice::SubmitSourceBuffer](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-submitsourcebuffer)

[XAudio2 Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)