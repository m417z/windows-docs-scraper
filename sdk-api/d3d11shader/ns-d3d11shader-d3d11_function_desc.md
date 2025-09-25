# D3D11_FUNCTION_DESC structure

## Description

Describes a function.

## Members

### `Version`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The shader version.

### `Creator`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the originator of the function.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3DCOMPILE Constants](https://learn.microsoft.com/windows/desktop/direct3dhlsl/d3dcompile-constants) that are combined by using a bitwise OR operation. The resulting value specifies shader compilation and parsing.

### `ConstantBuffers`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of constant buffers for the function.

### `BoundResources`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bound resources for the function.

### `InstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of emitted instructions for the function.

### `TempRegisterCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of temporary registers used by the function.

### `TempArrayCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of temporary arrays used by the function.

### `DefCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of constant defines for the function.

### `DclCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of declarations (input + output) for the function.

### `TextureNormalInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of non-categorized texture instructions for the function.

### `TextureLoadInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of texture load instructions for the function.

### `TextureCompInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of texture comparison instructions for the function.

### `TextureBiasInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of texture bias instructions for the function.

### `TextureGradientInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of texture gradient instructions for the function.

### `FloatInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of floating point arithmetic instructions used by the function.

### `IntInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of signed integer arithmetic instructions used by the function.

### `UintInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of unsigned integer arithmetic instructions used by the function.

### `StaticFlowControlCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of static flow control instructions used by the function.

### `DynamicFlowControlCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of dynamic flow control instructions used by the function.

### `MacroInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of macro instructions used by the function.

### `ArrayInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of array instructions used by the function.

### `MovInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of mov instructions used by the function.

### `MovcInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of movc instructions used by the function.

### `ConversionInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of type conversion instructions used by the function.

### `BitwiseInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of bitwise arithmetic instructions used by the function.

### `MinFeatureLevel`

Type: **[D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)**

A [D3D_FEATURE_LEVEL](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)-typed value that specifies the minimum Direct3D feature level target of the function byte code.

### `RequiredFeatureFlags`

Type: **UINT64**

A value that contains a combination of one or more shader requirements flags; each flag specifies a requirement of the shader. A default value of 0 means there are no requirements. For a list of values, see [ID3D11ShaderReflection::GetRequiresFlags](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflection-getrequiresflags).

### `Name`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the function.

### `FunctionParameterCount`

Type: **INT**

The number of logical parameters in the function signature, not including the return value.

### `HasReturn`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates whether the function returns a value. **TRUE** indicates it returns a value; otherwise, **FALSE** (it is a subroutine).

### `Has10Level9VertexShader`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates whether there is a Direct3D 10Level9 vertex shader blob. **TRUE** indicates there is a 10Level9 vertex shader blob; otherwise, **FALSE**.

### `Has10Level9PixelShader`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Indicates whether there is a Direct3D 10Level9 pixel shader blob. **TRUE** indicates there is a 10Level9 pixel shader blob; otherwise, **FALSE**.

## See also

[ID3D11FunctionReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11functionreflection-getdesc)

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)