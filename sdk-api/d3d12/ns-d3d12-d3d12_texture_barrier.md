## Description

Describes a texture memory access barrier. Used by texture barriers to indicate when resource memory must be made visible for a specific access type. Layout transitions are needed only for textures.

## Members

### `SyncBefore`

Synchronization scope of all preceding GPU work that must be completed before executing the barrier.

### `SyncAfter`

Synchronization scope of all subsequent GPU work that must wait until the barrier execution is finished.

### `AccessBefore`

Access bits corresponding with resource usage since the preceding barrier or the start of **ExecuteCommandLists** scope.

### `AccessAfter`

Access bits corresponding with resource usage after the barrier completes.

### `LayoutBefore`

Layout of texture preceding the barrier execution.

### `LayoutAfter`

Layout of texture upon completion of barrier execution.

### `pResource`

Pointer to the buffer resource being using the barrier.

### `Subresources`

Range of texture subresources being barriered.

### `Flags`

Optional flags values.

## Remarks

## See also