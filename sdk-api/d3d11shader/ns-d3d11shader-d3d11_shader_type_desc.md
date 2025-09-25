# D3D11_SHADER_TYPE_DESC structure

## Description

Describes a shader-variable type.

## Members

### `Class`

Type: **[D3D_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)**

A [D3D_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)-typed value that identifies the variable class as one of scalar, vector, matrix, object, and so on.

### `Type`

Type: **[D3D_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)**

A [D3D_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)-typed value that identifies the variable type.

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

Offset, in bytes, between the start of the parent structure and this variable. Can be 0 if not a structure member.

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Name of the shader-variable type. This member can be **NULL** if it isn't used. This member supports dynamic shader linkage interface types, which have names. For more info about dynamic shader linkage, see [Dynamic Linking](https://learn.microsoft.com/windows/desktop/direct3dhlsl/overviews-direct3d-11-hlsl-dynamic-linking).

## Remarks

Get a shader-variable-type description by calling [ID3D11ShaderReflectionType::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflectiontype-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)