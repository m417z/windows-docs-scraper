# D3D_SHADER_CBUFFER_FLAGS enumeration

## Description

Values that identify the intended use of a constant-data buffer.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_CBF_USERPACKED:1`

Bind the constant buffer to an input slot defined in HLSL code (instead of letting the compiler choose the input slot).

### `D3D10_CBF_USERPACKED`

Bind the constant buffer to an input slot defined in HLSL code (instead of letting the compiler choose the input slot).

### `D3D_CBF_FORCE_DWORD:0x7fffffff`

This value is not used by a programmer; it exists to force the enumeration to compile to 32 bits.

## Remarks

**D3D_SHADER_CBUFFER_FLAGS**-typed values are specified in the **uFlags** member of the [D3D11_SHADER_BUFFER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11shader/ns-d3d11shader-d3d11_shader_buffer_desc) structure.

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)