## Description

Specifies the level of sharing across nodes of an adapter, such as Tier 1 Emulated, Tier 1, or Tier 2.

## Constants

### `D3D12_CROSS_NODE_SHARING_TIER_NOT_SUPPORTED:0`

If an adapter has only 1 node, then cross-node sharing doesn't apply, so the **CrossNodeSharingTier** member of the [D3D12_FEATURE_DATA_D3D12_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) structure is set to D3D12_CROSS_NODE_SHARING_NOT_SUPPORTED.

### `D3D12_CROSS_NODE_SHARING_TIER_1_EMULATED:1`

Tier 1 Emulated. Devices that set the **CrossNodeSharingTier** member of the [D3D12_FEATURE_DATA_D3D12_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) structure to D3D12_CROSS_NODE_SHARING_TIER_1_EMULATED have Tier 1 support.
However, drivers stage these copy operations through a driver-internal system memory allocation. This will cause these copy operations to consume time on the destination GPU as well as the source.

### `D3D12_CROSS_NODE_SHARING_TIER_1:2`

Tier 1. Devices that set the **CrossNodeSharingTier** member of the [D3D12_FEATURE_DATA_D3D12_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) structure to D3D12_CROSS_NODE_SHARING_TIER_1 only support the following cross-node copy operations:

* [ID3D12CommandList::CopyBufferRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copybufferregion)
* [ID3D12CommandList::CopyTextureRegion](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytextureregion)
* [ID3D12CommandList::CopyResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copyresource)

Additionally, the cross-node resource must be the destination of the copy operation.

### `D3D12_CROSS_NODE_SHARING_TIER_2:3`

Tier 2. Devices that set the **CrossNodeSharingTier** member of the [D3D12_FEATURE_DATA_D3D12_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) structure to D3D12_CROSS_NODE_SHARING_TIER_2 support all operations across nodes, except for the following:

* Render target views.
* Depth stencil views.
* UAV atomic operations. Similar to CPU/GPU interop, shaders may perform UAV atomic operations; however, no atomicity across adapters is guaranteed.

Applications can retrieve the node where a resource/heap exists from the [D3D12_HEAP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_heap_desc) structure. These values are retrievable for opened resources. The runtime performs the appropriate re-mapping in case the 2 devices are using different UMD-specified node re-mappings.

### `D3D12_CROSS_NODE_SHARING_TIER_3:4`

Indicates support for [**D3D12_HEAP_FLAG_ALLOW_SHADER_ATOMICS**](https://learn.microsoft.com/windows/win32/api/d3d12/ne-d3d12-d3d12_heap_flags) on heaps that are visible to multiple nodes.

## Remarks

This enum is used by the **CrossNodeSharingTier** member of the [D3D12_FEATURE_DATA_D3D12_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)