## Description

Upsamples the input image, writing the result into the output tensor. The order of the dimensions should be NCHW (BatchSize, ChannelCount, Height, Width) or NCDHW (BatchSize, ChannelCount, Depth, Height, Width), but strides can be used if the data is stored in a different format. Unlike [DML_RESAMPLE_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_resample_operator_desc), only the last 2 dimensions (height and width) can be upsampled.

If available, you should prefer [DML_RESAMPLE_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_resample_operator_desc) since it is a more flexible version of **DML_UPSAMPLE_2D_OPERATOR_DESC**.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the input data. The expected dimensions of the InputTensor are `{ InputBatchCount, InputChannelCount, InputHeight, InputWidth }` for 4D, and `{ InputBatchCount, InputChannelCount, InputDepth, InputHeight, InputWidth }` for 5D.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the input data. The expected dimensions of the OutputTensor are `{ InputBatchCount, InputChannelCount, InputHeight * HeightScale, InputWidth * WidthScale }` for 4D, and `{ InputBatchCount, InputChannelCount, InputDepth, InputHeight * HeightScale, InputWidth * WidthScale }` for 5D.

### `ScaleSize`

Type: [**DML_SIZE_2D**](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_size_2d)

The width and height scales of type UINT to apply when upsampling the input. `0 < ScaleSize.Height <= UINT_MAX / InputHeight` and `0 < ScaleSize.Width <= UINT_MAX / InputWidth`.

### `InterpolationMode`

Type: **[DML_INTERPOLATION_MODE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_interpolation_mode)**

This field determines the kind of interpolation used to choose output pixels.

- [DML_INTERPOLATION_MODE_NEAREST_NEIGHBOR](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_interpolation_mode). Uses the *Nearest Neighbor* algorithm, which chooses the input element nearest to the corresponding pixel center for each output element.
- **DML_INTERPOLATION_MODE_LINEAR**. Uses the *Bilinear* algorithm, which computes the output element by doing the weighted average of the 2 nearest neighboring input elements in the height dimension, and the 2 nearest neighboring input elements in the width dimension, for a total of 4 elements. This is true even if the input/output DimensionCount is 5. That is, samples are only ever averaged along the width and height dimensions, and never along the batch, channel, or depth.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType* and *DimensionCount*.

## Tensor support
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 to 5 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 to 5 | FLOAT32, FLOAT16 |