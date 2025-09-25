# ID3D12Device::CreateConstantBufferView

## Description

Creates a constant-buffer view for accessing resource data.

## Parameters

### `pDesc` [in, optional]

Type: **const [D3D12_CONSTANT_BUFFER_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_constant_buffer_view_desc)***

A pointer to a [D3D12_CONSTANT_BUFFER_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_constant_buffer_view_desc) structure that describes the constant-buffer view.

### `DestDescriptor` [in]

Type: **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)**

Describes the CPU descriptor handle that represents the start of the heap that holds the constant-buffer view.

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)