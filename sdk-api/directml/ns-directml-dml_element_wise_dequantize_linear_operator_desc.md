## Description

Performs the following linear dequantization function on every element in *InputTensor* with respect to its corresponding element in *ScaleTensor* and `ZeroPointTensor`, placing the results in the corresponding element of *OutputTensor*.

```
f(input, scale, zero_point) = (input - zero_point) * scale
```

Quantization is a common way to increase performance at the cost of precision. A group of 8-bit int values can be computed faster than a group of 32-bit float values can. Dequantizing converts the encoded data back to its domain.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor containing the inputs.

### `ScaleTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor containing the scales.
A scale value of 0 will result in undefined behavior.

> [!NOTE]
> A scale value of 0 results in undefined behavior.

### `ZeroPointTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor containing the zero point that was used for quantization.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the results to.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
* *InputTensor*, *OutputTensor*, *ScaleTensor*, and *ZeroPointTensor* must have the same *DimensionCount* and *Sizes*.
* *InputTensor* and *ZeroPointTensor* must have the same *DataType*.
* *OutputTensor* and *ScaleTensor* must have the same *DataType*.

## Tensor support
### DML_FEATURE_LEVEL_6_2 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| ScaleTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| ZeroPointTensor | Optional input | 1 to 8 | INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_6_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| ScaleTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| ZeroPointTensor | Input | 1 to 8 | INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| ScaleTensor | Input | 1 to 8 | FLOAT32 |
| ZeroPointTensor | Input | 1 to 8 | INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| ScaleTensor | Input | 4 | FLOAT32 |
| ZeroPointTensor | Input | 4 | INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 4 | FLOAT32 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | UINT8 |
| ScaleTensor | Input | 4 | FLOAT32 |
| ZeroPointTensor | Input | 4 | UINT8 |
| OutputTensor | Output | 4 | FLOAT32 |

## See also

[DML_ELEMENT_WISE_QUANTIZE_LINEAR_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_element_wise_quantize_linear_operator_desc)