# D3DTRIPATCH\_INFO structure

Describes a triangular high-order patch.

## Members

**StartVertexOffset**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Starting vertex offset, in number of vertices.

**NumVertices**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of vertices.

**Basis**

Type: **[**D3DBASISTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbasistype)**

Member of the [**D3DBASISTYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dbasistype) enumerated type, which defines the basis type for the triangular high-order patch. The only valid value for this member is D3DBASIS\_BEZIER.

**Degree**

Type: **[**D3DDEGREETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddegreetype)**

Member of the [**D3DDEGREETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddegreetype) enumerated type, defining the degree type for the triangular high-order patch.

| Value | Number of vertices |
|----------------------|--------------------|
| D3DDEGREE\_CUBIC | 10 |
| D3DDEGREE\_LINEAR | 3 |
| D3DDEGREE\_QUADRATIC | N/A |
| D3DDEGREE\_QUINTIC | 21 |

N/A - Not available. Not supported.

## Remarks

For example, the following diagram identifies the vertex order and segment numbers for a cubic Bézier triangle patch. The vertex order determines the segment numbers used by [**DrawTriPatch**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-drawtripatch). The offset is the number of bytes to the first triangle patch vertex in the vertex buffer.

![diagram of a triangular high-order patch with nine vertices](https://learn.microsoft.com/windows/win32/direct3d9/images/hop-tripatch-info.png)

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**DrawTriPatch**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-drawtripatch)

[**D3DXTessellateTriPatch**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxtessellatetripatch)

