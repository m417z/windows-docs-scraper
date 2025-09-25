# D3D12_PIPELINE_STATE_SUBOBJECT_TYPE enumeration

## Description

Specifies the type of a sub-object in a pipeline state stream description.

## Constants

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_ROOT_SIGNATURE:0`

Indicates a root signature subobject type.
The corresponding subobject type is **[ID3D12RootSignature](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12rootsignature)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VS`

Indicates a vertex shader subobject type.
The corresponding subobject type is **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PS`

Indicates a pixel shader subobject type.
The corresponding subobject type is **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DS`

Indicates a domain shader subobject type.
The corresponding subobject type is **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_HS`

Indicates a hull shader subobject type.
The corresponding subobject type is **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_GS`

Indicates a geometry shader subobject type.
The corresponding subobject type is **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CS`

Indicates a compute shader subobject type.
The corresponding subobject type is **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_STREAM_OUTPUT`

Indicates a stream-output subobject type.
The corresponding subobject type is **[D3D12_STREAM_OUTPUT_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_stream_output_desc)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_BLEND`

Indicates a blend subobject type.
The corresponding subobject type is **[D3D12_BLEND_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_blend_desc)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_MASK`

Indicates a sample mask subobject type.
The corresponding subobject type is **UINT**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RASTERIZER`

Indicates indicates a rasterizer subobject type.
The corresponding subobject type is **[D3D12_RASTERIZER_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_rasterizer_desc)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL`

Indicates a depth stencil subobject type.
The corresponding subobject type is **[D3D12_DEPTH_STENCIL_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_INPUT_LAYOUT`

Indicates an input layout subobject type.
The corresponding subobject type is **[D3D12_INPUT_LAYOUT_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_input_layout_desc)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_IB_STRIP_CUT_VALUE`

Indicates an index buffer strip cut value subobject type.
The corresponding subobject type is **[D3D12_INDEX_BUFFER_STRIP_CUT_VALUE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_index_buffer_strip_cut_value)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_PRIMITIVE_TOPOLOGY`

Indicates a primitive topology subobject type.
The corresponding subobject type is **[D3D12_PRIMITIVE_TOPOLOGY_TYPE](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_primitive_topology_type)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_RENDER_TARGET_FORMATS`

Indicates a render target formats subobject type. The corresponding subobject type is **[D3D12_RT_FORMAT_ARRAY](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_rt_format_array)** structure, which wraps an array of render target formats along with a count of the array elements.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL_FORMAT`

Indicates a depth stencil format subobject.
The corresponding subobject type is **[DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_SAMPLE_DESC`

Indicates a sample description subobject type.
The corresponding subobject type is **[DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/win32/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_NODE_MASK`

Indicates a node mask subobject type.
The corresponding subobject type is **[D3D12_NODE_MASK](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_node_mask)** or **UINT**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_CACHED_PSO`

Indicates a cached pipeline state object subobject type.
The corresponding subobject type is **[D3D12_CACHED_PIPELINE_STATE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_cached_pipeline_state)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_FLAGS`

Indicates a flags subobject type.
The corresponding subobject type is **[D3D12_PIPELINE_STATE_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_pipeline_state_flags)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_DEPTH_STENCIL1`

Indicates an expanded depth stencil subobject type. This expansion of the depth stencil subobject supports optional depth bounds checking.
The corresponding subobject type is **[D3D12_DEPTH_STENCIL_DESC1](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_depth_stencil_desc1)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_VIEW_INSTANCING`

Indicates a view instancing subobject type.
The corresponding subobject type is **[D3D12_VIEW_INSTANCING_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_view_instancing_desc)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_AS:24`

Indicates an amplification shader subobject type.
The corresponding subobject type is **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MS:25`

Indicates a mesh shader subobject type.
The corresponding subobject type is **[D3D12_SHADER_BYTECODE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_shader_bytecode)**.

### `D3D12_PIPELINE_STATE_SUBOBJECT_TYPE_MAX_VALID`

A sentinel value that marks the exclusive upper-bound of valid values this enumeration represents.

## Remarks

This enum is used in the creation of pipeline state objects using the ID3D12Device1::CreatePipelineState method. The CreatePipelineState method takes a D3D12_PIPELINE_STATE_STREAM_DESC as one of its parameters, this structure in turn describes a bytestream made up of alternating D3D12_PIPELINE_STATE_SUBOBJECT_TYPE enumeration values and their corresponding subobject description structs. This bytestream description can be made a concrete type by defining a structure that has the same alternating pattern of alternating D3D12_PIPELINE_STATE_SUBOBJECT_TYPE enumeration values and their corresponding subobject description structs as members.

## See also

See [**D3D12_PIPELINE_STATE_STREAM_DESC**](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_pipeline_state_stream_desc) for a description of the layout and behavior of a streaming pipeline desc.

[Core Enumerations](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-enumerations)