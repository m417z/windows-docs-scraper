# D3DXSHADER\_CONSTANTINFO structure

## Members

**Name**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Offset from the beginning of this structure, in bytes, to the string that contains the constant information.

**RegisterSet**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Register set. See [**D3DXREGISTER\_SET**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxregister-set).

**RegisterIndex**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The register index.

**RegisterCount**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of registers.

**Reserved**

Type: **[**WORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Reserved.

**TypeInfo**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Offset from the beginning of this structure, in bytes, to the string that contains the [**D3DXSHADER\_TYPEINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-typeinfo) information.

**DefaultValue**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Offset from the beginning of this structure, in bytes, to the string that contains the default value.

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9shader.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

