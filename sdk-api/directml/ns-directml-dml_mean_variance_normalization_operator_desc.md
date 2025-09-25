## Description

Performs a mean variance normalization function on the input tensor. This operator will calculate the mean and variance of the input tensor to perform normalization. This operator performs the following computation.

```
Output = FusedActivation(Scale * ((Input - Mean) / sqrt(Variance + Epsilon)) + Bias).
```

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the Input data. This tensor's dimensions should be `{ BatchCount, ChannelCount, Height, Width }`.

### `ScaleTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing the Scale data. This tensor's dimensions should be `{ BatchCount, ChannelCount, Height, Width }`. Any dimension can be replaced with 1 to broadcast in that dimension. If **DML_FEATURE_LEVEL** is less than **DML_FEATURE_LEVEL_5_2**, then this tensor is required if *BiasTensor* is present. If **DML_FEATURE_LEVEL** is greater than or equal to **DML_FEATURE_LEVEL_5_2**, then this tensor can be null regardless of the value of *BiasTensor*.

### `BiasTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing the bias data. This tensor's dimensions should be `{ BatchCount, ChannelCount, Height, Width }`. Any dimension can be replaced with 1 to broadcast in that dimension. If **DML_FEATURE_LEVEL** is less than **DML_FEATURE_LEVEL_5_2**, then this tensor is required if *ScaleTensor* is present. If **DML_FEATURE_LEVEL** is greater than or equal to **DML_FEATURE_LEVEL_5_2**, then this tensor can be null regardless of the value of *ScaleTensor*.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor to write the results to. This tensor's dimensions are `{ BatchCount, ChannelCount, Height, Width }`.

### `CrossChannel`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

When **TRUE**, the MeanVariance layer includes channels in the Mean and Variance calculations, meaning they are normalized across axes `{ChannelCount, Height, Width}`. When **FALSE**, Mean and Variance calculations are normalized across axes `{Height, Width}` with each channel being independent.

### `NormalizeVariance`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

**TRUE** if the Normalization layer includes Variance in the normalization calculation. Otherwise, **FALSE**. If **FALSE**, then normalization equation is `Output = FusedActivation(Scale * (Input - Mean) + Bias)`.

### `Epsilon`

Type: **[FLOAT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The epsilon value to use to avoid division by zero. A value of 0.00001 is recommended as default.

### `FusedActivation`

Type: \_Maybenull\_ **const [DML_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_desc)\***

An optional fused activation layer to apply after the normalization. For more info, see [Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations).

## Remarks
A newer version of this operator, [DML_MEAN_VARIANCE_NORMALIZATION1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_mean_variance_normalization1_operator_desc), was introduced in `DML_FEATURE_LEVEL_2_1`.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
* *InputTensor* and *OutputTensor* must have the same *Sizes*.
* *BiasTensor*, *InputTensor*, *OutputTensor*, and *ScaleTensor* must have the same *DataType*.

## Tensor support
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { BatchCount, ChannelCount, Height, Width } | 4 | FLOAT32, FLOAT16 |
| ScaleTensor | Optional input | { ScaleBatchCount, ScaleChannelCount, ScaleHeight, ScaleWidth } | 4 | FLOAT32, FLOAT16 |
| BiasTensor | Optional input | { BiasBatchCount, BiasChannelCount, BiasHeight, BiasWidth } | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | { BatchCount, ChannelCount, Height, Width } | 4 | FLOAT32, FLOAT16 |

## See also

* [Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations)