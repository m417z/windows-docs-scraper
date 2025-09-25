# KSAC3_ALTERNATE_AUDIO structure

## Description

The KSAC3_ALTERNATE_AUDIO structure specifies whether the two mono channels in an AC-3-encoded stream should be interpreted as a stereo pair or as two independent program channels.

## Members

### `fStereo`

Specifies whether the two mono channels should be interpreted as a stereo pair. If **TRUE**, the two mono channels are treated as a stereo pair. If **FALSE**, **DualMode**=0x03 causes the two mono channels to be mixed before being output by the decoder.

### `DualMode`

When two independent channels of audio are encoded in the stream, this member specifies whether to use the audio track in channel 1, channel 2, or both. A value of 0x01 selects channel 1, 0x02 selects channel 2, and 0x03 selects both. Specify the value of this member as one of the following constants:

| Constant | Value |
|--|--|
| KSAC3_ALTERNATE_AUDIO_1 | 0x01 |
| KSAC3_ALTERNATE_AUDIO_2 | 0x02 |
| KSAC3_ALTERNATE_AUDIO_BOTH | 0x03 |

## Remarks

This structure is used by the [KSPROPERTY_AC3_ALTERNATE_AUDIO](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-alternate-audio) property.

For more information about the encoding of AC-3 program channels, see the AC-3 specification at the [Dolby Laboratories](https://www.dolby.com) website. The specification is titled Digital Audio Compression Standard (AC-3).

## See also

[KSPROPERTY_AC3_ALTERNATE_AUDIO](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-alternate-audio)