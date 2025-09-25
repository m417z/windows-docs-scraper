# D3D12_RESOURCE_TRANSITION_BARRIER structure

## Description

Describes the transition of subresources between different usages.

## Members

### `pResource`

A pointer to the [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) object that represents the resource used in the transition.

### `Subresource`

The index of the subresource for the transition.
Use the **D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES** flag ( 0xffffffff ) to transition all subresources in a resource at the same time.

### `StateBefore`

The "before" usages of the subresources, as a bitwise-OR'd combination of [D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) enumeration constants.

### `StateAfter`

The "after" usages of the subresources, as a bitwise-OR'd combination of [D3D12_RESOURCE_STATES](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_resource_states) enumeration constants.

## Remarks

This struct is used by the **Transition** member of the
[D3D12_RESOURCE_BARRIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_barrier) struct.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Using Resource Barriers to Synchronize Resource States in Direct3D 12](https://learn.microsoft.com/windows/desktop/direct3d12/using-resource-barriers-to-synchronize-resource-states-in-direct3d-12)