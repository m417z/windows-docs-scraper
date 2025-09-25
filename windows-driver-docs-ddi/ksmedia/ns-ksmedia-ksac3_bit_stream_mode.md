# KSAC3_BIT_STREAM_MODE structure

## Description

The KSAC3_BIT_STREAM_MODE structure specifies the bit-stream mode, which is the type of audio service that is encoded into an AC-3 stream.

## Members

### `BitStreamMode`

Specifies the bit-stream mode. The **BitStreamMode** member is set to a value in the range 0 to 7.

Specify the value of this member as one of the following constants:

| Constant | Value |
|--|--|
| KSAC3_SERVICE_MAIN_AUDIO | 0 |
| KSAC3_SERVICE_NO_DIALOG | 1 |
| KSAC3_SERVICE_VISUALLY_IMPAIRED | 2 |
| KSAC3_SERVICE_HEARING_IMPAIRED | 3 |
| KSAC3_SERVICE_DIALOG_ONLY | 4 |
| KSAC3_SERVICE_COMMENTARY | 5 |
| KSAC3_SERVICE_EMERGENCY_FLASH | 6 |
| KSAC3_SERVICE_VOICE_OVER | 7 |

These constants correspond to the bit-stream modes that are defined in the AC-3 specification. For more information, see the following Remarks section.

## Remarks

This structure is used by the [KSPROPERTY_AC3_BIT_STREAM_MODE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-bit-stream-mode) property.

For more information about bit stream modes, see the AC-3 specification at the [Dolby Laboratories](https://www.dolby.com) website. The specification is titled Digital Audio Compression Standard (AC-3).

## See also

[KSPROPERTY_AC3_BIT_STREAM_MODE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-bit-stream-mode)