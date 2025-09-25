## Description

Inverts a max-pooling operation (see [DML_MAX_POOLING_OPERATOR1_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling1_operator_desc) for details) by filling the output tensor *OutputTensor* with the values in the input tensor *InputTensor*, as obtained from a max-pooling operation, according to the index values provided in the *IndicesTensor*. The elements in the output tensor untouched by this process are left with zero values.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An input tensor of *Sizes* `{ Batch, Channel, Height, Width }`. The tensor values are obtained from the values in the *OutputTensor* of a max-pooling operation.

### `IndicesTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor of indices to the output tensor *OutputTensor* for the values given in the input tensor *InputTensor*. These index values are zero-based, and treat the output tensor as a contiguous one-dimensional array. Both the *InputTensor* and *IndicesTensor* have the same tensor sizes. The tensor values are obtained from the *OutputIndicesTensor* of a max-pooling operation.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor of the same number of dimensions as the input tensor.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_0`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType*.

## Tensor support
### DML_FEATURE_LEVEL_5_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| IndicesTensor | Input | 4 | UINT64, UINT32 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| IndicesTensor | Input | 4 | UINT32 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |