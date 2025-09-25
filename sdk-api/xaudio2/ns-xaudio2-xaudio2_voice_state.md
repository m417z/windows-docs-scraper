# XAUDIO2_VOICE_STATE structure

## Description

Returns the voice's current state and cursor position data.

## Members

### `pCurrentBufferContext`

Pointer to a buffer context provided in the [XAUDIO2_BUFFER](https://learn.microsoft.com/windows/desktop/api/xaudio2/ns-xaudio2-xaudio2_buffer) that is processed currently, or, if the voice is stopped currently, to the next buffer due to be processed. **pCurrentBufferContext** is NULL if there are no buffers in the queue.

### `BuffersQueued`

Number of audio buffers currently queued on the voice, including the one that is processed currently.

### `SamplesPlayed`

Total number of samples processed by this voice since it last started, or since the last audio stream ended (as marked with the XAUDIO2_END_OF_STREAM flag). This total includes samples played multiple times due to looping. Theoretically, if all audio emitted by the voice up to this time is captured, this parameter would be the length of the audio stream in samples. If you specify **XAUDIO2_VOICE_NOSAMPLESPLAYED** when you call [IXAudio2SourceVoice::GetState](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-getstate), this member won't be calculated, and its value is unspecified on return from **IXAudio2SourceVoice::GetState**. **IXAudio2SourceVoice::GetState** takes about one-third as much time to complete when you specify **XAUDIO2_VOICE_NOSAMPLESPLAYED**.

## Remarks

For all encoded formats, including constant bit rate (CBR) formats such as adaptive differential pulse code modulation (ADPCM), **SamplesPlayed** is expressed in terms of decoded samples. For pulse code modulation (PCM) formats, **SamplesPlayed** is expressed in terms of either input or output samples. There is a one-to-one mapping from input to output for PCM formats.

If a client needs to get the correlated positions of several voices—that is, to know exactly which sample of a particular voice is playing when a specified sample of another voice is playing—it must make the [IXAudio2SourceVoice::GetState](https://learn.microsoft.com/windows/desktop/api/xaudio2/nf-xaudio2-ixaudio2sourcevoice-getstate) calls in an XAudio2 engine callback. Doing this ensures that none of the voices advance while the calls are made.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[Structures](https://learn.microsoft.com/windows/desktop/xaudio2/structures)