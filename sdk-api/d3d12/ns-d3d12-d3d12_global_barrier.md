## Description

Describes a resource memory access barrier. Used by global, texture, and buffer barriers to indicate when resource memory must be made visible for a specific access type.

## Members

### `SyncBefore`

Synchronization scope of all preceding GPU work that must be completed before executing the barrier.

### `SyncAfter`

Synchronization scope of all subsequent GPU work that must wait until the barrier execution is finished.

### `AccessBefore`

Access bits corresponding with any relevant resource usage since the preceding barrier or the start of **ExecuteCommandLists** scope.

### `AccessAfter`

Access bits corresponding with any relevant resource usage after the barrier completes.

## Remarks

## See also