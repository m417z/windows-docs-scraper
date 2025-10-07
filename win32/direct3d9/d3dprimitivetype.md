# D3DPRIMITIVETYPE enumeration

Defines the primitives supported by Direct3D.

## Constants

**D3DPT\_POINTLIST**

Renders the vertices as a collection of isolated points. This value is unsupported for indexed primitives.

**D3DPT\_LINELIST**

Renders the vertices as a list of isolated straight line segments.

**D3DPT\_LINESTRIP**

Renders the vertices as a single polyline.

**D3DPT\_TRIANGLELIST**

Renders the specified vertices as a sequence of isolated triangles. Each group of three vertices defines a separate triangle.

Back-face culling is affected by the current winding-order render state.

**D3DPT\_TRIANGLESTRIP**

Renders the vertices as a triangle strip. The backface-culling flag is automatically flipped on even-numbered triangles.

**D3DPT\_TRIANGLEFAN**

Renders the vertices as a triangle fan.

**D3DPT\_FORCE\_DWORD**

Forces this enumeration to compile to 32 bits in size. Without this value, some compilers would allow this enumeration to compile to a size other than 32 bits. This value is not used.

## Remarks

Using [Triangle Strips](https://learn.microsoft.com/windows/win32/direct3d9/triangle-strips) or [Triangle Fans (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/triangle-fans) is often more efficient than using triangle lists because fewer vertices are duplicated.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Enumerations](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-enums)

[**IDirect3DDevice9::DrawIndexedPrimitive**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-drawindexedprimitive)

[**IDirect3DDevice9::DrawIndexedPrimitiveUP**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-drawindexedprimitiveup)

[**IDirect3DDevice9::DrawPrimitive**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-drawprimitive)

[**IDirect3DDevice9::DrawPrimitiveUP**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3ddevice9-drawprimitiveup)

