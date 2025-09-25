# D3D12_RESOURCE_UAV_BARRIER structure

## Description

Represents a resource in which all UAV accesses must complete before any future UAV accesses can begin.

## Members

### `pResource`

The resource used in the transition, as a pointer to [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource).

## Remarks

This struct represents a resource in which all unordered access view (UAV) accesses (reads or writes) must complete before any future UAV accesses (read or write) can begin.

This structure is a member of the [D3D12_RESOURCE_BARRIER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_resource_barrier) structure.

You don't need to insert a UAV barrier between 2 draw or dispatch calls that only read a UAV.
Additionally, you don't need to insert a UAV barrier between 2 draw or dispatch calls that write to the same UAV if you know that it's safe to execute the UAV accesses in any order.
The resource can be **NULL**, which indicates that any UAV access could require the barrier.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Using Resource Barriers to Synchronize Resource States in Direct3D 12](https://learn.microsoft.com/windows/desktop/direct3d12/using-resource-barriers-to-synchronize-resource-states-in-direct3d-12)