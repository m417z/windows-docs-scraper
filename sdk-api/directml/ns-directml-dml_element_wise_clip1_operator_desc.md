## Description

Performs the following operation for each element of *InputTensor*, placing the result into the corresponding element of *OutputTensor*. This operator clamps (or limits) every element in the input within the closed interval [*Min*, *Max*].

```
f(x) = max(Min, min(x, Max))
```

Where `max(a,b)` returns the larger of the two values, and `min(a,b)` returns the smaller of the two values a,b.

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

### `MinMaxDataType`

Type: [**DML_TENSOR_DATA_TYPE**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_data_type)

The data type of the *Min* and *Max* members, which must match *OutputTensor.DataType*.

### `Min`

Type: [**DML_SCALAR_UNION**](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_scalar_union)

The minimum value, below which the operator replaces the value with *Min*. *MinMaxDataType* determines how to interpret the field.

### `Max`

Type: [**DML_SCALAR_UNION**](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_scalar_union)

The maximum value, above which the operator replaces the value with *Max*. *MinMaxDataType* determines how to interpret the field.

## Remarks

## Availability
This operator was introduced in **DML_FEATURE_LEVEL_5_0**.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType*, *DimensionCount*, and *Sizes*.

## Tensor support
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

## See also