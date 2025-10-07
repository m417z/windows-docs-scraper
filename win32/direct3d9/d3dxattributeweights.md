# D3DXATTRIBUTEWEIGHTS structure

Specifies mesh weight attributes.

## Members

**Position**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Position.

**Boundary**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Blend weight.

**Normal**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Normal.

**Diffuse**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Diffuse lighting value.

**Specular**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specular lighting value.

**Texcoord**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Eight texture coordinates.

**Tangent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Tangent.

**Binormal**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Binormal.

## Remarks

This structure describes how a simplification operation will consider vertex data when calculating relative costs between collapsing edges. For example, if the Normal field is 0.0, the simplification operation will ignore the vertex normal component when calculating the error for the collapse. However, if the Normal field is 1.0, the simplification operation will use the vertex normal component. If the Normal field is 2.0, double the amount of errors; if the Normal field is 4.0, then quadruple the number of errors, and so on.

The LPD3DXATTRIBUTEWEIGHTS type is defined as a pointer to the **D3DXATTRIBUTEWEIGHTS** structure.

```

    typedef D3DXATTRIBUTEWEIGHTS* LPD3DXATTRIBUTEWEIGHTS;
```

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

[**D3DXSimplifyMesh**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxsimplifymesh)

