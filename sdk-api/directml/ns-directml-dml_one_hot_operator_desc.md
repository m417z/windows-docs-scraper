## Description

Produces a tensor filled with *one-hot encoded* values. This operator produces an output tensor where, for all sequences in a chosen axis, all but one element in that sequence is set to *OffValue*, and the remaining single element is set to *OnValue*. A *sequence* refers to one of the sets of elements that exist along the *Axis* dimension of the *OutputTensor*.

The location of the *OnValue* for each sequence and the choice of *OnValue*/*OffValue* are determined by the *IndicesTensor* and *ValuesTensor*, respectively.

## Members

### `IndicesTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the index in elements of the *OnValue*, for each sequence along the *Axis*. Indices are measured relative to the beginning of their sequence (as opposed to the beginning of the tensor). For example, an index of 0 always refers to the first element for all sequences in an axis.

If an index value for a sequence exceeds the number of elements along the *Axis* dimension in the *OutputTensor*, then that index value is ignored, and all elements in that sequence will be set to *OffValue*.

Starting with `DML_FEATURE_LEVEL_3_0`, this operator supports negative index values when using a signed integral type with this tensor. Negative indices are interpreted as being relative to the end of the sequence. For example, an index of -1 refers to the last element in the sequence.

This tensor must have dimension count and sizes equal to the *OutputTensor*, *except* for the dimension specified by the *Axis* parameter. The size of the *Axis* dimension must be 1. For example if the *OutputTensor* has sizes of `{2,3,4,5}` and *Axis* is 1, the sizes of the *IndicesTensor* must be `{2,1,4,5}`.

### `ValuesTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

This tensor may have any size, so long as it contains at least two elements. The 0th element of this tensor is interpreted as the *OffValue*, and the 1st element along the fastest-changing dimension of size >1 is interpreted as the *OnValue*.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the results to. This tensor must have dimension count and sizes equal to the *IndicesTensor*, *except* for the dimension specified by the *Axis* parameter. The size of the *Axis* dimension in this tensor may have any value greater than 0.

### `Axis`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The index of the dimension to produce one-hot encoded sequences along. This value must be less than the DimensionCount of the *IndicesTensor*.

## Examples

### Example 1

```
IndicesTensor: (Sizes:{1,1,3,1}, DataType:UINT32)
[[[[0],
   [3],
   [2]]]]

ValuesTensor: (Sizes:{1,1,1,2}, DataType:FLOAT32)
[[[[0, 1]]]]

Axis: 3

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[1, 0, 0, 0],    // The one-hot encoding is formed across the rows
   [0, 0, 0, 1],
   [0, 0, 1, 0]]]]
```

### Example 2. Using a different axis

```
IndicesTensor: (Sizes:{1,1,1,4}, DataType:UINT32)
[[[[0, 2, 1, 0]]]]

ValuesTensor: (Sizes:{1,1,1,2}, DataType:FLOAT32)
[[[[0, 1]]]]

Axis: 2

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[1, 0, 0, 1],    // The one-hot encoding is formed across the columns
   [0, 0, 1, 0],
   [0, 1, 0, 0]]]]
```

### Example 3. Using different on/off values

```
IndicesTensor: (Sizes:{1,1,3,1}, DataType:UINT32)
[[[[0],
   [3],
   [2]]]]

ValuesTensor: (Sizes:{1,1,3,1}, DataType:FLOAT32)
[[[[4],    // off value
   [2],    // on value
   [9]]]] // unused

Axis: 3

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[2, 4, 4, 4],
   [4, 4, 4, 2],
   [4, 4, 2, 4]]]]
```

### Example 4. Negative and out-of-bounds indices

```
IndicesTensor: (Sizes:{1,1,3,1}, DataType:INT32)
[[[[ -3],
   [100],
   [  3]]]]

ValuesTensor: (Sizes:{1,1,1,2}, DataType:FLOAT32)
[[[[0, 1]]]]

Axis: 3

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[0, 1, 0, 0],    // negative indices count from the end
   [0, 0, 0, 0],    // out-of-bounds indices are ignored; all elements are set to OffValue
   [0, 0, 0, 1]]]]
```

## Remarks

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_2_0`.

## Tensor constraints
* *IndicesTensor*, *OutputTensor*, and *ValuesTensor* must have the same *DimensionCount*.
* *OutputTensor* and *ValuesTensor* must have the same *DataType*.

## Tensor support

### DML_FEATURE_LEVEL_4_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| IndicesTensor | Input | 1 to 8 | INT64, INT32, UINT64, UINT32 |
| ValuesTensor | Input | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_3_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| IndicesTensor | Input | 1 to 8 | INT64, INT32, UINT64, UINT32 |
| ValuesTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| IndicesTensor | Input | 4 | UINT32 |
| ValuesTensor | Input | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_2_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| IndicesTensor | Input | 4 | UINT32 |
| ValuesTensor | Input | 4 | FLOAT32, FLOAT16 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16 |

## See also