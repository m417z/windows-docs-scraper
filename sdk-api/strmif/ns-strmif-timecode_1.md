# TIMECODE structure

## Description

The **TIMECODE** structure contains basic timecode frame count information.

## Members

### `wFrameRate`

Number of frames per second. Specify with one of the following values:

| Value | Meaning |
| --- | --- |
| **ED_FORMAT_SMPTE_30** | 30 frames per second. |
| **ED_FORMAT_SMPTE_30DROP** | 30 frames per second drop frame (actual rate 29.97 fps). |
| **ED_FORMAT_SMPTE_25** | 25 frames per second. |
| **ED_FORMAT_SMPTE_24** | 24 frames per second. |

### `wFrameFract`

Fractional frame. Full scale is 0x1000.

### `dwFrames`

Timecode value as a binary framecount.

### `qw`

## Remarks

Fractional frame can be used to indicate temporal offset into frame when timecode was actually read from an external device; for example, wFrameFract=0x7ff means the timecode value was read from the device at the end of the first video field.

## See also

[DirectShow Structures](https://learn.microsoft.com/windows/desktop/DirectShow/directshow-structures)