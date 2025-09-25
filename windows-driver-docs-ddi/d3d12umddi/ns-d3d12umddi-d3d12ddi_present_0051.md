# D3D12DDI_PRESENT_0051 structure

## Description

Arguments that describe allocations that content is copied to and from. Used by the [PFND3D12DDI_PRESENT_0051](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_present_0051) callback function.

## Members

### `BroadcastSrcAllocation`

Allocations which content will be presented.

### `BroadcastDstAllocation`

If non-zero, represents the destination allocations of the present.

### `AddedGpuWork`

Specifies whether there is added GPU work.

### `BackBufferMultiplicity`

The number of physical back buffer per logical back buffer.

### `SyncIntervalOverrideValid`

Override app sync interval is valid.

### `SyncIntervalOverride`

Override app sync interval.

## Remarks

## See also