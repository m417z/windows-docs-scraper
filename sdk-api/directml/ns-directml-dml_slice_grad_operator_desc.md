## Description

Computes backpropagation gradients for Slice (see [DML_SLICE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_slice1_operator_desc)).

Recall that [DML_SLICE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_slice1_operator_desc) extracts a subregion of an input tensor. Given an *InputGradientTensor* with the same sizes as the *output* of an equivalent **DML_SLICE1_OPERATOR_DESC**, this operator produces an *OutputGradientTensor* with the same sizes as the *input* of **DML_SLICE1_OPERATOR_DESC**. The sliced elements are propagated to the output, and all other elements are set to 0.

As an example, consider a **DML_SLICE1_OPERATOR_DESC** that extracts the following elements from a tensor:

```
InputTensor            OutputTensor
[[a, b, c, d],
 [e, f, g, h],   Slice   [[a, c],
 [i, j, k, l],    -->     [i, k]]
 [m, n, o, p]]
```

If provided the same *InputWindowOffsets*/*Sizes*/*Strides* as in the above example, this operator would then perform the following transform.

```
InputGradientTensor       OutputGradientTensor
                             [[a, 0, c, 0],
      [[a, c],   SliceGrad    [0, 0, 0, 0],
       [i, k]]      -->       [i, 0, k, 0],
                              [0, 0, 0, 0]]
```

## Members

### `InputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The incoming gradient tensor. This is typically obtained from the output of backpropagation of a preceding layer. Typically, this tensor would have the same sizes as the *output* of the corresponding [DML_SLICE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_slice1_operator_desc) in the forward pass.

### `OutputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor containing the backpropagated gradients. Typically, this tensor would have the same sizes as the *input* of the corresponding [DML_SLICE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_slice1_operator_desc) in the forward pass.

### `DimensionCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of elements in the *InputWindowOffsets*, *InputWindowSizes*, and *InputWindowStrides* arrays. This value must equal the *DimensionCount* provided in the *InputGradientTensor* and *OutputGradientTensor*.

### `InputWindowOffsets`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

See *InputWindowOffsets* in [DML_SLICE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_slice1_operator_desc).

### `InputWindowSizes`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

See *InputWindowSizes* in [DML_SLICE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_slice1_operator_desc).

### `InputWindowStrides`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

See *InputWindowStrides* in [DML_SLICE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_slice1_operator_desc).

Note that unlike **DML_SLICE1_OPERATOR_DESC**, this operator requires non-zero strides. That's because with a zero stride, it's ambiguous as to which input element should map to each output element, and therefore backpropagation can't be performed. Like **DML_SLICE1_OPERATOR_DESC**, negative strides flip the input window direction along that axis.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_0`.

## Tensor constraints
*InputGradientTensor* and *OutputGradientTensor* must have the same *DataType* and *DimensionCount*.

## Tensor support

### DML_FEATURE_LEVEL_4_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputGradientTensor | Input | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputGradientTensor | Output | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputGradientTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputGradientTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputGradientTensor | Input | 4 to 5 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputGradientTensor | Output | 4 to 5 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |