## Description

Splits an input tensor along an axis into multiple output tensors.

All input and output tensors must have the same sizes, except for the split axis. The size of input tensor in the split axis determines the possible splits. For example, if the input tensor's split axis has size 3, then there are these potential splits: 1+1+1 (3 outputs), 1+2 (2 outputs), 2+1 (2 outputs), or 3 (1 output, which is simply a copy of the input tensor). The output tensors' split axis sizes must sum up to exactly the input tensor's split axis size. These constraints are illustrated in the pseudocode below.

```
splitSize = 0;

for (i = 0; i < OutputCount; i++) {
    assert(outputTensors[i]->DimensionCount == inputTensor->DimensionCount);
    for (dim = 0; dim < inputTensor->DimensionCount; dim++) {
        if (dim == Axis) { splitSize += outputTensors[i]->Sizes[dim]; }
        else { assert(outputTensors[i]->Sizes[dim] == inputTensor->Sizes[dim]); }
    }
}

assert(splitSize == inputTensor->Sizes[Axis]);
```

Splitting into a single output tensor simply produces a copy of the input tensor.

This operator is the inverse of [DML_JOIN_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_join_operator_desc).

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to split into multiple output tensors.

### `OutputCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

This field determines the size of the *OutputTensors* array. This value must be greater than 0.

### `OutputTensors`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An array containing the descriptions of the tensors split off from the input tensor. The output sizes must have the same sizes as the input tensor except for the split axis.

### `Axis`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The index of the dimension of the input tensor to split. All input and output tensors must have identical sizes in all dimensions except for this axis. This value must be in the range `[0, InputTensor.DimensionCount - 1]`.

## Examples

The following examples use this same input tensor.

```
InputTensor: (Sizes:{1, 1, 6, 2}, DataType:FLOAT32)
[[[[1, 2],
   [3, 4],
   [5, 6],
   [7, 8],
   [9, 10],
   [11, 12]]]]
```

### Example 1. Splitting axis 2

```
OutputCount: 3
Axis: 2

OutputTensors[0]: (Sizes:{1, 1, 2, 2}, DataType:FLOAT32)
[[[[1, 2],
   [3, 4]]]]

OutputTensors[1]: (Sizes:{1, 1, 1, 2}, DataType:FLOAT32)
[[[[5, 6]]]]

OutputTensors[2]: (Sizes:{1, 1, 3, 2}, DataType:FLOAT32)
[[[[7, 8],
   [9, 10],
   [11, 12]]]]
```

### Example 2. Splitting axis 3

```
OutputCount: 2
Axis: 3

OutputTensors[0]: (Sizes:{1, 1, 6, 1}, DataType:FLOAT32)
[[[[1],
   [3],
   [5],
   [7],
   [9],
   [11]]]]

OutputTensors[1]: (Sizes:{1, 1, 6, 1}, DataType:FLOAT32)
[[[[2],
   [4],
   [6],
   [8],
   [10],
   [12]]]]
```

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor* and *OutputTensors* must have the same *DataType* and *DimensionCount*.

## Tensor support

### DML_FEATURE_LEVEL_4_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputTensors | Array of outputs | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensors | Array of outputs | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensors | Array of outputs | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16, INT32, INT16, UINT32, UINT16 |
| OutputTensors | Array of outputs | 4 | FLOAT32, FLOAT16, INT32, INT16, UINT32, UINT16 |