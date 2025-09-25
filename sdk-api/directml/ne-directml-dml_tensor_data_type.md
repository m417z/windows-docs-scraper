## Description

Specifies the data type of the values in a tensor. DirectML operators may not support all data types; see the documentation for each specific operator to find which data types it supports.

## Constants

### `DML_TENSOR_DATA_TYPE_UNKNOWN`

Indicates an unknown data type. This value is never valid.

### `DML_TENSOR_DATA_TYPE_FLOAT32`

Indicates a 32-bit floating-point data type.

### `DML_TENSOR_DATA_TYPE_FLOAT16`

Indicates a 16-bit floating-point data type.

### `DML_TENSOR_DATA_TYPE_UINT32`

Indicates a 32-bit unsigned integer data type.

### `DML_TENSOR_DATA_TYPE_UINT16`

Indicates a 16-bit unsigned integer data type.

### `DML_TENSOR_DATA_TYPE_UINT8`

Indicates an 8-bit unsigned integer data type.

### `DML_TENSOR_DATA_TYPE_INT32`

Indicates a 32-bit signed integer data type.

### `DML_TENSOR_DATA_TYPE_INT16`

Indicates a 16-bit signed integer data type.

### `DML_TENSOR_DATA_TYPE_INT8`

Indicates an 8-bit signed integer data type.

## Remarks

### DML_FEATURE_LEVEL_6_3

DirectML [feature level 6_3](https://learn.microsoft.com/windows/ai/directml/dml-feature-level-history#dml_feature_level_6_3) introduces the following data types.

#### DML_TENSOR_DATA_TYPE_UINT4

Indicates a 4-bit unsigned integer data type. The **UINT4** data type puts the first element in the low nibble of the byte; and the second element in the high nibble (standard little-endian order). Dimensions don't need to be byte-aligned (odd sizes are fine). For example, if you have the **UINT4** element data [1,2,3,4,5], then that yields 3 bytes [0x21, 0x43, 0x05] with an ignorable tail nibble.

#### DML_TENSOR_DATA_TYPE_INT4

Indicates a 4-bit signed integer data type.