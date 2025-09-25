## Description

Extracts a single subregion (a "slice") of an input tensor.

The elements copied in the slice are determined using three values for each dimension.

- The *offset* marks the first element to copy in a dimension.
- The *size* marks the number of elements to copy in a dimension.
- The *stride* indicates the element increment or step in a dimension.

The provided *Offsets*, *Sizes*, and *Strides* must only copy elements that are within the bounds of the input tensor (out-of-bounds reads are not permitted). The *Sizes* of the slice must exactly match the output tensor sizes. In general, the elements copied are calculated as follows.

```
OutputTensor[OutputCoordinates] = InputTensor[Offsets + Strides * OutputCoordinates]
```

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to extract slices from.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write the sliced data results to.

### `DimensionCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of dimensions. This field determines the size of the *Offsets*, *Sizes*, and *Strides* arrays. This value must match the *DimensionCount* of the input and output tensors. This value must be between 1 and 8, inclusively, starting from `DML_FEATURE_LEVEL_3_0`; earlier feature levels require a value of either 4 or 5.

### `Offsets`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

An array containing the slice's start along each dimension of the input tensor, in elements.

### `Sizes`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

An array containing the slice's size along each dimension, in elements. The values in this array must match the sizes specified in the output tensor.

### `Strides`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

An array containing the slice's stride along each dimension of the input tensor, in elements. A stride larger than 1 indicates that elements of the input tensor may be skipped (for example, a stride of 2 will select every second element along the dimension).

## Examples

The following examples use the same input tensor:

```
InputTensor: (Sizes:{1, 1, 4, 4}, DataType:FLOAT32)
[[[[ 1,  2,  3,  4],
   [ 5,  6,  7,  8],
   [ 9, 10, 11, 12],
   [13, 14, 15, 16]]]]
```

### Example 1. Contiguous slice

```
Offsets = {0, 0, 1, 2}
Sizes   = {1, 1, 3, 2}
Strides = {1, 1, 1, 1}

OutputTensor: (Sizes:{1, 1, 3, 2}, DataType:FLOAT32)
[[[[ 7,  8],
   [11, 12],
   [15, 16]]]]
```

### Example 2. Strided slice

```
Offsets = {0, 0, 1, 0}
Sizes   = {1, 1, 2, 2}
Strides = {1, 1, 2, 3}

OutputTensor: (Sizes:{1, 1, 2, 2}, DataType:FLOAT32)
[[[[ 5,  8],
   [13, 16]]]]
```

## Remarks
A newer version of this operator, [DML_SLICE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_slice1_operator_desc), was introduced in `DML_FEATURE_LEVEL_2_1`.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType* and *DimensionCount*.

## Tensor support

### DML_FEATURE_LEVEL_4_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 to 5 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 4 to 5 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 to 5 | FLOAT32, FLOAT16, INT32, INT16, UINT32, UINT16 |
| OutputTensor | Output | 4 to 5 | FLOAT32, FLOAT16, INT32, INT16, UINT32, UINT16 |