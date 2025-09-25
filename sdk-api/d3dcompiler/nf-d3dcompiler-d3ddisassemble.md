# D3DDisassemble function

## Description

Disassembles compiled HLSL code.

## Parameters

### `pSrcData` [in]

Type: **[LPCVOID](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to source data as compiled HLSL code.

### `SrcDataSize` [in]

Type: **[SIZE_T](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Length of *pSrcData*.

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags affecting the behavior of **D3DDisassemble**. *Flags* can be a combination of zero or more of the following values.

| Flag | Description |
| --- | --- |
| **D3D_DISASM_ENABLE_COLOR_CODE** | Enable the output of color codes. |
| **D3D_DISASM_ENABLE_DEFAULT_VALUE_PRINTS** | Enable the output of default values. |
| **D3D_DISASM_ENABLE_INSTRUCTION_NUMBERING** | Enable instruction numbering. |
| **D3D_DISASM_ENABLE_INSTRUCTION_CYCLE** | No effect. |
| **D3D_DISASM_DISABLE_DEBUG_INFO** | Disable debug information. |
| **D3D_DISASM_ENABLE_INSTRUCTION_OFFSET** | Enable instruction offsets. |
| **D3D_DISASM_INSTRUCTION_ONLY** | Disassemble instructions only. |
| **D3D_DISASM_PRINT_HEX_LITERALS** | Use hex symbols in disassemblies. |

### `szComments` [in, optional]

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The comment string at the top of the shader that identifies the shader constants and variables.

### `ppDisassembly` [out]

Type: **[ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85))****

A pointer to a buffer that receives the [ID3DBlob](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/ff728743(v=vs.85)) interface that accesses assembly text.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Returns one of the [Direct3D 11 return codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[Functions](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-d3dcompiler-reference-functions)