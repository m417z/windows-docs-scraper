## Description

Multiplies the elements of a tensor along an axis, writing the running tally of the product into the output tensor.

## Members

### `InputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

A tensor containing the input data. This is typically the same tensor that was provided as the *InputTensor* to [**DML_BATCH_NORMALIZATION_OPERATOR_DESC**](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_batch_normalization_operator_desc) in the forward pass.

The input tensor containing elements to be multiplied.

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The output tensor to write the resulting cumulative products to. This tensor must have the same sizes and data type as *InputTensor*.

### `Axis`

Type: [**UINT**](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)

The index of the dimension to multiply elements over. This value must be less than the *DimensionCount* of the *InputTensor*.

### `AxisDirection`

Type: **[DML_AXIS_DIRECTION](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_axis_direction)**

One of the values of the [DML_AXIS_DIRECTION](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_axis_direction) enumeration. If set to **DML_AXIS_DIRECTION_INCREASING**, then the product occurs by traversing the tensor along the specified axis by ascending element index. If set to **DML_AXIS_DIRECTION_DECREASING**, the reverse is true and the product occurs by traversing elements by descending index.

### `HasExclusiveProduct`

Type: **[BOOL](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If **TRUE**, then the value of the current element is excluded when writing the running tally to the output tensor. If **FALSE**, then the value of the current element is included in the running tally.

## Examples

The examples in this section all use this same input tensor.

```
InputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[2, 1, 3, 5],
   [3, 8, 7, 3],
   [9, 6, 2, 4]]]]
```

### Example 1. Cumulative product across horizontal slivers

```
Axis: 3
AxisDirection: DML_AXIS_DIRECTION_INCREASING
HasExclusiveProduct: FALSE

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[2,  2,   6,  30],       // i.e. [2, 2*1, 2*1*3, 2*1*3*5]
   [3, 24, 168, 504],       //      [...                   ]
   [9, 54, 108, 432]]]]     //      [...                   ]
```

### Example 2. Exclusive products

Setting *HasExclusiveProduct* to **TRUE** has the effect of excluding the current element's value from the running tally when writing to the output tensor.

```
Axis: 3
AxisDirection: DML_AXIS_DIRECTION_INCREASING
HasExclusiveProduct: TRUE

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[1, 2,  2,   6],      // Notice the product is written before multiplying the input,
   [1, 3, 24, 168],      // and the final total is not written to any output.
   [1, 9, 54, 108]]]]
```

### Example 3. Axis direction

Setting the *AxisDirection* to [**DML_AXIS_DIRECTION_DECREASING**](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_axis_direction) has the effect of reversing the traversal order of elements when computing the running tally.

```
Axis: 3
AxisDirection: DML_AXIS_DIRECTION_DECREASING
HasExclusiveProduct: FALSE

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[ 30,  15, 15, 5],    // i.e. [2*1*3*5, 1*3*5, 3*5, 5]
   [504, 168, 21, 3],    //      [...                   ]
   [432,  48,  8, 4]]]]  //      [...                   ]
```

### Example 4. Multiplying along a different axis

In this example, the product occurs vertically, along the height axis (second dimension).

```
Axis: 2
AxisDirection: DML_AXIS_DIRECTION_INCREASING
HasExclusiveProduct: FALSE

OutputTensor: (Sizes:{1,1,3,4}, DataType:FLOAT32)
[[[[ 2,  1,  3,  5],   // i.e. [2,    ...]
   [ 6,  8, 21, 15],   //      [2*3,  ...]
   [54, 48, 42, 60]]]] //      [2*3*9 ...]
```

## Remarks
This operator supports in-place execution, meaning that the output tensor is permitted to alias *InputTensor* during binding.

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_3_1`.

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

### DML_FEATURE_LEVEL_3_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| InputTensor | Input | 4 | FLOAT32, FLOAT16, INT32, UINT32 |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT32, UINT32 |

## See also