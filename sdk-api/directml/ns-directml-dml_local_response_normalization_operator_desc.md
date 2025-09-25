## Description

Performs a local response normalization (LRN) function on the input. This operator performs the following computation.

```
Output = Input / (Bias + (Alpha / LocalSize) * sum(Input^2 for every Input in the local region))^Beta
```

The data type and size of the input and output tensors must be the same.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor containing the input data. This tensor's *Sizes* should be `{ BatchCount, ChannelCount, Height, Width }`.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write the results to. This tensor's *Sizes* should match the *InputTensor*.

### `CrossChannel`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the LRN layer sums across channels; otherwise, **FALSE**.

### `LocalSize`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of elements to sum over per dimension: Width, Height, and optionally Channel (if *CrossChannel* is set). This value must be at least 1.

### `Alpha`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value of the scaling parameter. A value of 0.0001 is recommended as default.

### `Beta`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value of the exponent. A value of 0.75 is recommended as default.

### `Bias`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The value of bias. A value of 1 is recommended as default.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType* and *Sizes*.

## Tensor support
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |