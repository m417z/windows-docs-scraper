# D3D11_PARAMETER_DESC structure

## Description

Describes a function parameter.

## Members

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the function parameter.

### `SemanticName`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The HLSL [semantic](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics) that is associated with this function parameter. This name includes the index, for example, SV_Target[n].

### `Type`

Type: **[D3D_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)**

A [D3D_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)-typed value that identifies the variable type for the parameter.

### `Class`

Type: **[D3D_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)**

A [D3D_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)-typed value that identifies the variable class for the parameter as one of scalar, vector, matrix, object, and so on.

### `Rows`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of rows for a matrix parameter.

### `Columns`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of columns for a matrix parameter.

### `InterpolationMode`

Type: **[D3D_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_interpolation_mode)**

A [D3D_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_interpolation_mode)-typed value that identifies the interpolation mode for the parameter.

### `Flags`

Type: **[D3D_PARAMETER_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_parameter_flags)**

A combination of [D3D_PARAMETER_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_parameter_flags)-typed values that are combined by using a bitwise OR operation. The resulting value specifies semantic flags for the parameter.

### `FirstInRegister`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The first input register for this parameter.

### `FirstInComponent`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The first input register component for this parameter.

### `FirstOutRegister`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The first output register for this parameter.

### `FirstOutComponent`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The first output register component for this parameter.

## Remarks

Get a function-parameter description by calling [ID3D11FunctionParameterReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11functionparameterreflection-getdesc).

## See also

[ID3D11FunctionParameterReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11functionparameterreflection-getdesc)

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)