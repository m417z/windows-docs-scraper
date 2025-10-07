# D3DXRTS\_DESC structure

Describes a render surface.

## Members

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the render surface, in pixels.

**Height**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of the render surface, in pixels.

**Format**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the pixel format of the render surface.

**DepthStencil**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

If **TRUE**, the render surface supports a depth-stencil surface; otherwise this member is set to **FALSE**.

**DepthStencilFormat**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

If DepthStencil is set to **TRUE**, this parameter is a member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the depth-stencil format of the render surface.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9core.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

[**ID3DXRenderToSurface::GetDesc**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxrendertosurface--getdesc)

