## Description

Performs a logical right shift of each element of *ATensor* by a number of bits given by the corresponding element of *BTensor*, placing the result into the corresponding element of *OutputTensor*.

```
f(a, b) = (a >> b)
```

The bitwise operation is applied to tensor data in its native encoding. Therefore, the tensor data type is ignored except for determining the width of each element.

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
This operator was introduced in `DML_FEATURE_LEVEL_2_1`.

## Tensor constraints
*ATensor*, *BTensor*, and *OutputTensor* must have the same *DataType*, *DimensionCount*, and *Sizes*.

## Tensor support

### DML_FEATURE_LEVEL_4_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| ATensor | Input | 1 to 8 | UINT64, UINT32, UINT16, UINT8 |
| BTensor | Input | 1 to 8 | UINT64, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| ATensor | Input | 1 to 8 | UINT32, UINT16, UINT8 |
| BTensor | Input | 1 to 8 | UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| ATensor | Input | 4 | UINT32, UINT16, UINT8 |
| BTensor | Input | 4 | UINT32, UINT16, UINT8 |
| OutputTensor | Output | 4 | UINT32, UINT16, UINT8 |