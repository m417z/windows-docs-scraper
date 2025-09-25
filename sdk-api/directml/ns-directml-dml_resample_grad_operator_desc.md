## Description

Computes backpropagation gradients for Resample (see [DML_RESAMPLE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_resample1_operator_desc)).

**DML_RESAMPLE1_OPERATOR_DESC** rescales arbitrary dimensions of the input tensor using either nearest-neighbor sampling or bilinear interpolation. Given an *InputGradientTensor* with the same sizes as the *output* of an equivalent **DML_RESAMPLE1_OPERATOR_DESC**, this operator produces an *OutputGradientTensor* with the same sizes as the *input* of the **DML_RESAMPLE1_OPERATOR_DESC**.

As an example, consider a **DML_RESAMPLE1_OPERATOR_DESC** that performs a nearest-neighbor scaling of 1.5x in the width, and 0.5x in the height.

```
InputTensor           OutputTensor
[[1, 2],   Resample    [1, 1, 2]
 [3, 4]]      -->
```

Notice how the 0th element of the input tensor (with value 1) contributes to two elements in the output, the 1st element (with value 2) contributes to one element in the output, and the 2nd and 3rd elements (with values 3 and 4) contribute to no elements of the output.

The corresponding **DML_RESAMPLE_GRAD_OPERATOR_DESC** would perform the following.

```
InputGradientTensor           OutputGradientTensor
    [4, 5, 6]      ResampleGrad    [[9, 6],
                       -->          [0, 0]]
```

Notice that the values in the *OutputGradientTensor* represent the weighted contributions of that element to the *OutputTensor* during the original **DML_RESAMPLE1_OPERATOR_DESC** operator.

## Members

### `InputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The incoming gradient tensor. This is typically obtained from the output of backpropagation of a preceding layer. Typically this tensor would have the same sizes as the *output* of the corresponding [DML_RESAMPLE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_resample1_operator_desc) in the forward pass.

### `OutputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor containing the backpropagated gradients. Typically this tensor would have the same sizes as the *input* of the corresponding [DML_RESAMPLE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_resample1_operator_desc) in the forward pass.

### `InterpolationMode`

Type: [**DML_INTERPOLATION_MODE**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_interpolation_mode)

See *InterpolationMode* in [DML_RESAMPLE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_resample1_operator_desc).

### `DimensionCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of elements in the *Scales*, *InputPixelOffsets*, and *OutputPixelOffsets* arrays. This value must equal the *DimensionCount* provided in the *InputGradientTensor* and *OutputGradientTensor*.

### `Scales`

Type: \_Field\_size\_(DimensionCount) **const [FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

See *Scales* in [DML_RESAMPLE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_resample1_operator_desc).

### `InputPixelOffsets`

Type: \_Field\_size\_(DimensionCount) **const [FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

See *InputPixelOffsets* in [DML_RESAMPLE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_resample1_operator_desc).

### `OutputPixelOffsets`

Type: \_Field\_size\_(DimensionCount) **const [FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

See *OutputPixelOffsets* in [DML_RESAMPLE1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_resample1_operator_desc).

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_0`.

## Tensor constraints
*InputGradientTensor* and *OutputGradientTensor* must have the same *DataType* and *DimensionCount*.

## Tensor support
### DML_FEATURE_LEVEL_5_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputGradientTensor | Input | 1 to 4 | FLOAT32, FLOAT16 |
| OutputGradientTensor | Output | 1 to 4 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputGradientTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputGradientTensor | Output | 4 | FLOAT32, FLOAT16 |