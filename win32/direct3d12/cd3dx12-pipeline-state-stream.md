# CD3DX12\_PIPELINE\_STATE\_STREAM structure

A helper structure for creating and working with graphics and compute pipeline states through a combined interface. See [**D3D12\_GRAPHICS\_PIPELINE\_STATE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc) and [**D3D12\_COMPUTE\_PIPELINE\_STATE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc).

CD3DX12\_PIPELINE\_STATE\_STREAM supports Windows 10 Creators Update and newer but doesn't support new features of the Fall Creators update, such as view instancing. To support features of the Fall Creators update, use [**CD3DX12\_PIPELINE\_STATE\_STREAM1**](https://www.bing.com/search?q=**CD3DX12/_PIPELINE/_STATE/_STREAM1**) instead.

## Members

**CD3DX12\_PIPELINE\_STATE\_STREAM()**

Creates a new, uninitialized, instance of a CD3DX12\_PIPELINE\_STATE\_STREAM.

**CD3DX12\_PIPELINE\_STATE\_STREAM(const D3D12\_GRAPHICS\_PIPELINE\_STATE\_DESC& Desc)**

Creates a new instance of a CD3DX12\_PIPELINE\_STATE\_STREAM, initialized with values copied from a **CD3DX12\_PIPELINE\_STATE\_STREAM** structure.

**CD3DX12\_PIPELINE\_STATE\_STREAM(const D3D12\_COMPUTE\_PIPELINE\_STATE\_DESC& Desc)**

Creates a new instance of a CD3DX12\_PIPELINE\_STATE\_STREAM, initialized with values copied from a **CD3DX12\_PIPELINE\_STATE\_STREAM** structure.

**GraphicsDescV0()**

returns the contents of the CD3DX12\_PIPELINE\_STATE\_STREAM object as a D3D12\_GRAPHICS\_PIPELINE\_STATE\_DESC structure by value. Note that D3D12\_GRAPHICS\_PIPELINE\_STATE\_DESC does not include the **CS** member, so this value is lost in the conversion.

**ComputeDescV0()**

returns the contents of the CD3DX12\_PIPELINE\_STATE\_STREAM object as a D3D12\_COMPUTE\_PIPELINE\_STATE\_DESC structure by value. Note that D3D12\_COMPUTE\_PIPELINE\_STATE\_DESC does not include the **InputLayout**, **IBStripCutValue**, **PrimitiveTopologyType**, **VS**, **GS**, **StreamOutput**, **HS**, **DS**, **PS**, **BlendState**, **DepthStencilState**, **DSVFormat**, **RasterizerState**, **NumRootSignature**, **RTVFormats**, **SampleDesc**, or **SampleMask** members, so these values are lost in the conversion.

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

CD3DX12\_PIPELINE\_STATE\_STREAM supports Windows 10 Creators Update and newer, but doesn not support subobject types added in Windows 10 Fall Creators update, such as for view instancing. To support subobject types added in the Fall Creators update, use [**CD3DX12\_PIPELINE\_STATE\_STREAM1**](https://www.bing.com/search?q=**CD3DX12/_PIPELINE/_STATE/_STREAM1**) instead.

The accessible member variables of this structure are all typedefs of the CD3DX12\_PIPELINE\_STATE\_STREAM\_SUBOBJECT template, which combines the subobject type-marker and subobject data into a single object suitable for a stream description.

Those typedefs are:

## Requirements

| Requirement | Value |
|-------------------|-------------------------------------------------------------------------------------|
| Header<br> | D3dx12.h |

## See also

[Helper Structures for D3D12](https://learn.microsoft.com/windows/win32/direct3d12/helper-structures-for-d3d12)

[**CD3DX12\_PIPELINE\_STATE\_STREAM1**](https://learn.microsoft.com/windows/win32/direct3d12/cd3dx12-pipeline-state-stream1)

[**D3D12\_GRAPHICS\_PIPELINE\_STATE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_graphics_pipeline_state_desc)

[**D3D12\_COMPUTE\_PIPELINE\_STATE\_DESC**](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_compute_pipeline_state_desc)

