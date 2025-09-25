# D3D12DDIARG_MAKERESIDENT_0001 structure

## Description

Arguments used to instruct the OS to add a resource to the device residency list and increment the residency reference count on this allocation.

## Members

### `NumAdapters`

The number of adapters.

### `pRTPagingQueue`

Paging queue on the device that created the input allocations. This queue will be used for residency operations.

### `NumObjects`

The number of objects.

### `pObjects`

An array of adapters to make resident.

### `Flags`

Specifies memory residency behavior.

### `Flags.CantTrimFurther`

### `Flags.Value`

### `pPagingFenceValue`

Pointer to the paging queue fence value to wait on.

### `WaitMask`

The wait mask.

## Remarks

## See also