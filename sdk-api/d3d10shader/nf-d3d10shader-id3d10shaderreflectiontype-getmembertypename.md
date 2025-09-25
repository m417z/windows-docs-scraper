## Description

Retrieves a shader-reflection-variable name given the index to that member of the struct type.

## Parameters

### `Index` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

A zero-based index to a member of the struct type.

## Return value

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/winprog/windows-data-types)**

The member name in the form of a stringified value of the [D3D_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/win32/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type) enumeration.

## See also

* [ID3D10ShaderReflectionType](https://learn.microsoft.com/windows/win32/api/d3d10shader/nn-d3d10shader-id3d10shaderreflectiontype) interface
* [D3D_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/win32/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type) enumeration