## Description

Performs a batch normalization on the input. This operator performs the following computation: `Output = FusedActivation(Scale * ((Input - Mean) / sqrt(Variance + Epsilon)) + Bias)`.

Any dimension in *MeanTensor*, *VarianceTensor*, *ScaleTensor*, and *BiasTensor* can be set to 1, and be automatically broadcast to match *InputTensor*, but otherwise must equal the corresponding dimension's size from *InputTensor*.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the Input data.

### `MeanTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the Mean data.

### `VarianceTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the Variance data.

### `ScaleTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the Scale data.

### `BiasTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the Bias data.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor to write the results to.

### `Spatial`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** to specify that locations are spatial, otherwise **FALSE**. Setting this to **FALSE** will require the Width and Height dimensions of *MeanTensor* and *VarianceTensor* to not be broadcast. This parameter was deprecated in **DML_FEATURE_LEVEL_4_0**, and has no effect.

### `Epsilon`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The epsilon value to use to avoid division by zero.

### `FusedActivation`

Type: \_Maybenull\_ **const [DML_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_desc)\***

An optional fused activation layer to apply after the normalization. For more info, see [Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations).

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
* *BiasTensor*, *InputTensor*, *MeanTensor*, *OutputTensor*, *ScaleTensor*, and *VarianceTensor* must have the same *DataType* and *DimensionCount*.
* *InputTensor* and *OutputTensor* must have the same *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_3_1 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { InputDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| MeanTensor | Input | { MeanDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| VarianceTensor | Input | { VarianceDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| ScaleTensor | Input | { ScaleDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| BiasTensor | Input | { BiasDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | { InputDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { InputDimensions[] } | 4 | FLOAT32, FLOAT16 |
| MeanTensor | Input | { MeanDimensions[] } | 4 | FLOAT32, FLOAT16 |
| VarianceTensor | Input | { VarianceDimensions[] } | 4 | FLOAT32, FLOAT16 |
| ScaleTensor | Input | { ScaleDimensions[] } | 4 | FLOAT32, FLOAT16 |
| BiasTensor | Input | { BiasDimensions[] } | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | { InputDimensions[] } | 4 | FLOAT32, FLOAT16 |

## See also

* [Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations)