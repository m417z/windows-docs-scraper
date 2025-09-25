# D3D12DDI_ROOT_SIGNATURE_FLAGS enumeration

## Description

Specifies options for root signature layout.

## Constants

### `D3D12DDI_ROOT_SIGNATURE_FLAG_NONE:0x0`

Indicates default behavior.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT:0x1`

The app is opting in to using the Input Assembler (requiring an input layout that defines a set of vertex buffer bindings). Omitting this flag can result in one root argument space being saved on some hardware. Omit this flag if the Input Assembler is not required, though the optimization is minor.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_DENY_VERTEX_SHADER_ROOT_ACCESS:0x2`

Denies the vertex shader access to the root signature.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS:0x4`

Denies the hull shader access to the root signature.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS:0x8`

Denies the domain shader access to the root signature.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS:0x10`

Denies the geometry shader access to the root signature.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_DENY_PIXEL_SHADER_ROOT_ACCESS:0x20`

Denies the pixel shader access to the root signature.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_ALLOW_STREAM_OUTPUT:0x40`

The root signature allows stream output.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_LOCAL_ROOT_SIGNATURE:0x80`

The local root signature is supported.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_DENY_AMPLIFICATION_SHADER_ROOT_ACCESS:0x100`

Denies the amplification shader access to the root signature. Available starting with Windows 10, version 2004. See the [Mesh Shader specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information about amplification shaders.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_DENY_MESH_SHADER_ROOT_ACCESS:0x200`

Denies the mesh shader access to the root signature. Available starting with Windows 10, version 2004. See the [Mesh Shader specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information about mesh shaders.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_CBV_SRV_UAV_HEAP_DIRECTLY_INDEXED:0x400`

Shaders are allowed to index the CBV/SRV/UAV descriptor heap directly.

### `D3D12DDI_ROOT_SIGNATURE_FLAG_SAMPLER_HEAP_DIRECTLY_INDEXED:0x800`

Shaders are allowed to index the sampler descriptor heap directly.

## Remarks

See the [DirectX Raytracing (DXR) functional specification](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.