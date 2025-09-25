## Description

Computes backpropagation gradients for [local response normalization](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_local_response_normalization_operator_desc).

The data type and size of all tensors must be the same.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor containing the input data. This tensor's *Sizes* should be `{ BatchCount, ChannelCount, Height, Width }`.

### `InputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The incoming gradient tensor. This is typically obtained from the output of backpropagation of a preceding layer.

### `OutputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor containing the backpropagated gradients.

### `CrossChannel`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** if the LRN layer sums across channels; **FALSE** if the LRN layer sums across spatial dimensions.

### `LocalSize`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum number of elements to sum over per dimension (the local region is clipped so that all elements are within bounds). If *CrossChannel* is **TRUE**, then this is the width and height of the local region. If *CrossChannel* is **FALSE**, then this is the number of elements in the local region. This value must be at least 1.

### `Alpha`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The value of the scaling parameter. We recommend a value of 0.0001 as default.

### `Beta`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The value of the exponent. We recommend a value of 0.75 as default.

### `Bias`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The value of bias. We recommend a value of 1 as default.

## Remarks

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_1`.

## Tensor constraints
*InputGradientTensor*, *InputTensor*, and *OutputGradientTensor* must have the same *DataType* and *Sizes*.

## Tensor support
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| InputGradientTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputGradientTensor | Output | 4 | FLOAT32, FLOAT16 |

## See also