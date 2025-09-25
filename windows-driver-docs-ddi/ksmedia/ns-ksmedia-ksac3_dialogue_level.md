# KSAC3_DIALOGUE_LEVEL structure

## Description

The KSAC3_DIALOGUE_LEVEL structure specifies the average volume level of spoken dialog within the audio program encoded in an AC-3 stream.

## Members

### `DialogueLevel`

Specifies how far the average dialog level is below digital 100 percent. Valid values are 1 through 31. The values 1 through 31 are interpreted as -1 decibels through -31 decibels with respect to digital 100 percent.

## Remarks

This structure is used by the [KSPROPERTY_AC3_BIT_STREAM_MODE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-bit-stream-mode) property.

For more information about bit stream modes, see the AC-3 specification at the [Dolby Laboratories](https://www.dolby.com) website. The specification is titled Digital Audio Compression Standard (AC-3).

## See also

[KSPROPERTY_AC3_BIT_STREAM_MODE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-bit-stream-mode)