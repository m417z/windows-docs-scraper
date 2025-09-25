## Description

Indicates that the contents of a resource don't need to be preserved. The function may re-initialize resource metadata in some cases.

## Parameters

### `pResource`

Type: [in] **[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)***

A pointer to the [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) interface for the resource to discard.

### `pRegion`

Type: [in, optional] **const [D3D12_DISCARD_REGION](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_discard_region)***

A pointer to a [D3D12_DISCARD_REGION](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_discard_region) structure that describes details for the discard-resource operation.

## Remarks

The semantics of **DiscardResource** change based on the command list type.

For [D3D12_COMMAND_LIST_TYPE_DIRECT](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_command_list_type), the following two rules apply:

* When a resource has the [D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flag, **DiscardResource** must be called when the discarded subresource regions are in the [D3D12_RESOURCE_STATE_RENDER_TARGET](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) resource barrier state.
* When a resource has the [D3D12_RESOURCE_FLAG _ALLOW_DEPTH_STENCIL](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flag, **DiscardResource** must be called when the discarded subresource regions are in the [D3D12_RESOURCE_STATE_DEPTH_WRITE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states).

For [D3D12_COMMAND_LIST_TYPE_COMPUTE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_command_list_type), the following rule applies:

* The resource must have the [D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_flags) flag, and **DiscardResource** must be called when the discarded subresource regions are in the [D3D12_RESOURCE_STATE_UNORDERED_ACCESS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) resource barrier state.

**DiscardResource** is not supported on command lists with either [D3D12_COMMAND_LIST_TYPE_BUNDLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_command_list_type) nor **D3D12_COMMAND_LIST_TYPE_COPY**.

## See also

[ID3D12GraphicsCommandList](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12graphicscommandlist)

[Using Resource Barriers to Synchronize Resource States in Direct3D 12](https://learn.microsoft.com/windows/desktop/direct3d12/using-resource-barriers-to-synchronize-resource-states-in-direct3d-12)