# MF_QUALITY_DROP_MODE enumeration

## Description

Specifies how aggressively a pipeline component should drop samples.

## Constants

### `MF_DROP_MODE_NONE:0`

Normal processing of samples. Drop mode is disabled.

### `MF_DROP_MODE_1:0x1`

First drop mode (least aggressive).

### `MF_DROP_MODE_2:0x2`

Second drop mode.

### `MF_DROP_MODE_3:0x3`

Third drop mode.

### `MF_DROP_MODE_4:0x4`

Fourth drop mode.

### `MF_DROP_MODE_5:0x5`

Fifth drop mode (most aggressive, if it is supported; see Remarks).

### `MF_NUM_DROP_MODES:0x6`

Maximum number of drop modes. This value is not a valid flag.

## Remarks

In drop mode, a component drops samples, more or less aggressively depending on the level of the drop mode. The specific algorithm used depends on the component. Mode 1 is the least aggressive mode, and mode 5 is the most aggressive. A component is not required to implement all five levels.

For example, suppose an encoded video stream has three B-frames between each pair of P-frames. A decoder might implement the following drop modes:

* Mode 1: Drop one out of every three B frames.
* Mode 2: Drop one out of every two B frames.
* Mode 3: Drop all delta frames.
* Modes 4 and 5: Unsupported.

The enhanced video renderer (EVR) can drop video frames before sending them to the EVR mixer.

## See also

[IMFQualityAdvise](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)