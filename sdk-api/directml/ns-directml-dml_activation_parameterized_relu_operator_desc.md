## Description

Performs a parameterized rectified linear unit (ReLU) activation function on every element in *InputTensor*, placing the result into the corresponding element of *OutputTensor*.

```
f(x, slope) = x,         if x >= 0
              slope * x, otherwise
```

This operator supports in-place execution, meaning that the output tensor is permitted to alias *InputTensor* during binding.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The input tensor to read from.

### `SlopeTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the slope for each corresponding value of the input.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the results to.

## See also

[DML_ACTIVATION_RELU_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_activation_relu_operator_desc)

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor*, *OutputTensor*, and *SlopeTensor* must have the same *DataType*, *DimensionCount*, and *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_5_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8 |
| SlopeTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| SlopeTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_2_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 to 5 | FLOAT32, FLOAT16 |
| SlopeTensor | Input | 4 to 5 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 to 5 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| SlopeTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |