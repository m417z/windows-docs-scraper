## Description

Performs an ROI align operation, as described in the [Mask R-CNN](https://arxiv.org/abs/1703.06870) paper. In summary, the operation extracts crops from the input image tensor and resizes them to a common output size specified by the last 2 dimensions of *OutputTensor* using the specified *InterpolationMode*.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the input data with dimensions `{ BatchCount, ChannelCount, InputHeight, InputWidth }`.

### `ROITensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the regions of interest (ROI) data. The allowed dimensions of `ROITensor` are `{ NumROIs, 4 }`, `{ 1, NumROIs, 4 }`, or `{ 1, 1, NumROIs, 4 }`. For each ROI, the values will be the coordinates of its top-left and bottom-right corners in the order `[x1, y1, x2, y2]`.

### `BatchIndicesTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the batch indices to extract the ROIs from. The allowed dimensions of `BatchIndicesTensor` are `{ NumROIs }`, `{ 1, NumROIs }`, `{ 1, 1, NumROIs }`, or `{ 1, 1, 1, NumROIs }`. Each value is the index of a batch from *InputTensor*. The behavior is undefined if the values are not in the range [0, BatchCount).

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the output data. The expected dimensions of *OutputTensor* are `{ NumROIs, ChannelCount, OutputHeight, OutputWidth }`.

### `ReductionFunction`

Type: **[DML_REDUCE_FUNCTION](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_reduce_function)**

The reduction function to use when reducing across all input samples that contribute to an output element ([DML_REDUCE_FUNCTION_AVERAGE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_reduce_function) or **DML_REDUCE_FUNCTION_MAX**). The number of input samples to reduce across is bounded by *MinimumSamplesPerOutput* and *MaximumSamplesPerOutput*.

### `InterpolationMode`

Type: **[DML_INTERPOLATION_MODE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_interpolation_mode)**

The interpolation mode to use when resizing the regions.

- [DML_INTERPOLATION_MODE_NEAREST_NEIGHBOR](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_interpolation_mode). Uses the *Nearest Neighbor* algorithm, which chooses the input element nearest to the corresponding pixel center for each output element.
- **DML_INTERPOLATION_MODE_LINEAR**. Uses the *Bilinear* algorithm, which computes the output element by doing the weighted average of the 2 nearest neighboring input elements per dimension. Since only 2 dimensions are resized, the weighted average is computed on a total of 4 input elements for each output element.

### `SpatialScaleX`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The X (or width) component of the scaling factor to multiply the *ROITensor* coordinates by in order to make them proportionate to *InputHeight* and *InputWidth*. For example, if *ROITensor* contains normalized coordinates (values in the range [0..1]), then *SpatialScaleX* would usually have the same value as *InputWidth*.

### `SpatialScaleY`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The Y (or height) component of the scaling factor to multiply the *ROITensor* coordinates by in order to make them proportionate to *InputHeight* and *InputWidth*. For example, if *ROITensor* contains normalized coordinates (values in the range [0..1]), *SpatialScaleY* would usually have the same value as *InputHeight*.

### `OutOfBoundsInputValue`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value to read from *InputTensor* when the ROIs are outside the bounds of *InputTensor*. This can happen when the values obtained after scaling *ROITensor* by *SpatialScaleX* and *SpatialScaleY* are bigger than *InputWidth* and *InputHeight*.

### `MinimumSamplesPerOutput`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The minimum number of input samples to use for every output element. The operator will calculate the number of input samples by doing `ScaledCropSize / OutputSize`, and then clamp it to *MinimumSamplesPerOutput* and *MaximumSamplesPerOutput*.

### `MaximumSamplesPerOutput`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of input samples to use for every output element. The operator will calculate the number of input samples by doing `ScaledCropSize / OutputSize`, and then clamp it to *MinimumSamplesPerOutput* and *MaximumSamplesPerOutput*.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_0`.

## Tensor constraints
*InputTensor*, *OutputTensor*, and *ROITensor* must have the same *DataType*.

## Tensor support
### DML_FEATURE_LEVEL_5_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| ROITensor | Input | 2 to 4 | FLOAT32, FLOAT16 |
| BatchIndicesTensor | Input | 1 to 4 | UINT64, UINT32 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| ROITensor | Input | 2 to 4 | FLOAT32, FLOAT16 |
| BatchIndicesTensor | Input | 1 to 4 | UINT32 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |