## Description

Computes the base-e (natural) logarithm of each element of *InputTensor*, placing the result into the corresponding element of *OutputTensor*.

If x is negative, then this function returns `indefinite`. If x is 0, then this function returns -INF.

```
f(x) = ln(x)
```

This operator supports in-place execution, meaning that *OutputTensor* is permitted to alias *InputTensor* during binding.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The input tensor to read from.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the results to.

### `ScaleBias`

Type: \_Maybenull\_ **const [DML_SCALE_BIAS](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_scale_bias)\***

An optional scale and bias to apply to the input. If present, this has the effect of applying the function `g(x) = x * scale + bias` to each *input* element prior to computing this operator.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType*, *DimensionCount*, and *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |