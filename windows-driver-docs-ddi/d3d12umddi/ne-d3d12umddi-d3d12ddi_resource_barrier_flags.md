# D3D12DDI_RESOURCE_BARRIER_FLAGS enumeration

## Description

**D3D12DDI_RESOURCE_BARRIER_FLAGS** contains legacy resource barrier flags.

## Constants

### `D3D12DDI_RESOURCE_BARRIER_FLAG_NONE:0x0`

No flag value.

### `D3D12DDI_RESOURCE_BARRIER_FLAG_BEGIN_ONLY:0x1`

Indicates an acquire. This starts a barrier transition in a new state, putting a resource in a temporary no-access condition. This flag is relevant only for ranged barriers.

### `D3D12DDI_RESOURCE_BARRIER_FLAG_END_ONLY:0x2`

Indicates a release. This barrier completes a transition, setting a new state and restoring active access to a resource. This flag is relevant only for ranged barriers.

### `D3D12DDI_RESOURCE_BARRIER_FLAG_0022_ATOMIC_COPY:0x4`

Indicates that ranged barriers are associated with a parameter of an atomic copy operation.

### `D3D12DDI_RESOURCE_BARRIER_FLAG_0022_ALIASING:0x8`

Indicates that an aliasing barrier has been converted to a ranged barrier.

## Remarks

The absence of both **D3D12DDI_RESOURCE_BARRIER_FLAG_BEGIN_ONLY** and **D3D12DDI_RESOURCE_BARRIER_FLAG_END_ONLY** denotes both an acquire and release.

During an acquire, GPU caches may need to be explicitly invalidated. During a release, GPU caches may need to be explicitly flushed.

## See also

[**D3D12DDI_RANGED_BARRIER_FLAGS_0094**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_ranged_barrier_flags_0094)