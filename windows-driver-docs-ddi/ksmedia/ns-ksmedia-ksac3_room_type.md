# KSAC3_ROOM_TYPE structure

## Description

The KSAC3_ROOM_TYPE structure specifies the type of audio mixing room in which an AC-3-encoded stream was produced.

## Members

### `fLargeRoom`

Specifies the type and calibration of the mixing room used for the final audio mixing session. If **TRUE**, a large room with an X curve (described in the AC-3 specification; for more information, see the following Remarks section) was used. If **FALSE**, a small room with a flat curve was used.

## Remarks

This structure characterizes the production environment of an AC-3-encoded stream. The information in the structure is not typically used by the decoder, but might be used by other audio components after decoding.

This structure is used by the [KSPROPERTY_AC3_ROOM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-room-type) property.

For more information about bit stream modes, see the AC-3 specification at the [Dolby Laboratories](https://www.dolby.com) website. The specification is titled Digital Audio Compression Standard (AC-3).

## See also

[KSPROPERTY_AC3_ROOM_TYPE](https://learn.microsoft.com/windows-hardware/drivers/audio/ksproperty-ac3-room-type)