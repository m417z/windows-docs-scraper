# D3DKMT_MULTIPLANE_OVERLAY3 structure

## Description

Multiplane overlay structure.

## Members

### `LayerIndex`

The layer index.

### `InputFlags`

The input flags.

### `FlipInterval`

A UINT value that specifies whether the display miniport driver natively supports the scheduling of a flip command to take effect after two, three or four vertical syncs occur.

### `MaxImmediateFlipLine`

The maximum immediate flip line.

### `AllocationCount`

Number of allocations in *pAllocationList*.

### `pAllocationList`

Pointer to the first allocation list.

### `DriverPrivateDataSize`

The driver private data size.

### `pDriverPrivateData`

Pointer to driver private data.

### `pPlaneAttributes`

A structure that contains the plane attributes.

### `hFlipToFence`

Handle to the fence for a flip that is about to occur.

### `hFlipAwayFence`

Handle to the fence for a flip that has just completed.

### `FlipToFenceValue`

Fence value for the flip that is about to occur.

## `FlipAwayFenceValue`

Fence value for the flip that has just completed.

## See also

[**D3DKMT_PRESENT_MULTIPLANE_OVERLAY3**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_present_multiplane_overlay3)