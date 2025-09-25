## Description

Describes a buffer memory access barrier. Used by buffer barriers to indicate when resource memory must be made visible for a specific access type.

## Members

### `SyncBefore`

Synchronization scope of all preceding GPU work that must be completed before executing the barrier.

### `SyncAfter`

Synchronization scope of all subsequent GPU work that must wait until the barrier execution is finished.

### `AccessBefore`

Access bits corresponding with resource usage since the preceding barrier, or the start of **ExecuteCommandLists** scope.

### `AccessAfter`

Access bits corresponding with resource usage after the barrier completes.

### `pResource`

Pointer to the buffer resource being using the barrier.

### `Offset`

Must be 0.

### `Size`

Must be either **UINT64_MAX** or the size of the buffer in bytes.

## Remarks

## See also