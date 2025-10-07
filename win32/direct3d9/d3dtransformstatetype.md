# D3DTRANSFORMSTATETYPE enumeration

Defines constants that describe transformation state values.

## Constants

**D3DTS\_VIEW**

Identifies the transformation matrix being set as the view transformation matrix. The default value is **NULL** (the identity matrix).

**D3DTS\_PROJECTION**

Identifies the transformation matrix being set as the projection transformation matrix. The default value is **NULL** (the identity matrix).

**D3DTS\_TEXTURE0**

Identifies the transformation matrix being set for the specified texture stage.

**D3DTS\_TEXTURE1**

Identifies the transformation matrix being set for the specified texture stage.

**D3DTS\_TEXTURE2**

Identifies the transformation matrix being set for the specified texture stage.

**D3DTS\_TEXTURE3**

Identifies the transformation matrix being set for the specified texture stage.

**D3DTS\_TEXTURE4**

Identifies the transformation matrix being set for the specified texture stage.

**D3DTS\_TEXTURE5**

Identifies the transformation matrix being set for the specified texture stage.

**D3DTS\_TEXTURE6**

Identifies the transformation matrix being set for the specified texture stage.

**D3DTS\_TEXTURE7**

Identifies the transformation matrix being set for the specified texture stage.

**D3DTS\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

The transform states in the range 256 through 511 are reserved to store up to 256 world matrices that can be indexed using the D3DTS\_WORLDMATRIX and D3DTS\_WORLD macros.

| Macros | Description |
|---------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| [**D3DTS\_WORLD**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-world) | Equivalent to D3DTS\_WORLDMATRIX(0). |
| [**D3DTS\_WORLDMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-worldmatrix) (index) | Identifies the transform matrix to set for the world matrix at index. Multiple world matrices are used only for vertex blending. Otherwise only D3DTS\_WORLD is used. |

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**IDirect3DDevice9::GetTransform**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-gettransform)

[**IDirect3DDevice9::MultiplyTransform**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-multiplytransform)

[**IDirect3DDevice9::SetTransform**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-settransform)

[**D3DTS\_WORLD**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-world)

[**D3DTS\_WORLDn**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-worldn)

[**D3DTS\_WORLDMATRIX**](https://learn.microsoft.com/windows/win32/direct3d9/d3dts-worldmatrix)

