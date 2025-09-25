## Description

Performs a hardmax function on each element of *InputTensor*, placing the result into the corresponding element of *OutputTensor*.

The operator computes the hardmax (1 for the first occurrence of the largest value in the layer, and 0 for all other values) of each row in the given input.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to read from for the input. This tensor must have an *effective rank* no greater than 2. The effective rank of a tensor is the *DimensionCount* of the tensor, excluding leftmost dimensions of size 1. For example a tensor size of `{ 1, 1, BatchCount, Width }` is valid, and is equivalent to a tensor of sizes `{ BatchCount, Width }`.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the results to.

## Remarks

The operator computes the hardmax (1 for the first maximum value, and 0 for all others) values for each layer in the batch of the given input. The input is a 2-D tensor (Tensor) of size (batch_size x input_feature_dimensions). The output tensor has the same shape and contains the hardmax values of the corresponding input.

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

[DML_ARGMAX_OPERATOR_DESC structure](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_argmax_operator_desc)