## Description

Creates a view for unordered accessing.

## Parameters

### `pResource`

Type: [in, optional] **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)***

A pointer to the [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) object that represents the unordered access.
At least one of *pResource* or *pDesc* must be provided.

A null *pResource* is used to initialize a null descriptor, which guarantees Direct3D 11-like null binding behavior (reading 0s, writes are discarded), but must have a valid *pDesc* in order to determine the descriptor type.

### `pCounterResource`

Type: [in, optional] **[ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource)***

The [ID3D12Resource](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12resource) for the counter (if any) associated with the UAV.

If *pCounterResource* is not specified, then the **CounterOffsetInBytes** member of the [D3D12_BUFFER_UAV](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_buffer_uav) structure must be 0.

If *pCounterResource* is specified, then there is a counter associated with the UAV, and the runtime performs validation of the following requirements:

* The **StructureByteStride** member of the [D3D12_BUFFER_UAV](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_buffer_uav) structure must be greater than 0.
* The format must be DXGI_FORMAT_UNKNOWN.
* The D3D12_BUFFER_UAV_FLAG_RAW flag (a [D3D12_BUFFER_UAV_FLAGS](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_buffer_uav_flags) enumeration constant) must not be set.
* Both of the resources (*pResource* and *pCounterResource*) must be buffers.
* The **CounterOffsetInBytes** member of the [D3D12_BUFFER_UAV](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_buffer_uav) structure must be a multiple of **D3D12_UAV_COUNTER_PLACEMENT_ALIGNMENT** (4096), and must be within the range of the counter resource.
* *pResource* cannot be NULL
* *pDesc* cannot be NULL.

### `pDesc`

Type: [in, optional] **const [D3D12_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_unordered_access_view_desc)***

A pointer to a [D3D12_UNORDERED_ACCESS_VIEW_DESC](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_unordered_access_view_desc) structure that describes the unordered-access view.
A null *pDesc* is used to initialize a default descriptor, if possible. This behavior is identical to the D3D11 null descriptor behavior, where defaults are filled in. This behavior inherits the resource format and dimension (if not typeless) and for buffers UAVs target a full buffer and are typed, and for textures UAVs target the first mip and all array slices. Not all resources support null descriptor initialization.

### `DestDescriptor` [in]

Type: **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)**

Describes the CPU descriptor handle that represents the start of the heap that holds the unordered-access view.

## See also

[ID3D12Device](https://learn.microsoft.com/windows/win32/api/d3d12/nn-d3d12-id3d12device)