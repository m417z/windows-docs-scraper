# D3D10_SHADER_DEBUG_INPUT_INFO structure

## Description

Describes a shader input.

## Members

### `Var`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Index into array of variables to initialize.

### `InitialRegisterSet`

Type: **[D3D10_SHADER_DEBUG_REGTYPE](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ne-d3d10_1shader-d3d10_shader_debug_regtype)**

Must be D3D10_SHADER_DEBUG_REG_INPUT, D3D10_SHADER_DEBUG_REG_CBUFFER or D3D10_SHADER_DEBUG_REG_TBUFFER.

### `InitialBank`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Will contain a cbuffer or tbuffer slot, geometry shader input primitive number, identifying register for an indexable temp, or -1.

### `InitialRegister`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Register in register set. **InitialRegister** will be -1 if it is temporary.

### `InitialComponent`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Gives the component. **InitialComponent** will be -1 it is temporary.

### `InitialValue`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Initial value if the variable is a literal.

## Remarks

The **D3D10_SHADER_DEBUG_INPUT_INFO** structure is used with the [D3D10_SHADER_DEBUG_INFO](https://learn.microsoft.com/windows/win32/api/d3d10_1shader/ns-d3d10_1shader-d3d10_shader_debug_info) structure.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)