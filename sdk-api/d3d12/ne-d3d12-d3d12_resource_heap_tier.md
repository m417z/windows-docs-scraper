# D3D12_RESOURCE_HEAP_TIER enumeration

## Description

Specifies which resource heap tier the hardware and driver support.

## Constants

### `D3D12_RESOURCE_HEAP_TIER_1:1`

Indicates that heaps can only support resources from a single resource category.
For the list of resource categories, see Remarks.
In tier 1, these resource categories are mutually exclusive and cannot be used with the same heap.
The resource category must be declared when creating a heap, using the correct [D3D12_HEAP_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_heap_flags) enumeration constant.
Applications cannot create heaps with flags that allow all three categories.

### `D3D12_RESOURCE_HEAP_TIER_2:2`

Indicates that heaps can support resources from all three categories.
For the list of resource categories, see Remarks.
In tier 2, these resource categories can be mixed within the same heap.
Applications may create heaps with flags that allow all three categories; but are not required to do so.
Applications may be written to support tier 1 and seamlessly run on tier 2.

## Remarks

This enum is used by the **ResourceHeapTier** member of the [D3D12_FEATURE_DATA_D3D12_OPTIONS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_feature_data_d3d12_options) structure.

This enum specifies which resource heap tier the hardware and driver support.
Lower tiers require more heap attribution than greater tiers.

Resources can be categorized into the following types:

* Buffers
* Non-render target & non-depth stencil textures
* Render target or depth stencil textures

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)