# D3DXEFFECTINSTANCE structure

Data type for managing a set of default effect parameters.

## Members

**pEffectFilename**

Type: **LPSTR**

Name of the effect file.

**NumDefaults**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of default parameters.

**pDefaults**

Type: **[**LPD3DXEFFECTDEFAULT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectdefault)**

Pointer to an array of [**D3DXEFFECTDEFAULT**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxeffectdefault) elements, each of which contains an effect parameter.

## Requirements

| Requirement | Value |
|-------------------|----------------------------------------------------------------------------------------|
| Header<br> | D3dx9mesh.h |

## See also

[Effect Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-effects-structures)

