## Description

Computes the N-dimensional coordinates of all non-zero elements of the input tensor.

This operator produces an MxN matrix of values, where each row M contains an N-dimensional coordinate of a non-zero value from the input. When using **FLOAT32** or **FLOAT16** inputs, both negative and positive 0 (0.0f and -0.0f) are treated as zero for the purposes of this operator.

The operator requires that the *OutputCoordinatesTensor* has a size large enough to accommodate a worst-case scenario where every element of the input is non-zero. This operator returns the count of of non-zero elements via the *OutputCountTensor*, which callers can inspect to determine the number of coordinates written to the *OutputCoordinatesTensor*.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An input tensor.

### `OutputCountTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor that holds the count of non-zero elements in the input tensor. This tensor must be a scalar—that is, the Sizes of this tensor must all be 1. The type of this tensor must be **UINT32**.

### `OutputCoordinatesTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor that holds the N-dimensional coordinates of the input elements which are non-zero.

This tensor must have *Sizes* of `{1,1,M,N}` (if *DimensionCount* is 4), or `{1,1,1,M,N}` (if *DimensionCount* is 5), where M is the total number of elements in the *InputTensor*, and N is greater or equal to the *effective rank* of *InputTensor*, up to the *DimensionCount* of the input.

The effective rank of a tensor is determined by the *DimensionCount* of that tensor excluding leading dimensions of size 1. For example a tensor with sizes of `{1,2,3,4}` has effective rank 3, as does a tensor with sizes of `{1,1,5,5,5}`. A tensor with sizes `{1,1,1,1}` has effective rank 0.

Consider an *InputTensor* with *Sizes* of `{1,1,12,5}`. This input tensor contains 60 elements, and has an effective rank of 2. In this example all valid sizes of *OutputCoordinatesTensor* are of the form `{1,1,60,N}`, where N >= 2 but no greater than the *DimensionCount* (4 in this example).

The coordinates written into this tensor are guaranteed to be ordered by ascending element index. For example if the input tensor has 3 non-zero values at coordinates {1,0}, {1,2}, and {0,5}, the values written to the *OutputCoordinatesTensor* will be `[[0,5], [1,0], [1,2]]`.

While this tensor requires its dimension M to equal the number of elements in the input tensor, this operator will only write a maximum of OutputCount elements to this tensor. The OutputCount is returned through the scalar *OutputCountTensor*.

> [!NOTE]
> The remaining elements of this tensor beyond the OutputCount are undefined once this operator completes. You shouldn't rely on the values of these elements.

## Example

```
InputTensor: (Sizes:{1,1,2,4}, DataType:FLOAT32)
[[1.0f,  0.0f, 0.0f,  2.0f],
 [-0.0f, 3.5f, 0.0f, -5.2f]]

OutputCountTensor: (Sizes:{1,1,1,1}, DataType:UINT32)
[4]

OutputCoordinatesTensor: (Sizes:{1,1,8,3}, DataType:UINT32)
[[0, 0, 0],
 [0, 0, 3],
 [0, 1, 1],
 [0, 1, 3],
 [0, 0, 0], //
 [0, 0, 0], // Values in rows >= OutputCountTensor (4 in
 [0, 0, 0], // this case) are left undefined
 [0, 0, 0]] //
```

## Remarks

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_0`.

## Tensor support
### DML_FEATURE_LEVEL_4_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { [D0], [D1], [D2], [D3], [D4], [D5], [D6], D7 } | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputCountTensor | Output | { [1], [1], [1], [1], [1], [1], [1], 1 } | 1 to 8 | UINT32 |
| OutputCoordinatesTensor | Output | { [1], [1], [1], [1], [1], [1], M, N } | 2 to 8 | UINT32 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { [D0], D1, D2, D3, D4 } | 4 to 5 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputCountTensor | Output | { [1], 1, 1, 1, 1 } | 4 to 5 | UINT32 |
| OutputCoordinatesTensor | Output | { [1], 1, 1, M, N } | 4 to 5 | UINT32 |

## See also