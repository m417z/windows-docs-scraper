# D3D10_SHADER_DEBUG_INST_INFO structure

## Description

Contains instruction data.

## Members

### `Id`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Id of the instruction.

### `Opcode`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Type of instruction.

### `uOutputs`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Must be 0, 1 or 2.

### `pOutputs`

Type: **[D3D10_SHADER_DEBUG_OUTPUTREG_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_outputreg_info)**

Array containing the outputs of the instruction.

### `TokenId`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into the list of tokens for this instruction's token.

### `NestingLevel`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of function calls deep this instruction is.

### `Scopes`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of scopes.

### `ScopeInfo`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset to an array of UINT values with **Scopes** elements.

### `AccessedVars`

### `AccessedVarsInfo`

## Remarks

The **D3D10_SHADER_DEBUG_INST_INFO** structure is used with the [D3D10_SHADER_DEBUG_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_info) structure.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)