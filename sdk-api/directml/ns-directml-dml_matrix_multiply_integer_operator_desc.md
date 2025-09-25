## Description

Performs a matrix multiplication function on integer data.

This operator requires the matrix multiply input tensors to be 4D, which are formatted as `{ BatchCount, ChannelCount, Height, Width }`. The matrix multiply operator will perform BatchCount * ChannelCount number of independent matrix multiplications.

For example, if *ATensor* has *Sizes* of `{ BatchCount, ChannelCount, M, K }`, and *BTensor* has *Sizes* of `{ BatchCount, ChannelCount, K, N }`, and *OutputTensor* has *Sizes* of `{ BatchCount, ChannelCount, M, N }`, then the matrix multiply operator will perform BatchCount * ChannelCount independent matrix multiplications of dimensions {M,K} x {K,N} = {M,N}.

## Members

### `ATensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the A data. This tensor's dimensions should be `{ BatchCount, ChannelCount, M, K }`.

### `AZeroPointTensor`

Type: _Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing the ATensor zero point data. The expected dimensions of the `AZeroPointTensor` are `{ 1, 1, 1, 1 }` if per tensor quantization is required, or `{ 1, 1, M, 1 }` if per-row quantization is required. These zero point values are used for dequantizing the *ATensor* values.

### `BTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the B data. This tensor's dimensions should be `{ BatchCount, ChannelCount, K, N }`.

### `BZeroPointTensor`

Type: _Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing the *BTensor* zero point data. The expected dimensions of the `BZeroPointTensor` are `{ 1, 1, 1, 1 }` if per tensor quantization is required, or `{ 1, 1, 1, N }` if per column quantization is required. These zero point values are used for dequantizing the BTensor values.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor with which to write the results to. This tensor's dimensions are `{ BatchCount, ChannelCount, M, N }`.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_2_1`.

## Tensor constraints
* *ATensor*, *BTensor*, and *OutputTensor* must have the same *DimensionCount*.
* *BTensor* and *BZeroPointTensor* must have the same *DataType*.
* *ATensor* and *AZeroPointTensor* must have the same *DataType*.

## Tensor support
### DML_FEATURE_LEVEL_5_2 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| ATensor | Input | { [BatchCount], [ChannelCount], M, K } | 2 to 4 | INT8, UINT8 |
| AZeroPointTensor | Optional input | { [1], [1], AZeroPointCount, [1] } | 1 to 4 | INT8, UINT8 |
| BTensor | Input | { [BatchCount], [ChannelCount], K, N } | 2 to 4 | INT8, UINT8 |
| BZeroPointTensor | Optional input | { [1], [1], [1], BZeroPointCount } | 1 to 4 | INT8, UINT8 |
| OutputTensor | Output | { [BatchCount], [ChannelCount], M, N } | 2 to 4 | INT32 |

### DML_FEATURE_LEVEL_4_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| ATensor | Input | { [BatchCount], [ChannelCount], M, K } | 2 to 4 | INT8, UINT8 |
| AZeroPointTensor | Optional input | { [1], [1], AZeroPointCount, [1] } | 1 to 4 | INT8, UINT8 |
| BTensor | Input | { [BatchCount], [ChannelCount], K, N } | 2 to 4 | INT8, UINT8 |
| BZeroPointTensor | Optional input | { [1], [1], 1, BZeroPointCount } | 2 to 4 | INT8, UINT8 |
| OutputTensor | Output | { [BatchCount], [ChannelCount], M, N } | 2 to 4 | INT32 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| ATensor | Input | { BatchCount, ChannelCount, M, K } | 4 | INT8, UINT8 |
| AZeroPointTensor | Optional input | { 1, 1, AZeroPointCount, 1 } | 4 | INT8, UINT8 |
| BTensor | Input | { BatchCount, ChannelCount, K, N } | 4 | INT8, UINT8 |
| BZeroPointTensor | Optional input | { 1, 1, 1, BZeroPointCount } | 4 | INT8, UINT8 |
| OutputTensor | Output | { BatchCount, ChannelCount, M, N } | 4 | INT32 |