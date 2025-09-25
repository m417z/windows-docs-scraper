# D3D10_EFFECT_TYPE_DESC structure

## Description

Describes an effect-variable type.

## Members

### `TypeName`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A string that contains the variable name.

### `Class`

Type: **[D3D10_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)**

The variable class (see [D3D10_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)).

### `Type`

Type: **[D3D10_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)**

The variable type (see [D3D10_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)).

### `Elements`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of elements if the variable is an array; otherwise 0.

### `Members`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of members if the variable is a structure; otherwise 0.

### `Rows`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of rows if the variable is a matrix; otherwise 0.

### `Columns`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of columns if the variable is a matrix; otherwise 0.

### `PackedSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bytes that the variable consumes when it is packed tightly by the compiler.

### `UnpackedSize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bytes that the variable consumes before it is packed by the compiler.

### `Stride`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bytes between elements.

## Remarks

To get an effect-variable type, call [ID3D10EffectType::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10effect/nf-d3d10effect-id3d10effecttype-getdesc).

## See also

[Effect Structures (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-effect-structures)