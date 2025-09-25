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

An optional tensor containing the Scale data.

If **DML_FEATURE_LEVEL** is less than **DML_FEATURE_LEVEL_4_0**, then this tensor's dimensions should be `{ ScaleBatchCount, ChannelCount, ScaleHeight, ScaleWidth }`. The dimensions ScaleBatchCount, ScaleHeight, and ScaleWidth should either match *InputTensor*, or be set to 1 to automatically broadcast those dimensions across the input.

If **DML_FEATURE_LEVEL** is greater than or equal to **DML_FEATURE_LEVEL_4_0**, then any dimension can be set to 1, and be automatically broadcast to match *InputTensor*.

If **DML_FEATURE_LEVEL** is less than **DML_FEATURE_LEVEL_5_2**, then this tensor is required if *BiasTensor* is present. If **DML_FEATURE_LEVEL** is greater than or equal to **DML_FEATURE_LEVEL_5_2**, then this tensor can be null regardless of the value of *BiasTensor*.

### `BiasTensor`

Type: \_Maybenull\_ **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An optional tensor containing the Bias data.

If **DML_FEATURE_LEVEL** is less than **DML_FEATURE_LEVEL_4_0**, then this tensor's dimensions should be `{ BiasBatchCount, ChannelCount, BiasHeight, BiasWidth }`. The dimensions BiasBatchCount, BiasHeight, and BiasWidth should either match *InputTensor*, or be set to 1 to automatically broadcast those dimensions across the input.

If **DML_FEATURE_LEVEL** is greater than or equal to **DML_FEATURE_LEVEL_4_0**, then any dimension can be set to 1, and be automatically broadcast to match *InputTensor*.

If **DML_FEATURE_LEVEL** is less than **DML_FEATURE_LEVEL_5_2**, then this tensor is required if *ScaleTensor* is present. If **DML_FEATURE_LEVEL** is greater than or equal to **DML_FEATURE_LEVEL_5_2**, then this tensor can be null regardless of the value of *ScaleTensor*.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor to write the results to. This tensor's dimensions are `{ BatchCount, ChannelCount, Height, Width }`.

### `AxisCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of axes. This field determines the size of the *Axes* array.

### `Axes`

Type: \_Field\_size\_(AxisCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

The axes along which to calculate the Mean and Variance.

### `NormalizeVariance`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

**TRUE** if the Normalization layer includes Variance in the normalization calculation. Otherwise, **FALSE**. If **FALSE**, then normalization equation is `Output = FusedActivation(Scale * (Input - Mean) + Bias)`.

### `Epsilon`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The epsilon value to use to avoid division by zero. A value of 0.00001 is recommended as default.

### `FusedActivation`

Type: \_Maybenull\_ **const [DML_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_operator_desc)\***

An optional fused activation layer to apply after the normalization.

## Remarks
**DML_MEAN_VARIANCE_NORMALIZATION1_OPERATOR_DESC** is a superset of functionality of [DML_MEAN_VARIANCE_NORMALIZATION_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_mean_variance_normalization_operator_desc). Here, setting the **Axes** array to `{ 2, 3 }` is the equivalent of setting *CrossChannel* to **FALSE** in **DML_MEAN_VARIANCE_NORMALIZATION_OPERATOR_DESC**; while setting the **Axes** array to `{ 1, 2, 3 }` is equivalent of setting *CrossChannel* to **TRUE**.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_2_1`.

## Tensor constraints

*BiasTensor*, *InputTensor*, *OutputTensor*, and *ScaleTensor* must have the same *DataType* and *DimensionCount*.

## Tensor support

### DML_FEATURE_LEVEL_3_1 and above

| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| ScaleTensor | Optional input | 1 to 8 | FLOAT32, FLOAT16 |
| BiasTensor | Optional input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_2_1 and above

| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| ScaleTensor | Optional input | 4 | FLOAT32, FLOAT16 |
| BiasTensor | Optional input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |

## See also
[Using fused operators for improved performance](https://learn.microsoft.com/windows/ai/directml/dml-fused-activations)