# D3D11_SHADER_DESC structure

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

Type: **[D3D_PRIMITIVE_TOPOLOGY](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_primitive_topology)**

The [D3D_PRIMITIVE_TOPOLOGY](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_primitive_topology)-typed value that represents the geometry shader output topology.

### `GSMaxOutputVertexCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Geometry shader maximum output vertex count.

### `InputPrimitive`

Type: **[D3D_PRIMITIVE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_primitive)**

The [D3D_PRIMITIVE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_primitive)-typed value that represents the input primitive for a geometry shader or hull shader.

### `PatchConstantParameters`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of parameters in the patch-constant signature.

### `cGSInstanceCount`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of geometry shader instances.

### `cControlPoints`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of control points in the hull shader and domain shader.

### `HSOutputPrimitive`

Type: **[D3D_TESSELLATOR_OUTPUT_PRIMITIVE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_output_primitive)**

The [D3D_TESSELLATOR_OUTPUT_PRIMITIVE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_output_primitive)-typed value that represents the tessellator output-primitive type.

### `HSPartitioning`

Type: **[D3D_TESSELLATOR_PARTITIONING](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_partitioning)**

The [D3D_TESSELLATOR_PARTITIONING](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_partitioning)-typed value that represents the tessellator partitioning mode.

### `TessellatorDomain`

Type: **[D3D_TESSELLATOR_DOMAIN](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_domain)**

The [D3D_TESSELLATOR_DOMAIN](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_domain)-typed value that represents the tessellator domain.

### `cBarrierInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of barrier instructions in a compute shader.

### `cInterlockedInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of interlocked instructions in a compute shader.

### `cTextureStoreInstructions`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of texture writes in a compute shader.

## Remarks

A shader is written in HLSL and compiled into an intermediate language by the HLSL compiler. The shader description returns information about the compiled shader. Get a shader description by calling [ID3D11ShaderReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d11shader/nf-d3d11shader-id3d11shaderreflection-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)