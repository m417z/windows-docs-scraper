## Description

Provides data about a macroblock during video decoding.

## Members

### `flags`

A bitwise OR combination of zero or more of the following values:

| Constant | Value | Description |
|----------|-------|-------------|
| MACROBLOCK_FLAG_SKIP | 0x00000001 | The macroblock is not needed for output and can be skipped. |
| MACROBLOCK_FLAG_DIRTY | 0x00000002 | The macroblock is changed from the previous frame. |
| MACROBLOCK_FLAG_MOTION | 0x00000004 | The macroblock from the previous frame has moved to a new position. |
| MACROBLOCK_FLAG_VIDEO | 0x00000008 | The macroblock contains video playback or other continuous motion, rather than a slower moving screen capture |
| MACROBLOCK_FLAG_HAS_MOTION_VECTOR | 0x00000010 | The motion vector values of the **MACROBLOCK_DATA** are valid, and should be used in preference to the encoder's calculated motion vector values |
| MACROBLOCK_FLAG_HAS_QP | 0x00000020 | The *QPDelta* value of the **MACROBLOCK_DATA** is valid, and specifies the QP of this macroblock relative to the rest of the frame. |

### `motionVectorX`

The X component of the motion vector of the macroblock.

### `motionVectorY`

The Y component of the motion vector of the macroblock.

### `QPDelta`

The delta quantization paramater value of the macroblock.

## Remarks

## See also