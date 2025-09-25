# D3D12_GRAPHICS_PIPELINE_STATE_DESC structure

## Description

Describes a graphics pipeline state object.

## Members

### `pRootSignature`

A pointer to the [ID3D12RootSignature](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12rootsignature) object.

### `VS`

A [D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode) structure that describes the vertex shader.

### `PS`

A [D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode) structure that describes the pixel shader.

### `DS`

A [D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode) structure that describes the domain shader.

### `HS`

A [D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode) structure that describes the hull shader.

### `GS`

A [D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode) structure that describes the geometry shader.

### `StreamOutput`

A [D3D12_STREAM_OUTPUT_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_stream_output_desc) structure that describes a streaming output buffer.

### `BlendState`

A [D3D12_BLEND_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_blend_desc) structure that describes the blend state.

### `SampleMask`

The sample mask for the blend state.

### `RasterizerState`

A [D3D12_RASTERIZER_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_rasterizer_desc) structure that describes the rasterizer state.

### `DepthStencilState`

A [D3D12_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc) structure that describes the depth-stencil state.

### `InputLayout`

A [D3D12_INPUT_LAYOUT_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_input_layout_desc) structure that describes the input-buffer data for the input-assembler stage.

### `IBStripCutValue`

Specifies the properties of the index buffer in a [D3D12_INDEX_BUFFER_STRIP_CUT_VALUE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_index_buffer_strip_cut_value) structure.

### `PrimitiveTopologyType`

A [D3D12_PRIMITIVE_TOPOLOGY_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_primitive_topology_type)-typed value for the type of primitive, and ordering of the primitive data.

### `NumRenderTargets`

The number of render target formats in the **RTVFormats** member.

### `RTVFormats`

An array of [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed values for the render target formats.

### `DSVFormat`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value for the depth-stencil format.

### `SampleDesc`

A [DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc) structure that specifies multisampling parameters.

### `NodeMask`

For single GPU operation, set this to zero. If there are multiple GPU nodes, set bits to identify the nodes (the device's physical adapters) for which the graphics pipeline state is to apply.
Each bit in the mask corresponds to a single node.
Refer to [Multi-adapter systems](https://learn.microsoft.com/windows/win32/direct3d12/multi-engine).

### `CachedPSO`

A cached pipeline state object, as a [D3D12_CACHED_PIPELINE_STATE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_cached_pipeline_state) structure. pCachedBlob and CachedBlobSizeInBytes may be set to NULL and 0 respectively.

### `Flags`

A [D3D12_PIPELINE_STATE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_pipeline_state_flags) enumeration constant such as for "tool debug".

## Remarks

This structure is used by the [CreateGraphicsPipelineState](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12device-creategraphicspipelinestate) method.

The runtime validates:

* Whether the linkage between the shader stages is correct.
* If the **HS** and **DS** members are specified, the **PrimitiveTopologyType** member for topology type must be set to [D3D12_PRIMITIVE_TOPOLOGY_TYPE_PATCH](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_primitive_topology_type).
* Whether sample frequency execution isn't allowed with the center multi-sample anti-aliasing (MSAA) pattern.
* Whether anti-aliasing lines aren't allowed with the center MSAA pattern.
* If the **ForcedSampleCount** member of [D3D12_RASTERIZER_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_rasterizer_desc) that **RasterizerState** specifies isn't zero:

  + Depth/stencil must be disabled.
  + Pixel shader can't output depth.
  + Pixel shader can't run at sample frequency.
  + Render target sample count must be 1.
* Whether blend state is compatible with render target formats.
* Whether pixel shader output type is compatible with render target format.
* Whether the sample count and quality are supported for the render target/depth stencil formats.

## See also

[Conservative Rasterization](https://learn.microsoft.com/windows/win32/direct3d12/conservative-rasterization)

[Core Structures](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-structures)

[Rasterizer Ordered Views](https://learn.microsoft.com/windows/win32/direct3d12/rasterizer-order-views)