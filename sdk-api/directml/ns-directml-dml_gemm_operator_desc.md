## Description

Performs a general matrix multiplication function of the form `Output = FusedActivation(Alpha * TransA(A) x TransB(B) + Beta * C)`, where `x` denotes matrix multiplication, and `*` denotes multiplication with a scalar.

This operator requires 4D tensors with layout `{ BatchCount, ChannelCount, Height, Width }`, and it will perform BatchCount * ChannelCount number of independent matrix multiplications.

For example, if *ATensor* has *Sizes* of `{ BatchCount, ChannelCount, M, K }`, and *BTensor* has *Sizes* of `{ BatchCount, ChannelCount, K, N }`, and *OutputTensor* has *Sizes* of `{ BatchCount, ChannelCount, M, N }`, then this operator performs BatchCount * ChannelCount independent matrix multiplications of dimensions {M,K} x {K,N} = {M,N}.

## Members

### `ATensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the A matrix. This tensor's *Sizes* should be `{ BatchCount, ChannelCount, M, K }` if *TransA* is [DML_MATRIX_TRANSFORM_NONE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_matrix_transform), or `{ BatchCount, ChannelCount, K, M }` if *TransA* is **DML_MATRIX_TRANSFORM_TRANSPOSE**.

### `BTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the B matrix. This tensor's *Sizes* should be `{ BatchCount, ChannelCount, K, N }` if *TransB* is [DML_MATRIX_TRANSFORM_NONE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_matrix_transform), or `{ BatchCount, ChannelCount, N, K }` if *TransB* is **DML_MATRIX_TRANSFORM_TRANSPOSE**.

### `CTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the C matrix, or `nullptr`. Values default to 0 when not provided. If provided, this tensor's *Sizes* should be `{ BatchCount, ChannelCount, M, N }`.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write the results to. This tensor's *Sizes* are `{ BatchCount, ChannelCount, M, N }`.

### `TransA`

Type: [**DML_MATRIX_TRANSFORM**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_matrix_transform)

The transform to be applied to *ATensor*; either a transpose, or no transform.

### `TransB`

Type: [**DML_MATRIX_TRANSFORM**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_matrix_transform)

The transform to be applied to *BTensor*; either a transpose, or no transform.

### `Alpha`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value of the scalar multiplier for the product of inputs *ATensor* and *BTensor*.

### `Beta`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value of the scalar multiplier for the optional input *CTensor*. If *CTensor* is not provided, then this value is ignored.

### `FusedActivation`

Type: \_Maybenull\_ **const [DML_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_desc)\***

An optional fused activation layer to apply after the GEMM. For more info, see [Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations).

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
* *ATensor*, *BTensor*, *CTensor*, and *OutputTensor* must have the same *DataType* and *DimensionCount*.
* *CTensor* and *OutputTensor* must have the same *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_4_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| ATensor | Input | { [BatchCount], [ChannelCount], M, K } | 2 to 4 | FLOAT32, FLOAT16 |
| BTensor | Input | { [BatchCount], [ChannelCount], K, N } | 2 to 4 | FLOAT32, FLOAT16 |
| CTensor | Optional input | { [BatchCount], [ChannelCount], M, N } | 2 to 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | { [BatchCount], [ChannelCount], M, N } | 2 to 4 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| ATensor | Input | { BatchCount, ChannelCount, M, K } | 4 | FLOAT32, FLOAT16 |
| BTensor | Input | { BatchCount, ChannelCount, K, N } | 4 | FLOAT32, FLOAT16 |
| CTensor | Optional input | { BatchCount, ChannelCount, M, N } | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | { BatchCount, ChannelCount, M, N } | 4 | FLOAT32, FLOAT16 |

## See also

* [Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations)