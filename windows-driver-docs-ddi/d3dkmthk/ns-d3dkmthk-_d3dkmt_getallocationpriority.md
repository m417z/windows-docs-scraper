# _D3DKMT_GETALLOCATIONPRIORITY structure

## Description

Used to get allocation priorities.

## Members

### `hDevice` [in]

A handle to the device.

### `hResource` [in]

A handle for this resource in this process.

### `phAllocationList` [in]

Pointer to an array allocation to get priorities of.

### `AllocationCount` [in]

Number of allocations in *phAllocationList*.

### `pPriorities` [out]

Priority for each of the allocation in the array.

## Remarks

## See also