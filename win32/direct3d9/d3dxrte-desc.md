# D3DXRTE\_DESC structure

Describes an off-screen render target used by an instance of [**ID3DXRenderToEnvMap**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxrendertoenvmap).

## Members

**Size**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width and height in pixels.

**MipLevels**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Maximum level of detail (LOD) number.

**Format**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Color buffer format.

**DepthStencil**

Type: **[**BOOL**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Indicates if the z-buffer is needed.

**DepthStencilFormat**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Format of the depth buffer.

## Remarks

This method is used to return the creation parameters used when creating an [**ID3DXRenderToEnvMap**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxrendertoenvmap) object.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9core.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

