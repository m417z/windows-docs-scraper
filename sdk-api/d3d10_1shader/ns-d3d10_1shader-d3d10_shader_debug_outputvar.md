# D3D10_SHADER_DEBUG_OUTPUTVAR structure

## Description

Describes a shader output variable.

## Members

### `Var`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index variable being written to or if -1 it's not going to a variable.

### `uValueMin`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum UINT value.

### `uValueMax`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum UINT value.

### `iValueMin`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum INT value.

### `iValueMax`

Type: **[INT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum UINT value.

### `fValueMin`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Minimum FLOAT value.

### `fValueMax`

Type: **[FLOAT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Maximum FLOAT value.

### `bNaNPossible`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates whether the output variable can evaluate to not a number.

### `bInfPossible`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates whether the output variable can evaluate to infinity.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)