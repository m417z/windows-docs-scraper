## Description

Concatenates an array of input tensors along a specified axis.

Input tensors may only be joined if their sizes are identical in all dimensions except for the join axis, which may contain any non-zero size. The output sizes are equal to the input sizes except for the join axis, which is the sum of all inputs' join axis size. These constraints are illustrated in the pseudocode below.

```
joinSize = 0;

for (i = 0; i < InputCount; i++) {
    assert(inputTensors[i]->DimensionCount == outputTensor->DimensionCount);
    for (dim = 0; dim < outputTensor->DimensionCount; dim++) {
        if (dim == Axis) { joinSize += inputTensors[i]->Sizes[dim]; }
        else { assert(inputTensors[i]->Sizes[dim] == outputTensor->Sizes[dim]); }
    }
}

assert(joinSize == outputTensor->Sizes[Axis]);
```

Joining a single input tensor simply produces a copy of the input tensor.

This operator is the inverse of [DML_SPLIT_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_split_operator_desc).

## Members

### `InputCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

This field determines the size of the *InputTensors* array. This value must be greater than 0.

### `InputTensors`

Type: \_Field\_size\_(InputCount) **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An array containing the descriptions of the tensors to join into a single output tensor. All input tensors in this array must have the same sizes except for the join axis, which may have any non-zero value.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write the joined input tensors into. The output sizes must have the same sizes as all input tensors except for the join axis, which must be equal to the sum of all inputs' join axis size.

### `Axis`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The index of the dimension of the input tensors to join. All input and output tensors must have identical sizes in all dimensions except for this axis. This value must be in the range `[0, OutputTensor.DimensionCount - 1]`.

## Examples

### Example 1. Joining tensors with only one possible axis

In this example, the tensors may only be joined along the fourth dimension (axis 3). Joining any other axis is not possible, since the tensors' size in the fourth dimension do not match.

```
InputCount: 2
Axis: 3

InputTensors[0]: (Sizes:{1, 1, 2, 3}, DataType:FLOAT32)
[[[[ 1,  2,  3],
   [ 4,  5,  6]]]]

InputTensors[1]: (Sizes:{1, 1, 2, 4}, DataType:FLOAT32)
[[[[ 7,  8,  9, 10],
   [11, 12, 13, 14]]]]

OutputTensor: (Sizes:{1, 1, 2, 7}, DataType:FLOAT32)
[[[[ 1,  2,  3,  7,  8,  9, 10],
   [ 4,  5,  6, 11, 12, 13, 14]]]]
```

### Example 2. Joining tensors with multiple possible axes:

The following examples use the same input tensors. Since all inputs have the same size in all dimensions, they can be joined along any dimension.

```
InputCount: 3

InputTensors[0]: (Sizes:{1, 1, 2, 2}, DataType:FLOAT32)
[[[[1, 2],
   [3, 4]]]]

InputTensors[1]: (Sizes:{1, 1, 2, 2}, DataType:FLOAT32)
[[[[5, 6],
   [7, 8]]]]

InputTensors[2]: (Sizes:{1, 1, 2, 2}, DataType:FLOAT32)
[[[[9, 10],
   [11, 12]]]]
```

Joining axis 1:

```
Axis: 1

OutputTensor: (Sizes:{1, 3, 2, 2}, DataType:FLOAT32)
[[[[1, 2],
   [3, 4]],

  [[5, 6],
   [7, 8]],

  [[9, 10],
   [11, 12]]]]
```

Joining axis 2:

```
Axis: 2

OutputTensor: (Sizes:{1, 1, 6, 2}, DataType:FLOAT32)
[[[[1, 2],
   [3, 4],
   [5, 6],
   [7, 8],
   [9, 10],
   [11, 12]]]]
```

Joining axis 3:

```
Axis: 3

OutputTensor: (Sizes:{1, 1, 2, 6}, DataType:FLOAT32)
[[[[1, 2, 5, 6, 9, 10],
   [3, 4, 7, 8, 11, 12]]]]
```

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensors* and *OutputTensor* must have the same *DataType* and *DimensionCount*.

## Tensor support

### DML_FEATURE_LEVEL_4_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensors | Array of inputs | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensors | Array of inputs | 4 to 5 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 4 to 5 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensors | Array of inputs | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensors | Array of inputs | 4 | FLOAT32, FLOAT16, INT32, INT16, UINT32, UINT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT32, INT16, UINT32, UINT16 |