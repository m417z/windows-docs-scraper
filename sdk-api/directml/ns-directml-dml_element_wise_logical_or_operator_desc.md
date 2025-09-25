## Description

Performs a logical OR on each pair of corresponding elements of the input tensors, placing the result into the corresponding element of *OutputTensor*.

```
f(a, b) = (a || b)
```

This operator supports in-place execution, meaning that *OutputTensor* is permitted to alias one of the input tensors during binding.

## Members

### `ATensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the left-hand side inputs.

### `BTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the right-hand side inputs.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the results to.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*ATensor*, *BTensor*, and *OutputTensor* must have the same *DataType*, *DimensionCount*, and *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| ATensor | Input | 1 to 8 | UINT32, UINT8 |
| BTensor | Input | 1 to 8 | UINT32, UINT8 |
| OutputTensor | Output | 1 to 8 | UINT32, UINT8 |

### DML_FEATURE_LEVEL_2_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| ATensor | Input | 4 | UINT32, UINT8 |
| BTensor | Input | 4 | UINT32, UINT8 |
| OutputTensor | Output | 4 | UINT32, UINT8 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| ATensor | Input | 4 | UINT32 |
| BTensor | Input | 4 | UINT32 |
| OutputTensor | Output | 4 | UINT32 |