## Description

Performs an element-wise scale-and-bias function, `Output = Scale * Input + Bias`. This operator is similar to using an [DML_ELEMENT_WISE_IDENTITY_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_element_wise_identity_operator_desc) with a scale and bias, except that **DML_VALUE_SCALE_2D_OPERATOR_DESC** applies a different bias for each channel, rather than a single bias for the entire tensor.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the Input data. This tensor's dimensions should be `{ BatchCount, ChannelCount, Height, Width }`.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor with which to write the results to. This tensor's dimensions should match the *InputTensor*'s dimensions.

### `Scale`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Scale value to be applied to all input values.

### `ChannelCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

This field determines the size of the Bias array. This field must be set to either 1 or 3, and must also match the size of the Channel dimension of the input tensor.

### `Bias`

Type: **const [FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

An array of *FLOAT* values containing the bias term for each dimension of the input tensor.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType* and *Sizes*.

## Tensor support
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |