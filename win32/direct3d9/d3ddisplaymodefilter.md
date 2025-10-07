# D3DDISPLAYMODEFILTER structure

Specifies types of display modes to filter out.

## Members

**Size**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The size of this structure. This should always be set to sizeof(D3DDISPLAYMODEFILTER).

**Format**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

The display mode format to filter out. See [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat).

**ScanLineOrdering**

Type: **[**D3DSCANLINEORDERING**](https://learn.microsoft.com/windows/win32/direct3d9/d3dscanlineordering)**

Whether the scanline ordering is interlaced or progressive. See [**D3DSCANLINEORDERING**](https://learn.microsoft.com/windows/win32/direct3d9/d3dscanlineordering).

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

