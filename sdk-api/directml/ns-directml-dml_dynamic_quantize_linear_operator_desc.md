## Description

Calculates the quantization scale and zero point values necessary to quantize the *InputTensor*, then applies that quantization, writing the result to *OutputTensor*.

This operator uses the following equation to quantize.

```
InputMax = Max(InputTensor)
InputMin = Min(InputTensor)

AValue = (A - AZeroPoint) * AScale
BValue = (B - BZeroPoint) * BScale

// For uint8 output, Min = 0, Max = 255
// For int8 output, Min = -128, Max = 127
OutputScale = (InputMax – InputMin) / (Max – Min)

OutputZeroPoint = Min - InputMin / OutputScale

OutputTensor = clamp(round(InputValue / OutputScale) + OutputZeroPoint, Min, Max)
```

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor containing the inputs.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the results to.

### `OutputScaleTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the output scale factor for *OutputTensor*. The expected number of elements in *OutputScaleTensor* is 1.

### `OutputZeroPointTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the output zero point for *OutputTensor*. The expected number of elements in *OutputZeroPointTensor* is 1.

## Remarks

## Availability
This operator was introduced in **DML_FEATURE_LEVEL_4_0**.

## Tensor constraints
* *InputTensor*, *OutputScaleTensor*, *OutputTensor*, and *OutputZeroPointTensor* must have the same *DimensionCount*.
* *OutputTensor* and *OutputZeroPointTensor* must have the same *DataType*.

## Tensor support
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 1 to 8 | INT8, UINT8 |
| OutputScaleTensor | Output | 1 to 8 | FLOAT32 |
| OutputZeroPointTensor | Output | 1 to 8 | INT8, UINT8 |

## See also
* [DML_ELEMENT_WISE_DEQUANTIZE_LINEAR_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_element_wise_dequantize_linear_operator_desc)