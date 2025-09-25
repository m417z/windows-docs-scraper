## Description

Performs a natural log-of-softmax activation function on each element of *InputTensor*, placing the result into the corresponding element of *OutputTensor*.

```
// Let x_i be the current value in the axis, and j be the total number of elements along that axis.
f(x_i) = ln(exp(x_i) / sum(exp(x_0), ..., exp(x_j)))
```

Where exp(x) is the natural exponentiation function, and ln(x) is the natural logarithm.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The input tensor to read from. This tensor must have an *effective rank* no greater than 2. The effective rank of a tensor is the *DimensionCount* of the tensor, excluding leftmost dimensions of size 1. For example a tensor size of `{ 1, 1, BatchCount, Width }` is valid, and is equivalent to a tensor of sizes `{ BatchCount, Width }`.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the results to.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType*, *DimensionCount*, and *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_2_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 to 5 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 to 5 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |

## See also

[DML_ACTIVATION_SOFTMAX_OPERATOR_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_activation_softmax_operator_desc)

[DML_ARGMAX_OPERATOR_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_argmax_operator_desc)