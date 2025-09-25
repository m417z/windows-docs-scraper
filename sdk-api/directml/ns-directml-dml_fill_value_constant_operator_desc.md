## Description

Fills a tensor with the given constant *Value*. This operator performs the following pseudocode.

```
for each coordinate in OutputTensor
    OutputTensor[coordinate] = Value
endfor
```

## Members

### `OutputTensor`

Type: **const [DML_TENSOR_DESC](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_tensor_desc)\***

The tensor to write the results to. This tensor may have any size.

### `ValueDataType`

Type: **[DML_TENSOR_DATA_TYPE](https://learn.microsoft.com/windows/win32/api/directml/ne-directml-dml_tensor_data_type)**

The data type of the *Value* field, which must match *OutputTensor.DataType*.

### `Value`

Type: **[DML_SCALAR_UNION](https://learn.microsoft.com/windows/win32/api/directml/ns-directml-dml_scalar_union)**

A constant value to fill the output, with *ValueDataType* determining how to interpret the field.

## Examples

```
Value = 13.0

OutputTensor: (Sizes:{1,1,2,4}, DataType:FLOAT32)
    [[[[13.0f, 13.0f, 13.0f, 13.0f],
       [13.0f, 13.0f, 13.0f, 13.0f]]]]
```

## Availability
This operator was introduced in `DML_FEATURE_LEVEL_2_1`.

## Tensor support

### DML_FEATURE_LEVEL_4_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| OutputTensor | Output | 1 to 8 | FLOAT64, FLOAT32, FLOAT16, INT64, INT32, INT16, INT8, UINT64, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_4_0 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| OutputTensor | Output | 1 to 8 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |

### DML_FEATURE_LEVEL_2_1 and above
| Tensor | Kind | Supported dimension counts | Supported data types |
| ------ | ---- | -------------------------- | -------------------- |
| OutputTensor | Output | 4 | FLOAT32, FLOAT16, INT32, INT16, INT8, UINT32, UINT16, UINT8 |