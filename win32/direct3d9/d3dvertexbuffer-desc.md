# D3DVERTEXBUFFER\_DESC structure

Describes a vertex buffer.

## Members

**Format**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the surface format of the vertex buffer data.

**Type**

Type: **[**D3DRESOURCETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dresourcetype)**

Member of the [**D3DRESOURCETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dresourcetype) enumerated type, identifying this resource as a vertex buffer.

**Usage**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of one or more [**D3DUSAGE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dusage) flags.

**Pool**

Type: **[**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool)**

Member of the [**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) enumerated type, specifying the class of memory allocated for this vertex buffer.

**Size**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the vertex buffer, in bytes.

**FVF**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Combination of [D3DFVF](https://learn.microsoft.com/windows/win32/direct3d9/d3dfvf) that describes the vertex format of the vertices in this buffer.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetDesc**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dvertexbuffer9-getdesc)

[Vertex Buffers (Direct3D 9)](https://learn.microsoft.com/windows/win32/direct3d9/vertex-buffers)

