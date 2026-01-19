## Description

Describes the Quantization Parameter (QP) map settings that a video encoder MFT accepts as input.

## Members

### `minBlockSize`

The minimum block size granularity at which the MFT can accept QP values.

### `maxBlockSize`

The maximum block size granularity at which the MFT can accept QP values.

### `stepsBlockSize`

An incremental step that can be added to *minBlockSize* to produce a block size. The resulting block size must be within the range [*minBlockSize*, *maxBlockSize*]. Zero is a possible value for *stepsBlockSize* which implies that *minBlockSize* and *maxBlockSize* are the only allowed values for the block size.

### `dataType`

A value from the [AVEncVideoQPMapElementDataType](https://learn.microsoft.com/windows/win32/api/mfapi/eAVEncVideoQPMapElementDataType) specifying the data width and the signed nature of the QP min and max values.

### `minValue`

This value represents the minimum QP value accepted by the video encoder MFT. Any entry within such a QP map must be greater than or equal to *minValue*.

### `maxValue`

This value represents the maximum QP value accepted by the video encoder MFT. Any entry within such a QP map must be less than or equal to *maxValue*.

### `step`

An incremental step that can be added to *minValue* to produce a QP value. The resulting QP value must be within the range [*minValue*, *maxValue*]. Zero is a possible value for *step*, which implies that *minValue* and *maxValue* are the only allowed values for the QP value.

## Remarks

This structure provides data for the [CODECAPI_AVEncVideoInputAbsoluteQPBlockSettings](https://learn.microsoft.com/windows/win32/medfound/codecapi-avencvideoinputabsoluteqpblocksettings) and [CODECAPI_AVEncVideoInputDeltaQPBlockSettings](https://learn.microsoft.com/windows/win32/medfound/codecapi-avencvideoinputdeltaqpblocksettings) properties.

## See also