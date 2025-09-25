# ID3D12Device::CreateRenderTargetView

## Description

Creates a render-target view for accessing resource data.

## Parameters

### `pResource` [in, optional]

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)***

A pointer to the [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) object that represents the render target.

At least one of *pResource* or *pDesc* must be provided.
A null *pResource* is used to initialize a null descriptor, which guarantees D3D11-like null binding behavior (reading 0s, writes are discarded), but must have a valid *pDesc* in order to determine the descriptor type.

### `pDesc` [in, optional]

Type: **const [D3D12_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_view_desc)***

A pointer to a [D3D12_RENDER_TARGET_VIEW_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_render_target_view_desc) structure that describes the render-target view.

A null *pDesc* is used to initialize a default descriptor, if possible. This behavior is identical to the D3D11 null descriptor behavior, where defaults are filled in. This behavior inherits the resource format and dimension (if not typeless) and RTVs target the first mip and all array slices. Not all resources support null descriptor initialization.

### `DestDescriptor` [in]

Type: **[D3D12_CPU_DESCRIPTOR_HANDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_cpu_descriptor_handle)**

Describes the CPU descriptor handle that represents the destination where the newly-created render target view will reside.

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)