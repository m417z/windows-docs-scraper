# D3DX10\_WELD\_EPSILONS structure

Specifies tolerance values for each vertex component when comparing vertices to determine if they are similar enough to be welded together.

## Members

**Position**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Position

**BlendWeights**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Blend weight

**Normal**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Normal

**PSize**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Point size value

**Specular**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Specular lighting value

**Diffuse**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Diffuse lighting value

**Texcoord**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Eight texture coordinates

**Tangent**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Tangent

**Binormal**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Binormal

**TessFactor**

Type: **[**FLOAT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Tessellation factor

## Remarks

The LPD3DXWeldEpsilons type is defined as a pointer to the D3DXWeldEpsilons structure.

```
typedef D3DX_WELD_EPSILONS *LPD3DX_WELD_EPSILONS;
```

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3DX10.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d10/d3d10-graphics-reference-d3dx10-structures)

