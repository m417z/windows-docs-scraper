# D3D10_SHADER_TYPE_DESC structure

## Description

Describes a shader-variable type.

## Members

### `Class`

Type: **[D3D10_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)**

Identifies the variable class as one of scalar, vector, matrix or object. See [D3D10_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class).

### `Type`

Type: **[D3D10_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)**

The variable type. See [D3D10_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type).

### `Rows`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of rows in a matrix. Otherwise a numeric type returns 1, any other type returns 0.

### `Columns`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of columns in a matrix. Otherwise a numeric type returns 1, any other type returns 0.

### `Elements`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of elements in an array; otherwise 0.

### `Members`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of members in the structure; otherwise 0.

### `Offset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Offset, in bytes, between the start of the parent structure and this variable.

## Remarks

Get a shader-variable-type description by calling [ID3D10ShaderReflectionType::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nf-d3d10shader-id3d10shaderreflectiontype-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)