## Description

Constructs an output tensor by tiling the input tensor. The elements in each dimension of the input tensor are repeated by a multiple in the *Repeats* array.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to read from, which contains the elements to be tiled.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write to, which will hold the tiled output. For each dimension `i` in `[0, InputTensor.DimensionCount-1]`, the output size is calculated as `OutputTensor.Sizes[i] = InputTensor.Sizes[i] * Repeats[i]`. This tensor must have the same *DimensionCount* as the input tensor.

### `RepeatsCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

This field determines the size of the *Repeats* array. This value must be the same as the *InputTensor.DimensionCount*.

### `Repeats`

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

Each value in this array corresponds to one of the input tensor's dimensions (in order). Each value is the number of tiled copies to make of that dimension. Values must be larger than 0.

## Examples

```
RepeatsCount: 4
Repeats: {1, 1, 3, 3}

InputTensor: (Sizes:{1, 1, 2, 3}, DataType:FLOAT32)
[[[[1, 2, 3]
   [4, 5, 6]]]]

InputTensor: (Sizes:{1, 1, 6, 9}, DataType:FLOAT32)
[[[[1, 2, 3, 1, 2, 3, 1, 2, 3]
   [4, 5, 6, 4, 5, 6, 4, 5, 6]
   [1, 2, 3, 1, 2, 3, 1, 2, 3]
   [4, 5, 6, 4, 5, 6, 4, 5, 6]
   [1, 2, 3, 1, 2, 3, 1, 2, 3]
   [4, 5, 6, 4, 5, 6, 4, 5, 6]]]]
```

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType*.

## Tensor support

### DML_FEATURE_LEVEL_4_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_1 and above

| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_2_1 and above

| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_1_0 and above

| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |