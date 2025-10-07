# CD3DX12_PIPELINE_STATE_STREAM2 structure

A helper structure for creating and working with graphics and compute pipeline states through a combined interface. See [**D3D12_GRAPHICS_PIPELINE_STATE_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) and [**D3D12_COMPUTE_PIPELINE_STATE_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc).

**CD3DX12_PIPELINE_STATE_STREAM2** supports OS Build 19041+ (where there is a mesh shader pipeline).

## Members

`CD3DX12_PIPELINE_STATE_STREAM2`

Default constructor. Creates a new, uninitialized, instance of a **CD3DX12_PIPELINE_STATE_STREAM2**.

`CD3DX12_PIPELINE_STATE_STREAM2(const D3D12_GRAPHICS_PIPELINE_STATE_DESC&)`

Constructor that creates a new instance of a **CD3DX12_PIPELINE_STATE_STREAM2** initialized with the contents of a [**D3D12_GRAPHICS_PIPELINE_STATE_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) structure.

You'll then need to set mesh and amplification shaders manually, since they don't have representation in **D3D12_GRAPHICS_PIPELINE_STATE_DESC**.

`CD3DX12_PIPELINE_STATE_STREAM2(const D3DX12_MESH_SHADER_PIPELINE_STATE_DESC&)`

Constructor that creates a new instance of a **CD3DX12_PIPELINE_STATE_STREAM2** initialized with the contents of a [**D3DX12_MESH_SHADER_PIPELINE_STATE_DESC**](https://learn.microsoft.com/windows/win32/direct3d12/d3dx12-mesh-shader-pipeline-state-desc) structure.

`CD3DX12_PIPELINE_STATE_STREAM2(const D3D12_COMPUTE_PIPELINE_STATE_DESC&)`

Constructor that creates a new instance of a **CD3DX12_PIPELINE_STATE_STREAM2** initialized with the contents of a [**D3D12_COMPUTE_PIPELINE_STATE_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc) structure.

`Flags`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_FLAGS](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-flags)**

Flags (for example, to indicate that the pipeline state should be compiled with additional information to assist debugging).

`NodeMask`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_NODE_MASK](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-node-mask)**

Describes the pipeline state node mask, which is used to identify the nodes (physical adapters of the device) that the PSO applies to in multi-adapter scenarios; each bit in the mask corresponds to a single node. For single-adapter scenarios, use 0.

`pRootSignature`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_ROOT_SIGNATURE](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-root-signature)**

Describes the root signature.

`InputLayout`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_INPUT_LAYOUT](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-input-layout)**

Describes the input-buffer format for the input-assembler stage

`IBStripCutValue`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_IB_STRIP_CUT_VALUE](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-ib-strip-cut-value)**

Describes the special index value of the input buffer that indicates a cut (discontinuity) when using triangle-strip topology.

`PrimitiveTopologyType`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_PRIMITIVE_TOPOLOGY](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-primitive-topology)**

Describes the primitive topology and its order.

`VS`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_VS](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-vs)**

Describes the vertex shader.

`GS`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_GS](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-gs)**

Describes the geometry shader.

`StreamOutput`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_STREAM_OUTPUT](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-stream-output)**

Describes the streaming output-buffer.

`HS`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_HS](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-hs)**

Describes the hull shader.

`DS`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_DS](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-ds)**

Describes the domain shader.

`PS`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_PS](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-ps)**

Describes the pixel shader.

`AS`

Type: **CD3DX12_PIPELINE_STATE_STREAM_AS**

Describes the amplification shader.

`MS`

Type: **CD3DX12_PIPELINE_STATE_STREAM_MS**

Describes the mesh shader.

`CS`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_CS](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-cs)**

Describes the compute shader.

`BlendState`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_BLEND_DESC](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-blend-desc)**

Describes the blend state.

`DepthStencilState`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_DEPTH_STENCIL1](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-depth-stencil1)**

Describes the depth-stencil state.

`DSVFormat`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_DEPTH_STENCIL_FORMAT](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-depth-stencil-format)**

Describes the depth-stencil format.

`RasterizerState`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_RASTERIZER](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-rasterizer)**

Describes the rasterizer state.

`RTVFormats`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_RENDER_TARGET_FORMATS](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-render-target-formats)**

Describes the render target formats.

`SampleDesc`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_SAMPLE_DESC](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-sample-desc)**

Describes the sample count and quality.

`SampleMask`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_SAMPLE_MASK](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-sample-mask)**

Describes the sample mask used with the blend state.

`CachedPSO`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_CACHED_PSO](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-cached-pso)**

Describes a cached PSO.

`ViewInstancingDesc`

Type: **[CD3DX12_PIPELINE_STATE_STREAM_VIEW_INSTANCING](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-view-instancing)**

Describes a view instancing configuration.

`GraphicsDescV0`

Returns [**D3D12_GRAPHICS_PIPELINE_STATE_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc).

returns the contents of the **CD3DX12_PIPELINE_STATE_STREAM2** object as a **D3D12_GRAPHICS_PIPELINE_STATE_DESC** structure by value. **D3D12_GRAPHICS_PIPELINE_STATE_DESC** doesn't include the *CS* member, so that value is lost in the conversion.

`ComputeDescV0`

Returns [**D3D12_COMPUTE_PIPELINE_STATE_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc).

returns the contents of the **CD3DX12_PIPELINE_STATE_STREAM2** object as a **D3D12_COMPUTE_PIPELINE_STATE_DESC** structure by value. **D3D12_COMPUTE_PIPELINE_STATE_DESC** doesn't include the members *InputLayout*, *IBStripCutValue*, *PrimitiveTopologyType*, *VS*, *GS*, *StreamOutput*, *HS*, *DS*, *PS*, *BlendState*, *DepthStencilState*, *DSVFormat*, *RasterizerState*, *NumRootSignature*, *RTVFormats*, *SampleDesc*, and *SampleMask*, so those values are lost in the conversion.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header | [D3dx12.h](https://github.com/microsoft/DirectX-Headers/blob/main/include/directx/d3dx12.h) |

## See also

* [Helper structures for Direct3D 12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)