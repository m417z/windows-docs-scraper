# D3D12_BUFFER_SRV structure

## Description

Describes the elements in a buffer resource to use in a shader-resource view.

## Members

### `FirstElement`

The index of the first element to be accessed by the view.

### `NumElements`

The number of elements in the resource.

### `StructureByteStride`

The size of each element in the buffer structure (in bytes) when the buffer represents a structured buffer. The size must match the struct size declared in shaders that access the view.

### `Flags`

A [D3D12_BUFFER_SRV_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_buffer_srv_flags)-typed value that identifies view options for the buffer. Currently, the only option is to identify a raw view of the buffer. For more info about raw viewing of buffers, see [Raw Views of Buffers](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).

## Remarks

This structure is used by [D3D12_SHADER_RESOURCE_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_shader_resource_view_desc) to create a view of a buffer.

If the value of *StructureByteStride* is not 0, then a view of a structured buffer is created, and then the *D3D12_SHADER_RESOURCE_VIEW_DESC::Format* field must be **DXGI_FORMAT_UNKNOWN**. If *StructureByteStride* is 0, then a typed view of a buffer is created, and then a format must be supplied. The specified format for the typed view must be supported by the hardware.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)