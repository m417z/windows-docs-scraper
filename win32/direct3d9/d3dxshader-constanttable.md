# D3DXSHADER\_CONSTANTTABLE structure

Helper structure for managing a shader constant table. This can also be done using [**ID3DXConstantTable**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable).

## Members

**Size**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Size of the structure. See Remarks.

**Creator**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Offset from the beginning of this structure, in bytes, to the string that contains the name of the creator.

**Version**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Shader version.

**Constants**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Number of constants.

**ConstantInfo**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Array of constant information, D3DXSHADER\_CONSTANTINFO\[*Constants*\]. See [**D3DXSHADER\_CONSTANTINFO**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-constantinfo).

**Flags**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The [D3DXSHADER Flags](https://learn.microsoft.com/windows/win32/direct3d9/d3dxshader-flags) flags used to compile the shader.

**Target**

Type: **[**DWORD**](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

Offset into the string that contains the target.

## Remarks

Shader constant information is included in a tab-delimited table of comments. All offsets are measured in bytes from the beginning of the structure. Entries in the constant table are sorted by Creator in ascending order.

A shader constant table can be managed with the [**ID3DXConstantTable**](https://learn.microsoft.com/windows/win32/direct3d9/id3dxconstanttable) interfaces. Alternatively, you can manage the constant table with **D3DXSHADER\_CONSTANTTABLE**.

This size member is often initialized using the following:

```
D3DXSHADER_CONSTANTTABLE constantTable;
constantTable.Size = sizeof(D3DXSHADER_CONSTANTTABLE)
```

## Requirements

| Requirement | Value |
|-------------------|------------------------------------------------------------------------------------------|
| Header<br> | D3dx9shader.h |

## See also

[D3DX Structures](https://learn.microsoft.com/windows/win32/direct3d9/dx9-graphics-reference-d3dx-structures)

[**D3DXGetShaderConstantTable**](https://learn.microsoft.com/windows/win32/direct3d9/d3dxgetshaderconstanttable)

