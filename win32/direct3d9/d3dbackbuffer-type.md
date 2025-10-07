# D3DBACKBUFFER\_TYPE enumeration

Defines constants that describe the type of back buffer.

## Constants

**D3DBACKBUFFER\_TYPE\_MONO**

Specifies a nonstereo swap chain.

**D3DBACKBUFFER\_TYPE\_LEFT**

Specifies the left side of a stereo pair in a swap chain.

**D3DBACKBUFFER\_TYPE\_RIGHT**

Specifies the right side of a stereo pair in a swap chain.

**D3DBACKBUFFER\_TYPE\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Direct3D 9 does not support stereo view, so Direct3D does not use the D3DBACKBUFFER\_TYPE\_LEFT and D3DBACKBUFFER\_TYPE\_RIGHT values of this enumerated type.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**IDirect3DDevice9::GetBackBuffer**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getbackbuffer)

[**IDirect3DSwapChain9::GetBackBuffer**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dswapchain9-getbackbuffer)

