## Description

Performs a convolution of the *FilterTensor* with the *InputTensor*. This operator performs forward convolution on integer data. Optional zero point tensors can also be used to subtract zero point values from the input and filter tensor.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the input data. The expected dimensions of the *InputTensor* are `{ BatchCount, InputChannelCount, InputHeight, InputWidth }`.

### `InputZeroPointTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing the input zero point data. The expected dimensions of the *InputZeroPointTensor* are `{ 1, 1, 1, 1 }`.

### `FilterTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the filter data. The expected dimensions of the *FilterTensor* are `{ FilterBatchCount, FilterChannelCount, FilterHeight, FilterWidth }`.

### `FilterZeroPointTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing the filter zero point data. The expected dimensions of the *FilterZeroPointTensor* are `{ 1, 1, 1, 1 }` if per tensor quantization is required, or `{ 1, OutputChannelCount, 1, 1 }` if per-channel quantization is required.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write the results to. The expected dimensions of the *OutputTensor* are `{ BatchCount, OutputChannelCount, OutputHeight, OutputWidth }`.

### `DimensionCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of spatial dimensions for the convolution operation. Spatial dimensions are the lower dimensions of the convolution *FilterTensor*. This value also determines the size of the *Strides*, *Dilations*, *StartPadding*, and *EndPadding* arrays. Only a value of 2 is supported.

### `Strides`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

An array containing the strides of the convolution operation. These strides are applied to the convolution filter. They are separate from the tensor strides included in [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc).

### `Dilations`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

An array containing the dilations of the convolution operation. Dilations are strides applied to the elements of the filter kernel. This has the effect of simulating a larger filter kernel by padding the internal filter kernel elements with zeros.

### `StartPadding`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

An array containing the padding values to be applied to the beginning of each spatial dimension of the filter and input tensor of the convolution operation.

### `EndPadding`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

An array containing the padding values to be applied to the end of each spatial dimension of the filter and input tensor of the convolution operation.

### `GroupCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of groups which to divide the convolution operation up into. *GroupCount* can be used to achieve depth-wise convolution by setting the *GroupCount* equal to the input channel count. This divides the convolution up into a separate convolution per input channel.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_2_1`.

## Tensor constraints
* *FilterZeroPointTensor* and *InputZeroPointTensor* must have the same *DimensionCount*.
* *FilterTensor*, *InputTensor*, and *OutputTensor* must have the same *DimensionCount*.
* *InputTensor* and *InputZeroPointTensor* must have the same *DataType*.
* *FilterTensor* and *FilterZeroPointTensor* must have the same *DataType*.

# Tensor support
### DML_FEATURE_LEVEL_4_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { BatchCount, InputChannelCount, [InputHeight], InputWidth } | 3 to 4 | INT8, UINT8 |
| InputZeroPointTensor | Optional input | { [1], [1], [1], 1 } | 1 to 4 | INT8, UINT8 |
| FilterTensor | Input | { FilterBatchCount, FilterChannelCount, [FilterHeight], FilterWidth } | 3 to 4 | INT8, UINT8 |
| FilterZeroPointTensor | Optional input | { [1], FilterZeroPointChannelCount, [1], [1] } | 1 to 4 | INT8, UINT8 |
| OutputTensor | Output | { BatchCount, OutputChannelCount, [OutputHeight], OutputWidth } | 3 to 4 | INT32 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { BatchCount, InputChannelCount, InputHeight, InputWidth } | 4 | INT8, UINT8 |
| InputZeroPointTensor | Optional input | { 1, 1, 1, 1 } | 4 | INT8, UINT8 |
| FilterTensor | Input | { FilterBatchCount, FilterChannelCount, FilterHeight, FilterWidth } | 4 | INT8, UINT8 |
| FilterZeroPointTensor | Optional input | { 1, FilterZeroPointChannelCount, 1, 1 } | 4 | INT8, UINT8 |
| OutputTensor | Output | { BatchCount, OutputChannelCount, OutputHeight, OutputWidth } | 4 | INT32 |