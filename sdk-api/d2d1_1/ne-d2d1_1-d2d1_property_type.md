# D2D1_PROPERTY_TYPE enumeration

## Description

Specifies the types of properties supported by the Direct2D property interface.

## Constants

### `D2D1_PROPERTY_TYPE_UNKNOWN:0`

An unknown property.

### `D2D1_PROPERTY_TYPE_STRING:1`

An arbitrary-length string.

### `D2D1_PROPERTY_TYPE_BOOL:2`

A 32-bit integer value constrained to be either 0 or 1.

### `D2D1_PROPERTY_TYPE_UINT32:3`

An unsigned 32-bit integer.

### `D2D1_PROPERTY_TYPE_INT32:4`

A signed 32-bit integer.

### `D2D1_PROPERTY_TYPE_FLOAT:5`

A 32-bit float.

### `D2D1_PROPERTY_TYPE_VECTOR2:6`

Two 32-bit float values.

### `D2D1_PROPERTY_TYPE_VECTOR3:7`

 Three 32-bit float values.

### `D2D1_PROPERTY_TYPE_VECTOR4:8`

Four 32-bit float values.

### `D2D1_PROPERTY_TYPE_BLOB:9`

An arbitrary number of bytes.

### `D2D1_PROPERTY_TYPE_IUNKNOWN:10`

A returned COM or nano-COM interface.

### `D2D1_PROPERTY_TYPE_ENUM:11`

An enumeration. The value should be treated as a **UINT32** with a defined array of fields to specify the bindings to human-readable strings.

### `D2D1_PROPERTY_TYPE_ARRAY:12`

An enumeration. The value is the count of sub-properties in the array. The set of array elements will be contained in the sub-property.

### `D2D1_PROPERTY_TYPE_CLSID:13`

A CLSID.

### `D2D1_PROPERTY_TYPE_MATRIX_3X2:14`

A 3x2 matrix of float values.

### `D2D1_PROPERTY_TYPE_MATRIX_4X3:15`

A 4x2 matrix of float values.

### `D2D1_PROPERTY_TYPE_MATRIX_4X4:16`

A 4x4 matrix of float values.

### `D2D1_PROPERTY_TYPE_MATRIX_5X4:17`

A 5x4 matrix of float values.

### `D2D1_PROPERTY_TYPE_COLOR_CONTEXT:18`

A nano-COM color context interface pointer.

### `D2D1_PROPERTY_TYPE_FORCE_DWORD:0xffffffff`

## See also

[ID2D1Properties](https://learn.microsoft.com/windows/desktop/api/d2d1_1/nn-d2d1_1-id2d1properties)

[ID2D1Properties::GetType](https://learn.microsoft.com/windows/win32/api/d2d1_1/nf-d2d1_1-id2d1properties-gettype(u))