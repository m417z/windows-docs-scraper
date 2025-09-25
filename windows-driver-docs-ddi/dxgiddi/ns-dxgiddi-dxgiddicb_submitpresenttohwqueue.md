# DXGIDDICB_SUBMITPRESENTTOHWQUEUE structure

## Description

Arguments used by the [PFNDDXGIDDI_SUBMITPRESENTTOHWQUEUECB](https://learn.microsoft.com/windows-hardware/drivers/ddi/dxgiddi/nc-dxgiddi-pfnddxgiddi_submitpresenttohwqueuecb) callback function.

## Members

### `pDXGIContext`

Pointer to a DXGI context.

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