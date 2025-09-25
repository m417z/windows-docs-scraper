# CXAPOBase::ProcessThru

## Description

Called by an [IXAPO::Process](https://learn.microsoft.com/windows/desktop/api/xapo/nf-xapo-ixapo-process) implementation when an XAPO is disabled for thru processing.

## Parameters

### `pInputBuffer`

Pointer to a buffer containing the input audio data.

### `pOutputBuffer`

Pointer to a buffer that will contain the processed audio data.

### `FrameCount`

Number of frames of audio data to process, where a frame is a block of samples, one per channel of audio data.

### `InputChannelCount`

Number of channels in the input data buffer.

### `OutputChannelCount`

Number of channels in the output data buffer.

### `MixWithOutput`

TRUE to mix with the destination buffer, FALSE to overwrite the destination buffer.

## Remarks

**ProcessThru** copies/mixes data from source to destination, making as few changes as possible to the audio data. However, **ProcessThru** is capable of channel upmix/downmix and uses the same matrix coefficient table used by windows Vista to do so.

This function may be called if:

1. The XAPO is locked and disabled.
2. The number of source frames equals the number of destination frames.
3. The output format is FLOAT32.
4. input format is INT8, INT16, INT20 (contained in 24 or 32 bits), INT24 (contained in 24 or 32 bits), INT32, or FLOAT32.

For in-place processing (where the input buffer equals the output buffer) this function does nothing.

When writing a **ProcessThru** method it is important to note XAudio2 audio data is interleaved, data from each channel is adjacent for a particular sample number. For example if there was a 4 channel wave playing into an XAudio2 source voice, the audio data would be a sample of channel 0, a sample of channel 1, a sample of channel 2, a sample of channel 3, and then the next sample of channels 0, 1, 2, 3, etc.

### Platform Requirements

Windows 10 (XAudio2.9); Windows 8, Windows Phone 8 (XAudio 2.8); DirectX SDK (XAudio 2.7)

## See also

[CXAPOBase](https://learn.microsoft.com/windows/desktop/api/xapobase/nl-xapobase-cxapobase)

[IXAPO](https://learn.microsoft.com/windows/desktop/api/xapo/nn-xapo-ixapo)