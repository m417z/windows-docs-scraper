# D3D_INCLUDE_TYPE enumeration

## Description

Values that indicate the location of a shader #include file.

> [!NOTE]
> For programming with Direct3D 10, this API has a type alias that begins `D3D10_` instead of `D3D_`. These Direct3D 10 type aliases are defined in `d3d10.h`, `d3d10misc.h`, and `d3d10shader.h`.

## Constants

### `D3D_INCLUDE_LOCAL:0`

The local directory.

### `D3D_INCLUDE_SYSTEM`

The system directory.

### `D3D10_INCLUDE_LOCAL`

The local directory.

### `D3D10_INCLUDE_SYSTEM`

The system directory.

### `D3D_INCLUDE_FORCE_DWORD:0x7fffffff`

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits.

Do not use this value.

## Remarks

You pass a **D3D_INCLUDE_TYPE**-typed value to the *IncludeType* parameter in a call to the [ID3DInclude::Open](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nf-d3dcommon-id3dinclude-open) method to indicate the location of the #include file.

## See also

[Common Version Enumerations](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-common-enumerations)

[D3D_INCLUDE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_include_type)

[ID3DInclude::Open](https://learn.microsoft.com/windows/desktop/api/d3dcommon/nf-d3dcommon-id3dinclude-open)