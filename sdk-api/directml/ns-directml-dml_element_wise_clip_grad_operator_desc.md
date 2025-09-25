## Description

Computes backpropagation gradients for [element-wise clip](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_element_wise_clip_operator_desc).

```
f(x, gradient) = if x <= Min then 0
                 if x >= Max then 0
                 else        then gradient
```

This operator supports in-place execution, meaning `OutputTensor` is permitted to alias *InputTensor* during binding.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The input feature tensor. This is typically the same tensor that was provided as the *InputTensor* to [DML_ELEMENT_WISE_CLIP_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_element_wise_clip_operator_desc) in the forward pass.

### `InputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The incoming gradient tensor. This is typically obtained from the output of backpropagation of a preceding layer. Typically this tensor would have the same sizes as the *output* of the corresponding **DML_OPERATOR_ELEMENT_WISE_CLIP** in the forward pass.

### `OutputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor containing the backpropagated gradients. Typically this tensor would have the same sizes as the *input* of the corresponding **DML_OPERATOR_ELEMENT_WISE_CLIP** in the forward pass.

### `Min`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The minimum value. If x is at or below this value, then the gradient result is 0.

### `Max`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The maximum value. If x is at or above this value, then the gradient result is 0.

## Remarks

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_1`.

## Tensor constraints
*InputGradientTensor*, *InputTensor*, and *OutputGradientTensor* must have the same *DataType*, *DimensionCount*, and *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_5_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| InputGradientTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputGradientTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| InputGradientTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputGradientTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

## See also