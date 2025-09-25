# D3D12DDIARG_EVICT structure

## Description

Arguments used in the [PFND3D12DDI_EVICT2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/nc-d3d12umddi-pfnd3d12ddi_evict2) callback function to instruct the OS to decrement the residency reference count.

## Members

### `NumObjects`

The number of objects to evict.

### `pObjects`

Pointer to an array of objects.

### `Flags`

Flags.

### `Flags.EvictOnlyIfNecessary`

### `Flags.Value`

## Remarks

## See also