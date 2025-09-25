## Description

Computes the maximum value across the elements within the sliding window over the input tensor.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An input tensor of *Sizes* `{ BatchCount, ChannelCount, Height, Width }` if *InputTensor.DimensionCount* is 4, and `{ BatchCount, ChannelCount, Depth, Height, Weight }` if *InputTensor.DimensionCount* is 5.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

An output tensor to write the results to. The sizes of the output tensor can be computed as follows.

```cpp
OutputTensor->Sizes[0] = InputTensor->Sizes[0];
OutputTensor->Sizes[1] = InputTensor->Sizes[1];

for (UINT i = 0; i < DimensionCount; ++i) {
  UINT PaddedSize = InputTensor->Sizes[i + 2] + StartPadding[i] + EndPadding[i];
  OutputTensor->Sizes[i + 2] = (PaddedSize - WindowSizes[i]) / Strides[i] + 1;
}
```

### `DimensionCount`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The number of spatial dimensions of the input tensor *InputTensor*, which also corresponds to the number of dimensions of the sliding window *WindowSize*. This value also determines the size of the *Strides*, *StartPadding*, and *EndPadding* arrays. It should be set to 2 when *InputTensor* is 4D, and 3 when it's a 5D tensor.

### `Strides`

Type: **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

The strides for the sliding window dimensions of sizes `{ Height, Width }` when the *DimensionCount* is set to 2, or `{ Depth, Height, Width }` when set to 3.

### `WindowSize`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

The dimensions of the sliding window in `{ Height, Width }` when *DimensionCount* is set to 2, or `{ Depth, Height, Width }` when set to 3.

### `StartPadding`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

The number of padding elements to be applied to the beginning of each spatial dimension of the input tensor *InputTensor*. The values are in `{ Height, Width }` when *DimensionCount* is set to 2, or `{ Depth, Height, Width }` when set to 3.

### `EndPadding`

Type: \_Field\_size\_(DimensionCount) **const [UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)***

The number of padding elements to be applied to the end of each spatial dimension of the input tensor *InputTensor*. The values are in `{ Height, Width }` when *DimensionCount* is set to 2, or `{ Depth, Height, Width }` when set to 3.

## Remarks
A newer version of this operator, [DML_MAX_POOLING1_OPERATOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_max_pooling1_operator_desc), was introduced in `DML_FEATURE_LEVEL_2_0`.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_1_0`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType* and *DimensionCount*.

## Tensor support
### DML_FEATURE_LEVEL_5_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 to 5 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 4 to 5 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 to 5 | FLOAT32, FLOAT16, INT8, UINT8 |
| OutputTensor | Output | 4 to 5 | FLOAT32, FLOAT16, INT8, UINT8 |

### DML_FEATURE_LEVEL_1_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 to 5 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 to 5 | FLOAT32, FLOAT16 |