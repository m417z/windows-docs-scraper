# D3DXSEMANTIC structure

Semantics map a parameter to vertex or pixel shader registers. They can also be optional descriptive strings attached to non-register parameters.

## Members

**Usage**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Options that identify how resources are used. See [**D3DDECLUSAGE**](https://learn.microsoft.com/windows/win32/direct3d9/d3ddeclusage).

**UsageIndex**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Options that modify how the usage is interpreted. The usage and usage index make up a vertex declaration. See [Vertex Declaration (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/vertex-declaration).

## Remarks

Semantics are required for vertex and pixel shader, input and output registers.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9shader.h |

## See also

[Effect Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-structures)

