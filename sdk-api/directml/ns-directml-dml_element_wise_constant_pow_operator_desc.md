## Description

Raises each element of *InputTensor* to the power of *Exponent*, placing the result into the corresponding element of *OutputTensor*.

```
f(x) = pow(x, Exponent)
```

Negative bases are supported for integral exponents, otherwise this operator returns NaN.

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

### `Exponent`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The exponent that all inputs will be raised to.

## Remarks
Also see the POW operator [DML_ELEMENT_WISE_POW_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_element_wise_pow_operator_desc), which accepts a second tensor as exponents.

## See also
[DML_ELEMENT_WISE_POW_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_element_wise_pow_operator_desc)

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