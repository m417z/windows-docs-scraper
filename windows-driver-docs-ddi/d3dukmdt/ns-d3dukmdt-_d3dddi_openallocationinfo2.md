# _D3DDDI_OPENALLOCATIONINFO2 structure

## Description

The D3DDDI_OPENALLOCATIONINFO2 structure describes an allocation to be opened.

## Members

### `hAllocation` [in]

Handle for this allocation in this process.

### `pPrivateDriverData` [in]

Pointer to driver private buffer for this allocation.

### `PrivateDriverDataSize` [in]

Size in bytes of driver private buffer for this allocation.

### `GpuVirtualAddress` [out]

The GPU virtual address of the allocation opened.

### `Reserved`

Reserved.

## Remarks

## See also