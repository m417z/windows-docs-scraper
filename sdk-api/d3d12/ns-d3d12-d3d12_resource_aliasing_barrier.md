# D3D12_RESOURCE_ALIASING_BARRIER structure

## Description

Describes the transition between usages of two different resources that have mappings into the same heap.

## Members

### `pResourceBefore`

A pointer to the [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) object that represents the before resource used in the transition.

### `pResourceAfter`

A pointer to the [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) object that represents the after resource used in the transition.

## Remarks

This structure is a member of the [D3D12_RESOURCE_BARRIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_barrier) structure.

Both the before and the after resources can be specified or one or both resources can be **NULL**, which indicates that any placed or reserved resource could cause aliasing.

Refer to the usage models described in [CreatePlacedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createplacedresource).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Using Resource Barriers to Synchronize Resource States in Direct3D 12](https://learn.microsoft.com/windows/desktop/direct3d12/using-resource-barriers-to-synchronize-resource-states-in-direct3d-12)