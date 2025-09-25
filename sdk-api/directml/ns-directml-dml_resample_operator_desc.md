## Description

Resamples elements from the source to the destination tensor, using the scale factors to compute the destination tensor size. You can use a linear or nearest-neighbor interpolation mode. The operator supports interpolation across multiple dimensions, not just 2D. So you can keep the same spatial size, but interpolate across channels or across batches.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor containing the input data.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write the output data to.

### `InterpolationMode`

Type: [**DML_INTERPOLATION_MODE**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_interpolation_mode)

This field determines the kind of interpolation used to choose output pixels.

- **DML_INTERPOLATION_MODE_NEAREST_NEIGHBOR**. Uses the *Nearest Neighbor* algorithm, which chooses the input element nearest to the corresponding pixel center for each output element.

- **DML_INTERPOLATION_MODE_LINEAR**. Uses the *Linear Interpolation* algorithm, which computes the output element by computing the weighted average of the 2 nearest neighboring input elements per dimension. Resampling is supported up to 4 dimensions (quadrilinear), where the weighted average is computed on a total of 16 input elements for each output element.

### `ScaleCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of values in the array `Scales` points to. This value must match the dimension count of *InputTensor* and *OutputTensor*.

### `Scales`

Type: \_Field\_size\_(ScaleCount) **const [FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

The scales to apply when resampling the input, where scales > 1 scale up the image and scales < 1 scale down the image for that dimension. Note that the scales don't need to be exactly `OutputSize / InputSize`. If the input after scaling is larger than the output bound, then we crop it to the output size. On the other hand, if the input after scaling is smaller than the output bound, the output edges are clamped.

## Remarks
A newer version of this operator, [DML_RESAMPLE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_resample1_operator_desc), was introduced in `DML_FEATURE_LEVEL_2_1`.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_2_0`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType* and *DimensionCount*.

## Tensor support
### DML_FEATURE_LEVEL_6_2 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 4 | FLOAT32, FLOAT16, INT8, UINT8 |
| OutputTensor | Output | 1 to 4 | FLOAT32, FLOAT16, INT8, UINT8 |

### DML_FEATURE_LEVEL_5_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 1 to 4 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_2_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |

## See also