## Description

Fills a tensor with a sequence. This operator performs the following pseudocode.

```
for each elementIndex in OutputTensor
    OutputTensor[elementIndex] = Value + elementIndex * Delta
endfor
```

## Members

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write the results to. This tensor may have any size.

### `ValueDataType`

Type: **[DML_TENSOR_DATA_TYPE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_data_type)**

The data type of *Value* field, which must match *OutputTensor.DataType*.

### `ValueStart`

Type: **[DML_SCALAR_UNION](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_scalar_union)**

The initial value to fill the first element in the output, with *ValueDataType* determining how to interpret the field.

### `ValueDelta`

Type: **[DML_SCALAR_UNION](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_scalar_union)**

A step to add to the value for each element written, with *ValueDataType* determining how to interpret the field.

## Examples

### Example 1. 1D ascending step

```
ValueStart = 3
ValueDelta = 2
ValueDataType = DML_TENSOR_DATA_TYPE_FLOAT32

OutputTensor: (Sizes:{1,1,1,3}, DataType:FLOAT32)
    [[[[3, 5, 7]]]]
```

### Example 2. 2D ascending step

```
ValueStart = 10
ValueDelta = -2
ValueDataType = DML_TENSOR_DATA_TYPE_UINT8

OutputTensor: (Sizes:{1,1,2,2}, DataType:UINT8)
    [[[[10, 8],
       [ 6, 4]]]]
```

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_2_1`.

## Tensor support
### DML_FEATURE_LEVEL_5_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_4_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |