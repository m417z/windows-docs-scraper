# KSAUDIO_PRESENTATION_POSITION structure

## Description

The **KSAUDIO_PRESENTATION_POSITION** structure specifies the current cursor position in audio data stream that is being rendered to the endpoint.

## Members

### `u64PositionInBlocks`

Specifies the block offset from the start of the stream to the current post-decoded, uncompressed position in the stream. A "block" refers to the group of channels in the same sample. So, for example, in a PCM stream a block is the same as a frame. However, for compressed formats a block is a single sample within a frame. This means that for a typical MP3 stream that has 1152 samples in a frame, there are 1152 blocks.

### `u64QPCPosition`

Specifies the value of the performance counter at the time that the audio driver reads the presentation position in response to the **KSAUDIO_PRESENTATION_POSITION** call. A driver writes to this field with the value read from calling [KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter) when a snapshot is taken of the presentation position.

## See also

[KSAUDIO_PRESENTATION_POSITION](https://learn.microsoft.com/windows-hardware/drivers/ddi/ksmedia/ns-ksmedia-ksaudio_presentation_position)

[KSPROPERTY_AUDIO_PRESENTATION_POSITION](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-audio-presentation-position)

[KeQueryPerformanceCounter](https://learn.microsoft.com/windows-hardware/drivers/ddi/ntifs/nf-ntifs-kequeryperformancecounter)