# D3D12_SHADER_DESC structure

## Description

Describes a shader.

## Members

### `Version`

The Shader version, as an encoded UINT that corresponds to a shader model, such as "ps_5_0".
**Version** describes the program type, a major version number, and a minor version number.
The program type is a [D3D12_SHADER_VERSION_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12shader/ne-d3d12shader-d3d12_shader_version_type) enumeration constant.
**Version** is decoded in the following way:

* Program type = (Version & 0xFFFF0000) >> 16
* Major version = (Version & 0x000000F0) >> 4
* Minor version = (Version & 0x0000000F)

### `Creator`

The name of the originator of the shader.

### `Flags`

Shader compilation/parse flags.

### `ConstantBuffers`

The number of shader-constant buffers.

### `BoundResources`

The number of resource (textures and buffers) bound to a shader.

### `InputParameters`

The number of parameters in the input signature.

### `OutputParameters`

The number of parameters in the output signature.

### `InstructionCount`

The number of intermediate-language instructions in the compiled shader.

### `TempRegisterCount`

The number of temporary registers in the compiled shader.

### `TempArrayCount`

Number of temporary arrays used.

### `DefCount`

Number of constant defines.

### `DclCount`

Number of declarations (input + output).

### `TextureNormalInstructions`

Number of non-categorized texture instructions.

### `TextureLoadInstructions`

Number of texture load instructions

### `TextureCompInstructions`

Number of texture comparison instructions

### `TextureBiasInstructions`

Number of texture bias instructions

### `TextureGradientInstructions`

Number of texture gradient instructions.

### `FloatInstructionCount`

Number of floating point arithmetic instructions used.

### `IntInstructionCount`

Number of signed integer arithmetic instructions used.

### `UintInstructionCount`

Number of unsigned integer arithmetic instructions used.

### `StaticFlowControlCount`

Number of static flow control instructions used.

### `DynamicFlowControlCount`

Number of dynamic flow control instructions used.

### `MacroInstructionCount`

Number of macro instructions used.

### `ArrayInstructionCount`

Number of array instructions used.

### `CutInstructionCount`

Number of cut instructions used.

### `EmitInstructionCount`

Number of emit instructions used.

### `GSOutputTopology`

The [D3D_PRIMITIVE_TOPOLOGY](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_primitive_topology)-typed value that represents the geometry shader output topology.

### `GSMaxOutputVertexCount`

Geometry shader maximum output vertex count.

### `InputPrimitive`

The [D3D_PRIMITIVE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_primitive)-typed value that represents the input primitive for a geometry shader or hull shader.

### `PatchConstantParameters`

Number of parameters in the patch-constant signature.

### `cGSInstanceCount`

Number of geometry shader instances.

### `cControlPoints`

Number of control points in the hull shader and domain shader.

### `HSOutputPrimitive`

The [D3D_TESSELLATOR_OUTPUT_PRIMITIVE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_output_primitive)-typed value that represents the tessellator output-primitive type.

### `HSPartitioning`

The [D3D_TESSELLATOR_PARTITIONING](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_partitioning)-typed value that represents the tessellator partitioning mode.

### `TessellatorDomain`

The [D3D_TESSELLATOR_DOMAIN](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_tessellator_domain)-typed value that represents the tessellator domain.

### `cBarrierInstructions`

Number of barrier instructions in a compute shader.

### `cInterlockedInstructions`

Number of interlocked instructions in a compute shader.

### `cTextureStoreInstructions`

Number of texture writes in a compute shader.

## Remarks

A shader is written in HLSL and compiled into an intermediate language by the HLSL compiler.
The shader description returns information about the compiled shader.
To get a shader description, call [ID3D12ShaderReflection::GetDesc](https://learn.microsoft.com/windows/desktop/api/d3d12shader/nf-d3d12shader-id3d12shaderreflection-getdesc).

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-shader-structures)