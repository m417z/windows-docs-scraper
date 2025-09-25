## Description

Performs an Lp-normalization function along the specified axis of the input tensor.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor containing the input data.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write the results to. This tensor's *Sizes* should match the *InputTensor*.

### `Axis`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The axis on which to apply normalization.

### `Epsilon`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The epsilon value to use to avoid division by zero. A value of 0.00001 is recommended as default.

### `P`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The order of the normalization (either 1 or 2).

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints

*InputTensor* and *OutputTensor* must have the same *DataType*, *DimensionCount*, and *Sizes*.

## Tensor support

### DML_FEATURE_LEVEL_3_1 and above

| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_1_0 and above

| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |