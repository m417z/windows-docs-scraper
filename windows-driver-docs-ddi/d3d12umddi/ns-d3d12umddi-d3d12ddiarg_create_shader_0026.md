# D3D12DDIARG_CREATE_SHADER_0026 structure

## Description

The **D3D12DDIARG_CREATE_SHADER_0026** structure contains the parameters that the display driver uses to create a shader.

## Members

### `hRootSignature`

Handle to a root signature.

### `pShaderCode`

Pointer to the shader code.

### `IOSignatures`

IO signature.

### `IOSignatures.Standard`

Pointer to a D3D12DDIARG_STAGE_IO_SIGNATURES structure.

### `IOSignatures.Tessellation`

Pointer to a D3D12DDIARG_TESSELLATION_IO_SIGNATURES structure.

### `IOSignatures.Mesh`

Pointer to a [**D3D12DDIARG_MESH_IO_SIGNATURES**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_mesh_io_signatures) structure.

### `Flags`

A [**D3D12DDI_CREATE_SHADER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_create_shader_flags) value specifying the flags for shader creation.

### `LibraryReference`

A [**D3D12DDI_LIBRARY_REFERENCE_0010**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_library_reference_0010) structure describing a pipeline library.

### `ShaderCodeHash`

A [**D3D12DDI_SHADERCACHE_HASH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shadercache_hash) structure containing a hash value to associate with the shader for shader cache lookup.

## Remarks

See the [Mesh Shader specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

## See also

[**D3D12DDI_CREATE_SHADER_FLAGS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_create_shader_flags)

[**D3D12DDI_LIBRARY_REFERENCE_0010**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_library_reference_0010)

[**D3D12DDI_SHADERCACHE_HASH**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_shadercache_hash)