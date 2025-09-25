# D3D12_PARAMETER_DESC structure

## Description

Describes a function parameter.

## Members

### `Name`

The name of the function parameter.

### `SemanticName`

The HLSL [semantic](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics) that is associated with this function parameter. This name includes the index, for example, SV_Target[n].

### `Type`

A [D3D_SHADER_VARIABLE_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_type)-typed value that identifies the variable type for the parameter.

### `Class`

A [D3D_SHADER_VARIABLE_CLASS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_shader_variable_class)-typed value that identifies the variable class for the parameter as one of scalar, vector, matrix, object, and so on.

### `Rows`

The number of rows for a matrix parameter.

### `Columns`

The number of columns for a matrix parameter.

### `InterpolationMode`

A [D3D_INTERPOLATION_MODE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_interpolation_mode)-typed value that identifies the interpolation mode for the parameter.

### `Flags`

A combination of [D3D_PARAMETER_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_parameter_flags)-typed values that are combined by using a bitwise OR operation. The resulting value specifies semantic flags for the parameter.

### `FirstInRegister`

The first input register for this parameter.

### `FirstInComponent`

The first input register component for this parameter.

### `FirstOutRegister`

The first output register for this parameter.

### `FirstOutComponent`

The first output register component for this parameter.

## Remarks

Get a function-parameter description by calling [ID3D12FunctionParameterReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12functionparameterreflection-getdesc).

## See also

[ID3D12FunctionParameterReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12functionparameterreflection-getdesc)

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-shader-structures)