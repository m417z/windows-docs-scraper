# CD3DX12_PIPELINE_STATE_STREAM1 structure

A helper structure for creating and working with graphics and compute pipeline states through a combined interface. See [D3D12_GRAPHICS_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) and [D3D12_COMPUTE_PIPELINE_STATE_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc).

CD3DX12_PIPELINE_STATE_STREAM1 supports the Windows 10 Fall Creators Update with new features such as view instancing.

See [CD3DX12_PIPELINE_STATE_STREAM2](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream2) for support for OS Build 19041+ (where there is a mesh shader pipeline).

## Members

**CD3DX12_PIPELINE_STATE_STREAM1()**

Creates a new, uninitialized, instance of a CD3DX12_PIPELINE_STATE_STREAM1.

**CD3DX12_PIPELINE_STATE_STREAM1(const D3D12_GRAPHICS_PIPELINE_STATE_DESC& Desc)**

Creates a new instance of a CD3DX12_PIPELINE_STATE_STREAM1, initialized with values copied from a **CD3DX12_PIPELINE_STATE_STREAM1** structure.

**CD3DX12_PIPELINE_STATE_STREAM1(const D3D12_COMPUTE_PIPELINE_STATE_DESC& Desc)**

Creates a new instance of a CD3DX12_PIPELINE_STATE_STREAM1, initialized with values copied from a **CD3DX12_PIPELINE_STATE_STREAM1** structure.

**GraphicsDescV0()**

returns the contents of the CD3DX12_PIPELINE_STATE_STREAM1 object as a D3D12_GRAPHICS_PIPELINE_STATE_DESC structure by value. Note that D3D12_GRAPHICS_PIPELINE_STATE_DESC does not include the **CS** member, so this value is lost in the conversion.

**ComputeDescV0()**

returns the contents of the CD3DX12_PIPELINE_STATE_STREAM1 object as a D3D12_COMPUTE_PIPELINE_STATE_DESC structure by value. Note that D3D12_COMPUTE_PIPELINE_STATE_DESC does not include the **InputLayout**, **IBStripCutValue**, **PrimitiveTopologyType**, **VS**, **GS**, **StreamOutput**, **HS**, **DS**, **PS**, **BlendState**, **DepthStencilState**, **DSVFormat**, **RasterizerState**, **NumRootSignature**, **RTVFormats**, **SampleDesc**, or **SampleMask** members, so these values are lost in the conversion.

**Flags**

Describes the pipeline state flags, which control features such as "tool debug".

**NodeMask**

Describes the pipeline state node mask, which is used to identify the nodes (physical adapters of the device) that the PSO applies to in Multi-Adapter scenarios; each bit in the mask corresponds to a single node. For single-adapter scenarios, set this value to 0.

**pRootSignature**

Describes the root signature.

**InputLayout**

Describes the input-buffer format for the input-assembler stage

**IBStripCutValue**

Describes the special index value of the input buffer that indicates a cut (discontinuity) when using triangle-strip topology.

**PrimitiveTopologyType**

Describes the primitive topology and its order.

**VS**

Describes the vertex shader.

**GS**

Describes the geometry shader.

**StreamOutput**

Describes the streaming output-buffer.

**HS**

Describes the hull shader.

**DS**

Describes the domain shader.

**PS**

Describes the pixel shader.

**CS**

Describes the compute shader.

**BlendState**

Describes the blend state.

**DepthStencilState**

Describes the depth-stencil state.

**DSVFormat**

Describes the depth-stencil format.

**RasterizerState**

Describes the rasterizer state.

**RTVFormats**

Describes the render target formats.

**SampleDesc**

Describes the sample count and quality.

**SampleMask**

Describes the sample mask used with the blend state.

**CachedPSO**

Describes a cached PSO.

## Remarks

[CD3DX12_PIPELINE_STATE_STREAM](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream) supports the Windows 10 Fall Creators Update, but doesn't support subobject types added in Windows 10 Fall Creators update, such as for view instancing. To support the new subobject types, use **CD3DX12_PIPELINE_STATE_STREAM1** instead.

The accessible member variables of this structure are all typedefs of the [**CD3DX12_PIPELINE_STATE_STREAM_SUBOBJECT**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream-subobject) template, which combines the subobject type-marker and subobject data into a single object suitable for a stream description.

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header | [D3dx12.h](https://github.com/microsoft/DirectX-Headers/blob/main/include/directx/d3dx12.h) |

## See also

* [Helper structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)
* [**CD3DX12_PIPELINE_STATE_STREAM**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream)
* [**D3D12_GRAPHICS_PIPELINE_STATE_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc)
* [**D3D12_COMPUTE_PIPELINE_STATE_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc)