# D3D_REGISTER_COMPONENT_TYPE enumeration

## Description

Values that identify the data types that can be stored in a register.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_REGISTER_COMPONENT_UNKNOWN:0`

The data type is unknown.

### `D3D_REGISTER_COMPONENT_UINT32:1`

32-bit unsigned integer.

### `D3D_REGISTER_COMPONENT_SINT32:2`

32-bit signed integer.

### `D3D_REGISTER_COMPONENT_FLOAT32:3`

32-bit floating-point number.

### `D3D10_REGISTER_COMPONENT_UNKNOWN`

The data type is unknown.

### `D3D10_REGISTER_COMPONENT_UINT32`

32-bit unsigned integer.

### `D3D10_REGISTER_COMPONENT_SINT32`

32-bit signed integer.

### `D3D10_REGISTER_COMPONENT_FLOAT32`

32-bit floating-point number.

## Remarks

A register component type is specified in the **ComponentType** member of the [D3D11_SIGNATURE_PARAMETER_DESC](https://learn.microsoft.com/windows/win32/api/d3d11shader/ns-d3d11shader-d3d11_signature_parameter_desc) structure.

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)