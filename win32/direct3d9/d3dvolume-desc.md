# D3DVOLUME\_DESC structure

Describes a volume.

## Members

**Format**

Type: **[D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat)**

Member of the [D3DFORMAT](https://learn.microsoft.com/windows/win32/direct3d9/d3dformat) enumerated type, describing the surface format of the volume.

**Type**

Type: **[**D3DRESOURCETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dresourcetype)**

Member of the [**D3DRESOURCETYPE**](https://learn.microsoft.com/windows/win32/direct3d9/d3dresourcetype) enumerated type, identifying this resource as a volume.

**Usage**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Currently not used. Always returned as 0.

**Pool**

Type: **[**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool)**

Member of the [**D3DPOOL**](https://learn.microsoft.com/windows/win32/direct3d9/d3dpool) enumerated type, specifying the class of memory allocated for this volume.

**Width**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Width of the volume, in pixels.

**Height**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Height of the volume, in pixels.

**Depth**

Type: **[**UINT**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Depth of the volume, in pixels.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3D9Types.h |

## See also

[Direct3D Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3d-structures)

[**GetDesc**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dvolume9-getdesc)

[**GetLevelDesc**](https://learn.microsoft.com/windows/win32/api/d3d9helper/nf-d3d9helper-idirect3dvolumetexture9-getleveldesc)

