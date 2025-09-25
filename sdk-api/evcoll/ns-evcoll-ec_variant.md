# EC_VARIANT structure

## Description

The **EC_VARIANT** structure contains event collector data (subscription data) or property values.

## Members

### `BooleanVal`

A Boolean value.

### `UInt32Val`

An unsigned 32-bit integer value.

### `DateTimeVal`

A ULONGLONG value.

### `StringVal`

A null-terminated Unicode string.

### `BinaryVal`

A hexadecimal binary value.

### `BooleanArr`

A pointer to an array of Boolean values.

### `Int32Arr`

A pointer to an array of signed 32-bit integer values.

### `StringArr`

A pointer to an array of null-terminated strings.

### `PropertyHandleVal`

### `Count`

The number of elements (not length) in bytes. Used for arrays and binary or string types.

### `Type`

The type of the data in the structure. Use a value from the [EC_VARIANT_TYPE](https://learn.microsoft.com/windows/desktop/api/evcoll/ne-evcoll-ec_variant_type) enumeration to specify the type. When the type is specified, you can use any of the union members to access the actual value. For example, if the type is **EcVarTypeDateTime**, then the value is **DateTimeVal** in the **EC_VARIANT** structure.