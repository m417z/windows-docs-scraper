## Description

Computes backpropagation gradients for a rectified linear unit (ReLU). This operator performs the following element-wise computation.

```
X = InputTensor
dY = InputGradientTensor

OutputGradientTensor = (X > 0 ? dY : 0)
```

The corresponding forward-pass operator is [DML_ACTIVATION_RELU_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_activation_relu_operator_desc).

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The input (feature) tensor. This is typically the same input as was provided during the forward pass (see [DML_ACTIVATION_RELU_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_activation_relu_operator_desc)).

### `InputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The incoming gradient tensor. This is typically obtained from the output of backpropagation of a preceding layer. The *Sizes* and *DataType* of this tensor must exactly match those of the *InputTensor*.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor containing the backpropagated gradients. The *Sizes* and *DataType* of this tensor must exactly match those of the *InputTensor*.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_0`.

## Tensor constraints
*InputGradientTensor*, *InputTensor*, and *OutputGradientTensor* must have the same *DataType*, *DimensionCount*, and *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_5_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8 |
| InputGradientTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8 |
| OutputGradientTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8 |

### DML_FEATURE_LEVEL_4_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| InputGradientTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputGradientTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| InputGradientTensor | Input | 1 to 8 | FLOAT32, FLOAT16 |
| OutputGradientTensor | Output | 1 to 8 | FLOAT32, FLOAT16 |

## See also
[DML_ACTIVATION_RELU_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_activation_relu_operator_desc)