# D3DCOMPOSERECTDESC structure

Specifies the rectangle used to enclose glyphs on a monochrome surface.

## Members

**X**

Type: **[**USHORT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Left coordinate to begin copy at.

**Y**

Type: **[**USHORT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Top coordinate to begin copy at.

**Width**

Type: **[**USHORT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of texels from left coordinate.

**Height**

Type: **[**USHORT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of texels from the top coordinate.

## Remarks

This structure is used in calls to [**ComposeRects**](https://learn.microsoft.com/windows/desktop/api/d3d9/nf-d3d9-idirect3ddevice9ex-composerects) to enclose glyphs on the source surface. A vertex buffer (see [**IDirect3DVertexBuffer9**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nn-d3d9helper-idirect3dvertexbuffer9)) filled with these structures are created to contain the glyph locations. USHORT members are used to reduce the memory footprint as much as possible.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3d9types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

