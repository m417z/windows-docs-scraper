## Description

Sums the elements of a tensor along an axis, writing the running tally of the summation into the output tensor.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The input tensor containing elements to be summed.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the resulting cumulative summations to. This tensor must have the same sizes and data type as the *InputTensor*.

### `Axis`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The index of the dimension to sum elements over. This value must be less than the *DimensionCount* of the *InputTensor*.

### `AxisDirection`

Type: **[DML_AXIS_DIRECTION](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_axis_direction)**

One of the values of the [DML_AXIS_DIRECTION](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_axis_direction) enumeration. If set to **DML_AXIS_DIRECTION_INCREASING**, then the summation occurs by traversing the tensor along the specified axis by ascending element index. If set to **DML_AXIS_DIRECTION_DECREASING**, the reverse is true, and the summation occurs by traversing elements by descending index.

### `HasExclusiveSum`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **TRUE**, then the value of the current element is excluded when writing the running tally to the output tensor. If **FALSE**, then the value of the current element is included in the running tally.

## Examples

The examples in this section all use an input tensor with the following properties.

```
InputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[2, 1, 3, 5],
   [3, 8, 7, 3],
   [9, 6, 2, 4]]]]
```

### Example 1. Cumulative summation across horizontal slivers

```
Axis: 3
AxisDirection: DML_AXIS_DIRECTION_INCREASING
HasExclusiveSum: FALSE

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[2,  3,  6, 11],     // i.e. [2, 2+1, 2+1+3, 2+1+3+5]
   [3, 11, 18, 21],     //      [...                   ]
   [9, 15, 17, 21]]]]   //      [...                   ]
```

### Example 2. Exclusive sums

Setting *HasExclusiveSum* to **TRUE** has the effect of excluding the current element's value from the running tally when writing to the output tensor.

```
Axis: 3
AxisDirection: DML_AXIS_DIRECTION_INCREASING
HasExclusiveSum: TRUE

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[0, 2,  3,  6],      // Notice the sum is written before adding the input,
   [0, 3, 11, 18],      // and the final total is not written to any output.
   [0, 9, 15, 17]]]]
```

### Example 3. Axis direction

Setting the *AxisDirection* to [DML_AXIS_DIRECTION_DECREASING](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_axis_direction) has the effect of reversing the traversal order of elements when computing the running tally.

```
Axis: 3
AxisDirection: DML_AXIS_DIRECTION_DECREASING
HasExclusiveSum: FALSE

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[11,  9,  8,  5],    // i.e. [2+1+3+5, 1+3+5, 3+5, 5]
   [21, 18, 10,  3],    //      [...                   ]
   [21, 12,  6,  4]]]]  //      [...                   ]
```

### Example 4. Summing along a different axis

In this example, the summation occurs vertically, along the height axis (dimension 2).

```
Axis: 2
AxisDirection: DML_AXIS_DIRECTION_INCREASING
HasExclusiveSum: FALSE

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[ 2,  1,  3,  5],   // i.e. [2,    ...]
   [ 5,  9, 10,  8],   //      [2+3,  ...]
   [14, 15, 12, 12]]]] //      [2+3+9 ...]
```

## Remarks
This operator supports in-place execution, meaning that the *OutputTensor* is permitted to alias the *InputTensor* during binding.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_2_1`.

## Tensor constraints
*InputTensor* and *OutputTensor* must have the same *DataType*, *DimensionCount*, and *Sizes*.

## Tensor support
### DML_FEATURE_LEVEL_5_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, UINT64, UINT32 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, UINT64, UINT32 |

### DML_FEATURE_LEVEL_4_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 1 to 8 | FLOAT32, FLOAT16, INT32, UINT32 |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, UINT32 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16, INT32, UINT32 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT32, UINT32 |