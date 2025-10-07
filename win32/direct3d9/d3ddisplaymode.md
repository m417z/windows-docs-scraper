# D3DDISPLAYMODE structure

Describes the display mode.

## Members

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Screen width, in pixels.

**Height**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Screen height, in pixels.

**RefreshRate**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Refresh rate. The value of 0 indicates an adapter default.

**Format**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the surface format of the display mode.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**EnumAdapterModes**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-enumadaptermodes)

[**GetAdapterDisplayMode**](https://learn.microsoft.com/windows/win32/api/d3d9/nf-d3d9-idirect3d9-getadapterdisplaymode)

[**GetDisplayMode**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-getdisplaymode)

