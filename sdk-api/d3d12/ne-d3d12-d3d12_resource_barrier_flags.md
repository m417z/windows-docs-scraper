# D3D12_RESOURCE_BARRIER_FLAGS enumeration

## Description

Flags for setting split resource barriers.

## Constants

### `D3D12_RESOURCE_BARRIER_FLAG_NONE:0`

No flags.

### `D3D12_RESOURCE_BARRIER_FLAG_BEGIN_ONLY:0x1`

This starts a barrier transition in a new state, putting a resource in a temporary no-access condition.

### `D3D12_RESOURCE_BARRIER_FLAG_END_ONLY:0x2`

This barrier completes a transition, setting a new state and restoring active access to a resource.

## Remarks

Split barriers allow a single transition to be split into begin and end halves (refer to [Multi-engine synchronization](https://learn.microsoft.com/windows/win32/direct3d12/user-mode-heap-synchronization)).

This enum is used by the *Flags* member of the
[D3D12_RESOURCE_BARRIER](https://learn.microsoft.com/windows/win32/api/d3d12/ns-d3d12-d3d12_resource_barrier) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/win32/direct3d12/direct3d-12-enumerations)

[ResourceBarrier](https://learn.microsoft.com/windows/win32/api/d3d12/nf-d3d12-id3d12graphicscommandlist-resourcebarrier)

[Using Resource Barriers to Synchronize Resource States in Direct3D 12](https://learn.microsoft.com/windows/win32/direct3d12/using-resource-barriers-to-synchronize-resource-states-in-direct3d-12)