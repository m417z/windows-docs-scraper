# D3D10_SHADER_DEBUG_OUTPUTREG_INFO structure

## Description

Describes a shader output register.

## Members

### `OutputRegisterSet`

Type: **[D3D10_SHADER_DEBUG_REGTYPE](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ne-d3d10_1shader-d3d10_shader_debug_regtype)**

Must be D3D10_SHADER_DEBUG_REG_TEMP, D3D10_SHADER_DEBUG_REG_TEMPARRAY or D3D10_SHADER_DEBUG_REG_OUTPUT.

### `OutputReg`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value of -1 indicates no output.

### `TempArrayReg`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If **OutputRegisterSet** is D3D10_SHADER_DEBUG_REG_TEMPARRAY this indicates which temp array.

### `OutputComponents`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A value of -1 means the component is masked out.

### `OutputVars`

Type: **[D3D10_SHADER_DEBUG_OUTPUTVAR](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_outputvar)**

Indicates which variable the instruction is writing per-component.

### `IndexReg`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset from OutputReg of the element being written to. Used when writing to an indexable temp array or an output.

### `IndexComp`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset from OutputReg of the element being written to. Used when writing to an indexable temp array or an output.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)