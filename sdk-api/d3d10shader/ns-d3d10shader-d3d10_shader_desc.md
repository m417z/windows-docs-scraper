## Description

Describes a shader.

## Members

### `Version`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shader version.

### `Creator`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The name of the originator of the shader.

### `Flags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Shader compilation/parse flags.

### `ConstantBuffers`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of shader-constant buffers.

### `BoundResources`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of resource (textures and buffers) bound to a shader.

### `InputParameters`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of parameters in the input signature.

### `OutputParameters`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of parameters in the output signature.

### `InstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of intermediate-language instructions in the compiled shader.

### `TempRegisterCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of temporary registers in the compiled shader.

### `TempArrayCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of temporary arrays used.

### `DefCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of constant defines.

### `DclCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of declarations (input + output).

### `TextureNormalInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of non-categorized texture instructions.

### `TextureLoadInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of texture load instructions

### `TextureCompInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of texture comparison instructions

### `TextureBiasInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of texture bias instructions

### `TextureGradientInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of texture gradient instructions.

### `FloatInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of floating point arithmetic instructions used.

### `IntInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of signed integer arithmetic instructions used.

### `UintInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of unsigned integer arithmetic instructions used.

### `StaticFlowControlCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of static flow control instructions used.

### `DynamicFlowControlCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of dynamic flow control instructions used.

### `MacroInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of macro instructions used.

### `ArrayInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of array instructions used.

### `CutInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of cut instructions used.

### `EmitInstructionCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of emit instructions used.

### `GSOutputTopology`

Type: **[D3D10_PRIMITIVE_TOPOLOGY](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/bb205334(v=vs.85))**

Geometry shader output topology.

### `GSMaxOutputVertexCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Geometry shader maximum output vertex count.

#### - BitwiseInstructionCount

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of bitwise operations.

#### - ConversionInstructionCount

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of conversion operations.

#### - MovInstructionCount

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of mov instructions.

#### - MovcInstructionCount

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of movc instructions.

## Remarks

A shader is written in HLSL and compiled into an intermediate language by the HLSL compiler. The shader description returns information about the compiled shader. Get a shader description by calling [ID3D10ShaderReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d10shader/nf-d3d10shader-id3d10shaderreflection-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-shader-structures)