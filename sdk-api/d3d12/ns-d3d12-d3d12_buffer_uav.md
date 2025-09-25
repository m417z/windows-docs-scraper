# D3D12_BUFFER_UAV structure

## Description

Describes the elements in a buffer to use in a unordered-access view.

## Members

### `FirstElement`

The zero-based index of the first element to be accessed.

### `NumElements`

The number of elements in the resource. For structured buffers, this is the number of structures in the buffer.

### `StructureByteStride`

The size of each element in the buffer structure (in bytes) when the buffer represents a structured buffer.

### `CounterOffsetInBytes`

The counter offset, in bytes.

### `Flags`

A [D3D12_BUFFER_UAV_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_buffer_uav_flags)-typed value that specifies the view options for the resource.

## Remarks

Use this structure with a [D3D12_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_unordered_access_view_desc) structure to view the resource as a buffer.

If *StructureByteStride* value is not 0, a view of a structured buffer is created and the D3D12_UNORDERED_ACCESS_VIEW_DESC::Format field must be DXGI_FORMAT_UNKNOWN. If *StructureByteStride* is 0, a typed view of a buffer is created and a format must be supplied. The specified format for the typed view must be supported by the hardware. More information on this topic can be found in the [Typed unordered access view (UAV) loads](https://learn.microsoft.com/en-gb/windows/win32/direct3d12/typed-unordered-access-view-loads) page.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Typed unordered access view (UAV) loads](https://learn.microsoft.com/en-gb/windows/win32/direct3d12/typed-unordered-access-view-loads)