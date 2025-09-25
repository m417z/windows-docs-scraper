# D3D12DDI_CROSS_NODE_SHARING_TIER enumeration

## Description

A **D3D12DDI_CROSS_NODE_SHARING_TIER** value specifies the level of sharing across nodes of a display adapter.

## Constants

### `D3D12DDI_CROSS_NODE_SHARING_TIER_NOT_SUPPORTED:0`

Cross-node sharing does not apply.

### `D3D12DDI_CROSS_NODE_SHARING_TIER_1_EMULATED:1`

Emulated. Drivers stage these copy operations through a driver-internal system memory allocation. This will cause these copy operations to consume time on the destination GPU as well as the source.

### `D3D12DDI_CROSS_NODE_SHARING_TIER_1:2`

When set to Tier 1, drivers only support copy buffer region, copy texture region, and copy resource. The cross-node resource must be the destination of the copy region.

### `D3D12DDI_CROSS_NODE_SHARING_TIER_2:3`

All operations across nodes are supported except render target views, depth stencil views, and UAV atomic operations.

### `D3D12DDI_CROSS_NODE_SHARING_TIER_0041_3:4`

Supports cross-node sharing capabilities beyond Tier 2.

## Remarks

The latest cap data structures must be filled in by the driver when the corresponding DDI version is used. The driver may also detect which version of each cap-check occurs by the DataSize value passed along with each cap-query.
Tiled resources tier 4 cannot be supported directly by setting tiled resources tier 4. Instead, set support for the Deterministic64KBUndefinedSwizzle cap.

## See also

[**D3D12DDI_D3D12_OPTIONS_DATA_0089**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddi_d3d12_options_data_0089)