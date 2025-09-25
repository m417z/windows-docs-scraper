## Description

Performs a batch normalization on the input. This operator performs the following computation: `Output = FusedActivation(Scale * ((Input - Mean) / sqrt(Variance + Epsilon)) + Bias + FusedAdd)`.

Any dimension in *ScaleTensor* and *BiasTensor* can be set to 1, and be automatically broadcast to match *InputTensor*, but otherwise must equal the corresponding dimension's size from *InputTensor*. *MeanTensor* and *VarianceTensor* are computed on the input across the set of dimensions for which *ScaleTensor* and *BiasTensor* sizes equal one.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the Input data.

### `ScaleTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the Scale data.

### `BiasTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the Bias data.

### `FusedAddTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing data that is added to the result prior to FusedActivation, if any.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor to write the results to.

### `OutputMeanTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor to write the mean of the input to.

### `OutputVarianceTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor to write the variance of the input to.

### `Epsilon`

Type: [**FLOAT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The epsilon value to use to avoid division by zero.

### `FusedActivation`

Type: \_Maybenull\_ **const [DML_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_desc)\***

An optional fused activation layer to apply after the normalization. For more info, see [Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations).

## Remarks

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_4_1`.

## Tensor constraints
* *BiasTensor*, *FusedAddTensor*, *InputTensor*, *OutputMeanTensor*, *OutputTensor*, *OutputVarianceTensor*, and *ScaleTensor* must have the same *DataType* and *DimensionCount*.
* *BiasTensor*, *OutputMeanTensor*, *OutputVarianceTensor*, and *ScaleTensor* must have the same *Sizes*.
* *FusedAddTensor*, *InputTensor*, and *OutputTensor* must have the same *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_4_1 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { InputDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| ScaleTensor | Input | { ScaleDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| BiasTensor | Input | { ScaleDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| FusedAddTensor | Optional input | { InputDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | { InputDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| OutputMeanTensor | Output | { ScaleDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |
| OutputVarianceTensor | Output | { ScaleDimensions[] } | 1 to 8 | FLOAT32, FLOAT16 |

## See also

* [Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations)