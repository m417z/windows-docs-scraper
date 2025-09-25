# D3D12_FUNCTION_DESC structure

## Description

Describes a function.

## Members

### `Version`

The shader version.
See also [D3D12_SHADER_VERSION_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12shader/ne-d3d12shader-d3d12_shader_version_type).

### `Creator`

The name of the originator of the function.

### `Flags`

A combination of [D3DCOMPILE Constants](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-constants) that are combined by using a bitwise OR operation. The resulting value specifies shader compilation and parsing.

### `ConstantBuffers`

The number of constant buffers for the function.

### `BoundResources`

The number of bound resources for the function.

### `InstructionCount`

The number of emitted instructions for the function.

### `TempRegisterCount`

The number of temporary registers used by the function.

### `TempArrayCount`

The number of temporary arrays used by the function.

### `DefCount`

The number of constant defines for the function.

### `DclCount`

The number of declarations (input + output) for the function.

### `TextureNormalInstructions`

The number of non-categorized texture instructions for the function.

### `TextureLoadInstructions`

The number of texture load instructions for the function.

### `TextureCompInstructions`

The number of texture comparison instructions for the function.

### `TextureBiasInstructions`

The number of texture bias instructions for the function.

### `TextureGradientInstructions`

The number of texture gradient instructions for the function.

### `FloatInstructionCount`

The number of floating point arithmetic instructions used by the function.

### `IntInstructionCount`

The number of signed integer arithmetic instructions used by the function.

### `UintInstructionCount`

The number of unsigned integer arithmetic instructions used by the function.

### `StaticFlowControlCount`

The number of static flow control instructions used by the function.

### `DynamicFlowControlCount`

The number of dynamic flow control instructions used by the function.

### `MacroInstructionCount`

The number of macro instructions used by the function.

### `ArrayInstructionCount`

The number of array instructions used by the function.

### `MovInstructionCount`

The number of mov instructions used by the function.

### `MovcInstructionCount`

The number of movc instructions used by the function.

### `ConversionInstructionCount`

The number of type conversion instructions used by the function.

### `BitwiseInstructionCount`

The number of bitwise arithmetic instructions used by the function.

### `MinFeatureLevel`

A [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)-typed value that specifies the minimum Direct3D feature level target of the function byte code.

### `RequiredFeatureFlags`

A value that contains a combination of one or more shader requirements flags; each flag specifies a requirement of the shader. A default value of 0 means there are no requirements. For a list of values, see [ID3D12ShaderReflection::GetRequiresFlags](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12shaderreflection-getrequiresflags).

### `Name`

The name of the function.

### `FunctionParameterCount`

The number of logical parameters in the function signature, not including the return value.

### `HasReturn`

Indicates whether the function returns a value. **TRUE** indicates it returns a value; otherwise, **FALSE** (it is a subroutine).

### `Has10Level9VertexShader`

Indicates whether there is a Direct3D 10Level9 vertex shader blob. **TRUE** indicates there is a 10Level9 vertex shader blob; otherwise, **FALSE**.

### `Has10Level9PixelShader`

Indicates whether there is a Direct3D 10Level9 pixel shader blob. **TRUE** indicates there is a 10Level9 pixel shader blob; otherwise, **FALSE**.

## Remarks

This structure is returned by [ID3D12FunctionReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12functionreflection-getdesc).

## See also

[ID3D12FunctionReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12functionreflection-getdesc)

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-shader-structures)