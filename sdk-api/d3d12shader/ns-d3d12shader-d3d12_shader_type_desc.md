# D3D12_SHADER_TYPE_DESC structure

## Description

Describes a shader-variable type.

## Members

### `Class`

A [D3D_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)-typed value that identifies the variable class as one of scalar, vector, matrix, object, and so on.

### `Type`

A [D3D_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)-typed value that identifies the variable type.

### `Rows`

Number of rows in a matrix. Otherwise a numeric type returns 1, any other type returns 0.

### `Columns`

Number of columns in a matrix. Otherwise a numeric type returns 1, any other type returns 0.

### `Elements`

Number of elements in an array; otherwise 0.

### `Members`

Number of members in the structure; otherwise 0.

### `Offset`

Offset, in bytes, between the start of the parent structure and this variable. Can be 0 if not a structure member.

### `Name`

Name of the shader-variable type. This member can be **NULL** if it isn't used. This member supports dynamic shader linkage interface types, which have names. For more info about dynamic shader linkage, see [Dynamic Linking](https://learn.microsoft.com/windows/desktop/direct3dhlsl/overviews-direct3d-11-hlsl-dynamic-linking).

## Remarks

Get a shader-variable-type description by calling [ID3D12ShaderReflectionType::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12shaderreflectiontype-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-shader-structures)