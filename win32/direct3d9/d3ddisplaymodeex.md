# D3DDISPLAYMODEEX structure

Information about the properties of a display mode.

## Members

**Size**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of this structure. This should always be set to sizeof(D3DDISPLAYMODEEX).

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the display mode.

**Height**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of the display mode.

**RefreshRate**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Refresh rate of the display mode.

**Format**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Format of the display mode. See [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat).

**ScanLineOrdering**

Type: **[**D3DSCANLINEORDERING**](https://learn.microsoft.com/windows/win32/direct3d9/d3dscanlineordering)**

Indicates whether the scanline order is progressive or interlaced. See [**D3DSCANLINEORDERING**](https://learn.microsoft.com/windows/win32/direct3d9/d3dscanlineordering).

## Remarks

This structure is used in various methods to create and manage Direct3D 9Ex devices ([**IDirect3DDevice9Ex**](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3ddevice9ex)) and swapchains ([**IDirect3DSwapChain9Ex**](https://learn.microsoft.com/windows/desktop/api/d3d9/nn-d3d9-idirect3dswapchain9ex)).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

