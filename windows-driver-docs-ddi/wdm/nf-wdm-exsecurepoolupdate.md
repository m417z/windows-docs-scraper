## Description

The **ExSecurePoolUpdate** function updates the contents of the secure pool allocation.

## Parameters

### `SecurePoolHandle` [in]

Supplies the handle for the heap.

### `Tag` [in]

Supplies the tag for this allocation.

### `Allocation` [in]

Supplies a pointer to the allocation it wants to update.

### `Cookie` [in]

Supplies a cookie value used for identifying this allocation.

### `Offset` [in]

Supplies the offset into the buffer to be modified.

### `Size` [in]

Supplies size of the allocation. Offset + size must be within the original allocation.

### `Buffer` [in]

Supplies new contents of the secure pool block.

## Return value

Returns an NTSTATUS code.

## Remarks

## See also