## Description

Computes backpropagation gradients for max pooling (see [DML_MAX_POOLING2_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling2_operator_desc)).

Consider a 2x2 **DML_MAX_POOLING2_OPERATOR_DESC** without padding nor dilations and a stride of 1, which performs the following.

```
InputTensor             OutputTensor    IndicesTensor
[[1, 2, 3],   MaxPool    [[4, 4],        [[4, 4],
 [2, 4, 2],     -->       [6, 7]]         [7, 8]]
 [5, 6, 7]]
```

The largest element of each 2x2 window in the input tensor produces one element of the output. Below is an example of the output of **DML_MAX_POOLING_GRAD_OPERATOR_DESC**, given similar parameters.

```
InputTensor   InputGradientTensor            OutputGradientTensor
[[1, 2, 3],       [[1, 2],     MaxPoolGrad   [[0, 0, 0],
 [2, 4, 2],        [4, 5]]         -->        [0, 3, 0],
 [5, 6, 7]]                                   [0, 4, 5]]
```

In effect, this operator uses the *InputTensor* to determine the index of the largest element from each window, and distributes the values of *InputGradientTensor* into the *OutputGradientTensor* based on these indices. Where indices overlap, the values are summed. Any unreferenced output elements are zeroed.

In the case of a tie (where more than one element in a window has the same maximum value), the element with the lowest logical element index is chosen.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The input feature tensor. This is typically the same tensor that was provided as the *InputTensor* to [DML_MAX_POOLING2_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling2_operator_desc) in the forward pass.

### `InputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The incoming gradient tensor. This is typically obtained from the output of backpropagation of a preceding layer. Typically this tensor would have the same sizes as the *output* of the corresponding [DML_MAX_POOLING2_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling2_operator_desc) in the forward pass.

### `OutputGradientTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor containing the backpropagated gradients. Typically this tensor would have the same sizes as the *input* of the corresponding [DML_MAX_POOLING2_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling2_operator_desc) in the forward pass.

### `DimensionCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of elements in the *Strides*, *WindowSize*, *StartPadding*, *EndPadding*, and *Dilations* arrays. This value must equal the spatial dimension count (InputTensor's DimensionCount - 2). As this operator only supports 4D tensors, the only valid value for this parameter is 2.

### `Strides`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

See *Strides* in [DML_MAX_POOLING2_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling2_operator_desc).

### `WindowSize`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

See *WindowSize* in [DML_MAX_POOLING2_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling2_operator_desc).

### `StartPadding`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

See *StartPadding* in [DML_MAX_POOLING2_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling2_operator_desc).

### `EndPadding`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

See *EndPadding* in [DML_MAX_POOLING2_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling2_operator_desc).

### `Dilations`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

See *Dilations* in [DML_MAX_POOLING2_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling2_operator_desc).

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_0`.

## Tensor constraints
* *InputGradientTensor*, *InputTensor*, and *OutputGradientTensor* must have the same *DataType* and *DimensionCount*.
* *InputTensor* and *OutputGradientTensor* must have the same *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_4_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { BatchCount, ChannelCount, [InputDepth], InputHeight, InputWidth } | 4 to 5 | FLOAT32, FLOAT16 |
| InputGradientTensor | Input | { BatchCount, ChannelCount, [OutputDepth], OutputHeight, OutputWidth } | 4 to 5 | FLOAT32, FLOAT16 |
| OutputGradientTensor | Output | { BatchCount, ChannelCount, [InputDepth], InputHeight, InputWidth } | 4 to 5 | FLOAT32, FLOAT16 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Dimensions | Supported dimension counts | Supported data types |
| ------ | ---- | ---------- | -------------------------- | -------------------- |
| InputTensor | Input | { BatchCount, ChannelCount, InputHeight, InputWidth } | 4 | FLOAT32, FLOAT16 |
| InputGradientTensor | Input | { BatchCount, ChannelCount, OutputHeight, OutputWidth } | 4 | FLOAT32, FLOAT16 |
| OutputGradientTensor | Output | { BatchCount, ChannelCount, InputHeight, InputWidth } | 4 | FLOAT32, FLOAT16 |