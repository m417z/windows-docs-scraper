# D3D12_RESOURCE_BARRIER_TYPE enumeration

## Description

Specifies a type of resource barrier (transition in resource use) description.

## Constants

### `D3D12_RESOURCE_BARRIER_TYPE_TRANSITION:0`

A transition barrier that indicates a transition of a set of subresources between different usages. The caller must specify the before and after usages of the subresources.

### `D3D12_RESOURCE_BARRIER_TYPE_ALIASING`

An aliasing barrier that indicates a transition between usages of 2 different resources that have mappings into the same tile pool. The caller can specify both the before and the after resource. Note that one or both resources can be **NULL**, which indicates that any tiled resource could cause aliasing.

### `D3D12_RESOURCE_BARRIER_TYPE_UAV`

An unordered access view (UAV) barrier that indicates all UAV accesses (reads or writes) to a particular resource must complete before any future UAV accesses (read or write) can begin.

## Remarks

This enum is used in the **D3D12_RESOURCE_BARRIER_TYPE** structure. Use these values with the [ID3D12GraphicsCommandList::ResourceBarrier](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-resourcebarrier) method.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)