# _D3DDDICB_SUBMITPRESENTTOHWQUEUE structure

## Description

Arguments used by the [PFND3DDDI_SUBMITPRESENTTOHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dumddi/nc-d3dumddi-pfnd3dddi_submitpresenttohwqueuecb) callback function.

## Members

### `BroadcastSrcAllocations`

Allocations for which content will be presented.

### `BroadcastDstAllocations`

If non-zero, represents the destination allocations of the present.

### `hHwQueues`

An array of hardware queues being submitted to.

### `BroadcastHwQueueCount`

The number of broadcast hardware queues.

### `PrivateDriverDataSize`

The total size in bytes of the private data buffer.

### `pPrivateDriverData`

Pointer to the private data to pass to DdiPresent.

### `bOptimizeForComposition`

### `SyncIntervalOverrideValid`

### `SyncIntervalOverride`

## Remarks

## See also