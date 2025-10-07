# D3DX12_MESH_SHADER_PIPELINE_STATE_DESC structure

For [mesh/amplifications shaders](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html), you can use the data from an [EffectPipelineStateDescription](https://github.com/Microsoft/DirectXTK12/wiki/EffectPipelineStateDescription), with **D3DX12_MESH_SHADER_PIPELINE_STATE_DESC**, to provide all the state.

Also see [CD3DX12_PIPELINE_STATE_STREAM2](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream1).

For a code example, see [Mesh shaders](https://github.com/Microsoft/DirectXTK12/wiki/EffectPipelineStateDescription#mesh-shaders).

## Members

`pRootSignature`

Type: **[ID3D12RootSignature](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12rootsignature)\***

A root signature object defining what resources are bound to the pipeline.

`AS`

Type: **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**

Contains the data representing the amplification shader program.

`MS`

Type: **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**

Contains the data representing the mesh shader program.

`PS`

Type: **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**

Contains the data representing the pixel shader program.

`BlendState`

Type: **[D3D12_BLEND_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_blend_desc)**

Describes the blend state.

`SampleMask`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The sample mask for the blend state.

`RasterizerState`

Type: **[D3D12_RASTERIZER_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_rasterizer_desc)**

Describes the rasterizer state.

`DepthStencilState`

Type: **[D3D12_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc)**

Describes the depth-stencil state.

`PrimitiveTopologyType`

Type: **[D3D12_PRIMITIVE_TOPOLOGY_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_primitive_topology_type)**

Describes the type and ordering of the primitive data.

`NumRenderTargets`

Type: **[UINT](https://learn.microsoft.com/windows/win32/winprog/windows-data-types)**

The number of render target formats in the *RTVFormats* member.

`RTVFormats`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)**

An array of values for the render target formats.

`DSVFormat`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)**

A value for the depth-stencil format.

`SampleDesc`

Type: **[DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)**

Specifies multisampling parameters.

`CachedPSO`

Type: **[D3D12_CACHED_PIPELINE_STATE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_cached_pipeline_state)**

A cached pipeline state object. *pCachedBlob* and *CachedBlobSizeInBytes* may be set to NULL and 0 respectively.

`Flags`

Type: **[D3D12_PIPELINE_STATE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_pipeline_state_flags)**

A flag enumeration constant (for example, to indicate that the pipeline state should be compiled with additional information to assist debugging).

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header | [D3dx12.h](https://github.com/microsoft/DirectX-Headers/blob/main/include/directx/d3dx12.h) |

## See also

* [Helper structures for Direct3D 12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)
* [CD3DX12_PIPELINE_STATE_STREAM2](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream1)
* [mesh/amplifications shaders](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html)
* [EffectPipelineStateDescription](https://github.com/Microsoft/DirectXTK12/wiki/EffectPipelineStateDescription)