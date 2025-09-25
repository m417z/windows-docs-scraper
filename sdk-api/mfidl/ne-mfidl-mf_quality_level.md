# MF_QUALITY_LEVEL enumeration

## Description

Specifies the quality level for a pipeline component. The quality level determines how the component consumes or produces samples.

## Constants

### `MF_QUALITY_NORMAL:0`

Normal quality.

### `MF_QUALITY_NORMAL_MINUS_1:0x1`

One level below normal quality.

### `MF_QUALITY_NORMAL_MINUS_2:0x2`

Two levels below normal quality.

### `MF_QUALITY_NORMAL_MINUS_3:0x3`

Three levels below normal quality.

### `MF_QUALITY_NORMAL_MINUS_4:0x4`

Four levels below normal quality.

### `MF_QUALITY_NORMAL_MINUS_5:0x5`

Five levels below normal quality.

### `MF_NUM_QUALITY_LEVELS:0x6`

Maximum number of quality levels. This value is not a valid flag.

## Remarks

Each successive quality level decreases the amount of processing that is needed, while also reducing the resulting quality of the audio or video. The specific algorithm used to reduce quality depends on the component. Mode 1 is the least aggressive mode, and mode 5 is the most aggressive. A component is not required to implement all five levels. Also, the same quality level might not be comparable between two different components.

Video decoders can often reduce quality by leaving out certain post-processing steps. The enhanced video renderer (EVR) can sometimes reduce quality by switching to a different deinterlacing mode.

## See also

[IMFQualityAdvise](https://learn.microsoft.com/windows/desktop/api/mfidl/nn-mfidl-imfqualityadvise)

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)