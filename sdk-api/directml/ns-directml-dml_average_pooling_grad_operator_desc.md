## Description

Computes backpropagation gradients for average pooling (see [DML_AVERAGE_POOLING_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_average_pooling_operator_desc)).

Consider a 2x2 **DML_AVERAGE_POOLING_OPERATOR_DESC**, without padding and a stride of 1, that performs the following.

```
InputTensor             OutputTensor
[[[[1, 2, 3],   AvgPool  [[[[3, 4],
   [4, 5, 6],     -->       [6, 7]]]]
   [7, 8, 9]]]]
```

Each 2x2 window in the input tensor is averaged to produce one element of the output (reading zeros for elements beyond the edge). Here's an example of the output of **DML_AVERAGE_POOLING_GRAD_OPERATOR_DESC** given similar parameters.

```
InputGradientTensor            OutputGradientTensor
  [[[[1, 2],     AvgPoolGrad  [[[[0.25, 0.75, 0.5],
     [3, 4]]]]       -->         [   1,  2.5, 1.5],
                                 [0.75, 1.75,   1]]]]
```

Notice that the values in the *OutputGradientTensor* represent the weighted contributions of that element to the *OutputTensor* during the original [DML_AVERAGE_POOLING_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_average_pooling_operator_desc) operator.

## Members

### `InputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The incoming gradient tensor. This is typically obtained from the output of backpropagation of a preceding layer. Typically this tensor would have the same sizes as the *output* of the corresponding [DML_AVERAGE_POOLING_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_average_pooling_operator_desc) in the forward pass.

### `OutputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor containing the backpropagated gradients. Typically this tensor would have the same sizes as the *input* of the corresponding [DML_AVERAGE_POOLING_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_average_pooling_operator_desc) in the forward pass.

### `DimensionCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of elements in the *Strides*, *WindowSize*, *StartPadding*, and *EndPadding* arrays. This value must equal the spatial dimension count. The spatial dimension count is 2 if 4D tensors are provided, or 3 if 5D tensors are provided.

### `Strides`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

See *Strides* in [DML_AVERAGE_POOLING_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_average_pooling_operator_desc).

### `WindowSize`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

See *WindowSize* in [DML_AVERAGE_POOLING_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_average_pooling_operator_desc).

### `StartPadding`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

See *StartPadding* in [DML_AVERAGE_POOLING_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_average_pooling_operator_desc).

### `EndPadding`

Type: \_Field_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)\***

See *EndPadding* in [DML_AVERAGE_POOLING_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_average_pooling_operator_desc).

### `IncludePadding`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

See *IncludePadding* in [DML_AVERAGE_POOLING_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_average_pooling_operator_desc).

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_0`.

## Tensor constraints
*InputGradientTensor* and *OutputGradientTensor* must have the same *DataType* and *DimensionCount*.

## Tensor support
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputGradientTensor | Input | 4 to 5 | FLOAT32, FLOAT16 |
| OutputGradientTensor | Output | 4 to 5 | FLOAT32, FLOAT16 |