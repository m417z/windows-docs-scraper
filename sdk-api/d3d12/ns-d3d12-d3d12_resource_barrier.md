# D3D12_RESOURCE_BARRIER structure

## Description

Describes a resource barrier (transition in resource use).

## Members

### `Type`

A [D3D12_RESOURCE_BARRIER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_barrier_type)-typed value that specifies the type of resource barrier.
This member determines which type to use in the union below.

### `Flags`

Specifies a [D3D12_RESOURCE_BARRIER_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_barrier_flags) enumeration constant such as for "begin only" or "end only".

### `Transition`

A [D3D12_RESOURCE_TRANSITION_BARRIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_transition_barrier) structure that describes the transition of subresources between different usages.
Members specify the before and after usages of the subresources.

### `Aliasing`

A
[D3D12_RESOURCE_ALIASING_BARRIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_aliasing_barrier) structure that describes the transition between usages of two different resources that have mappings into the same heap.

### `UAV`

A
[D3D12_RESOURCE_UAV_BARRIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_uav_barrier) structure that describes a resource in which all UAV accesses (reads or writes) must complete before any future UAV accesses (read or write) can begin.

## Remarks

This structure is used by the [ID3D12GraphicsCommandList::ResourceBarrier](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-resourcebarrier) method.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Using Resource Barriers to Synchronize Resource States in Direct3D 12](https://learn.microsoft.com/windows/desktop/direct3d12/using-resource-barriers-to-synchronize-resource-states-in-direct3d-12)