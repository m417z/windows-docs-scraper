## Description

Performs a convolution of the *FilterTensor* with the *InputTensor*. This operator supports a number of standard convolution configurations. These standard configurations include forward and backward (transposed) convolution by setting the *Direction* and *Mode* fields, as well as depth-wise convolution by setting the *GroupCount* field.

A summary of the steps involved: perform the convolution into the output tensor; reshape the bias to the same dimension sizes as the output tensor; add the reshaped bias tensor to the output tensor.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the input data. The expected dimensions of the *InputTensor* are:
* `{ BatchCount, InputChannelCount, InputWidth }` for 3D,
* `{ BatchCount, InputChannelCount, InputHeight, InputWidth }` for 4D, and
* `{ BatchCount, InputChannelCount, InputDepth, InputHeight, InputWidth }` for 5D.

### `FilterTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the filter data. The expected dimensions of the *FilterTensor* are:
* `{ FilterBatchCount, FilterChannelCount, FilterWidth }` for 3D,
* `{ FilterBatchCount, FilterChannelCount, FilterHeight, FilterWidth }` for 4D, and
* `{ FilterBatchCount, FilterChannelCount, FilterDepth, FilterHeight, FilterWidth }` for 5D.

### `BiasTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing the bias data. The bias tensor is a tensor containing data which is broadcasted across the output tensor at the end of the convolution which is added to the result. The expected dimensions of the *BiasTensor* are:
* `{ 1, OutputChannelCount, 1 }` for 3D,
* `{ 1, OutputChannelCount, 1, 1 }` for 4D, and
* `{ 1, OutputChannelCount, 1, 1, 1 }` for 5D.

For each output channel, the single bias value for that channel is added to every element in that channel of the *OutputTensor*. That is, the *BiasTensor* is broadcasted to the size of the *OutputTensor*, and what the operator returns is the summation of this broadcasted *BiasTensor* with the result from convolution.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor to write the results to. The expected dimensions of the *OutputTensor* are:
* `{ BatchCount, OutputChannelCount, OutputWidth }` for 3D,
* `{ BatchCount, OutputChannelCount, OutputHeight, OutputWidth }` for 4D, and
* `{ BatchCount, OutputChannelCount, OutputDepth, OutputHeight, OutputWidth }` for 5D.

### `Mode`

Type: [**DML_CONVOLUTION_MODE**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_convolution_mode)

The mode to use for the convolution operation. [DML_CONVOLUTION_MODE_CROSS_CORRELATION](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_convolution_mode) is the behavior for required for typical inference scenarios. In contrast, [DML_CONVOLUTION_MODE_CONVOLUTION](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_convolution_mode) flips the order of elements in each filter kernel along each spatial dimension.

### `Direction`

Type: [**DML_CONVOLUTION_DIRECTION**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_convolution_direction)

The direction of the convolution operation. [DML_CONVOLUTION_DIRECTION_FORWARD](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_convolution_direction) is the primary form of convolution used for inference where a combination of [DML_CONVOLUTION_DIRECTION_FORWARD](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_convolution_direction) and [DML_CONVOLUTION_DIRECTION_BACKWARD](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_convolution_direction) are used during training.

### `DimensionCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of spatial dimensions for the convolution operation. Spatial dimensions are the lower dimensions of the convolution *FilterTensor*. For example, the width and height dimension are spatial dimensions of a 4D convolution filter tensor. This value also determines the size of the *Strides*, *Dilations*, *StartPadding*, *EndPadding*, and *OutputPadding* arrays. It should be set to 2 when *InputTensor.DimensionCount* is 4, and 3 when *InputTensor.DimensionCount* is 5.

### `Strides`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

An array containing the strides of the convolution operation. These strides are applied to the convolution filter. They are separate from the tensor strides included in [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc).

### `Dilations`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

An array containing the dilations of the convolution operation. Dilations are strides applied to the elements of the filter kernel. This has the effect of simulating a larger filter kernel by padding the internal filter kernel elements with zeros.

### `StartPadding`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

An array containing the padding values to be applied to the beginning of each spatial dimension of the filter and input tensor of the convolution operation. The start padding values are interpreted according to the *Direction* field.

### `EndPadding`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

An array containing the padding values to be applied to the end of each spatial dimension of the filter and input tensor of the convolution operation. The end padding values are interpreted according to the *Direction* field.

### `OutputPadding`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

An array containing the output padding of the convolution operation. *OutputPadding* applies a zero padding to the result of the convolution. This padding is applied to the end of each spatial dimension of the output tensor.

### `GroupCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of groups which to divide the convolution operation up into. This can be used to achieve depth-wise convolution by setting *GroupCount* equal to the input channel count, and *Direction* equal to [DML_CONVOLUTION_DIRECTION_FORWARD](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_convolution_direction). This divides the convolution up into a separate convolution per input channel.

### `FusedActivation`

Type: \_Maybenull\_ **const [DML_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_desc)\***

An optional fused activation layer to apply after the convolution. For more info, see [Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations).

## Mode interactions

Convolution mode | Convolution direction | Filter orientation
---------------------------------------|------------------------------------|------------------------------------
DML_CONVOLUTION_MODE_CROSS_CORRELATION | DML_CONVOLUTION_DIRECTION_FORWARD | filter has identity orientation
DML_CONVOLUTION_MODE_CROSS_CORRELATION | DML_CONVOLUTION_DIRECTION_BACKWARD | filter is transposed along x,y axes
DML_CONVOLUTION_MODE_CONVOLUTION | DML_CONVOLUTION_DIRECTION_FORWARD | filter is transposed along x,y axes
DML_CONVOLUTION_MODE_CONVOLUTION | DML_CONVOLUTION_DIRECTION_BACKWARD | filter has identity orientation

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*BiasTensor*, *FilterTensor*, *InputTensor*, and *OutputTensor* must have the same *DataType* and *DimensionCount*.

## Tensor support
### DML_FEATURE_LEVEL_4_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { BatchCount, InputChannelCount, [InputDepth], [InputHeight], InputWidth } | 3 to 5 | FLOAT32, FLOAT16 |
| FilterTensor | Input | { FilterBatchCount, FilterChannelCount, [FilterDepth], [FilterHeight], FilterWidth } | 3 to 5 | FLOAT32, FLOAT16 |
| BiasTensor | Optional input | { 1, OutputChannelCount, [1], [1], 1 } | 3 to 5 | FLOAT32, FLOAT16 |
| OutputTensor | Output | { BatchCount, OutputChannelCount, [OutputDepth], [OutputHeight], OutputWidth } | 3 to 5 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { BatchCount, InputChannelCount, [InputDepth], InputHeight, InputWidth } | 4 to 5 | FLOAT32, FLOAT16 |
| FilterTensor | Input | { FilterBatchCount, FilterChannelCount, [FilterDepth], FilterHeight, FilterWidth } | 4 to 5 | FLOAT32, FLOAT16 |
| BiasTensor | Optional input | { 1, OutputChannelCount, [1], 1, 1 } | 4 to 5 | FLOAT32, FLOAT16 |
| OutputTensor | Output | { BatchCount, OutputChannelCount, [OutputDepth], OutputHeight, OutputWidth } | 4 to 5 | FLOAT32, FLOAT16 |

## See also

* [Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations)