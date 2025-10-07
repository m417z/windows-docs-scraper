# D3DRECTPATCH\_INFO structure

Describes a rectangular high-order patch.

## Members

**StartVertexOffsetWidth**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Starting vertex offset width, in number of vertices.

**StartVertexOffsetHeight**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Starting vertex offset height, in number of vertices.

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of each vertex, in number of vertices.

**Height**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of each vertex, in number of vertices.

**Stride**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the imaginary two-dimensional vertex array, which occupies the same space as the vertex buffer. For an example, see the diagram below.

**Basis**

Type: **[**D3DBASISTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbasistype)**

Member of the [**D3DBASISTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbasistype) enumerated type, defining the basis type for the rectangular high-order patch.

| Value | Order supported | Width and height |
|-----------------------|----------------------------|-----------------------------------|
| D3DBASIS\_BEZIER | Linear, cubic, and quintic | Width = height = (DWORD)order + 1 |
| D3DBASIS\_BSPLINE | Linear, cubic, and quintic | Width = height > (DWORD)order |
| D3DBASIS\_INTERPOLATE | Cubic | Width = height > (DWORD)order |

**Degree**

Type: **[**D3DDEGREETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddegreetype)**

Member of the [**D3DDEGREETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddegreetype) enumerated type, defining the degree for the rectangular patch.

## Remarks

The following diagram identifies the parameters that specify a rectangle patch.

![diagram of a rectangular high-order patch and the parameters that specify it](https://learn.microsoft.com/windows/win32/direct3d9/images/hop-rectpatch.png)

Each of the vertices in the vertex buffer is shown as a black dot. In this case, the vertex buffer has 20 vertices in it, 16 of which are in the rectangle patch. The stride is the number of vertices in the width of the vertex buffer, in this case five. The x offset to the first vertex is called the StartIndexVertexWidth and is in this case 1. The y offset to the first patch vertex is called the StartIndexVertexHeight and is in this case 0.

To render a stream of individual rectangular patches (non-mosaic), you should interpret your geometry as a long narrow (1 x N) rectangular patch. The **D3DRECTPATCH\_INFO** structure for such a strip (cubic Bézier) would be set up in the following manner.

```

D3DRECTPATCH_INFO RectInfo;

RectInfo.Width = 4;
RectInfo.Height = 4;
RectInfo.Stride = 4;
RectInfo.Basis = D3DBASIS_BEZIER;
RectInfo.Order = D3DORDER_CUBIC;
RectInfo.StartVertexOffsetWidth = 0;
RectInfo.StartVertexOffsetHeight = 4*i;  // The variable i is the index of the
//   patch you want to render.
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**DrawRectPatch**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-drawrectpatch)

[**D3DXTessellateRectPatch**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxtessellaterectpatch)

