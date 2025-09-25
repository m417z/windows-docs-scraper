# D3D_SHADER_VARIABLE_CLASS enumeration

## Description

Values that identify the class of a shader variable.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_SVC_SCALAR:0`

The shader variable is a scalar.

### `D3D_SVC_VECTOR`

The shader variable is a vector.

### `D3D_SVC_MATRIX_ROWS`

The shader variable is a row-major matrix.

### `D3D_SVC_MATRIX_COLUMNS`

The shader variable is a column-major matrix.

### `D3D_SVC_OBJECT`

The shader variable is an object.

### `D3D_SVC_STRUCT`

The shader variable is a structure.

### `D3D_SVC_INTERFACE_CLASS`

The shader variable is a class.

### `D3D_SVC_INTERFACE_POINTER`

The shader variable is an interface.

### `D3D10_SVC_SCALAR`

The shader variable is a scalar.

### `D3D10_SVC_VECTOR`

The shader variable is a vector.

### `D3D10_SVC_MATRIX_ROWS`

The shader variable is a row-major matrix.

### `D3D10_SVC_MATRIX_COLUMNS`

The shader variable is a column-major matrix.

### `D3D10_SVC_OBJECT`

The shader variable is an object.

### `D3D10_SVC_STRUCT`

The shader variable is a structure.

### `D3D11_SVC_INTERFACE_CLASS`

The shader variable is a class.

### `D3D11_SVC_INTERFACE_POINTER`

The shader variable is an interface.

### `D3D_SVC_FORCE_DWORD:0x7fffffff`

This value is not used by a programmer; it exists to force the enumeration to compile to 32 bits.

## Remarks

The class of a shader variable is not a programming class; the class identifies the variable class such as scalar, vector, object, and so on. **D3D_SHADER_VARIABLE_CLASS**-typed values are specified in the **Class** member of the [D3D11_SHADER_TYPE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_shader_type_desc) structure.

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)