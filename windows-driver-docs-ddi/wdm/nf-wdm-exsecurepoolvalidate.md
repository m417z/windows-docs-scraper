## Description

The **ExSecurePoolValidate** function validates that the secure pool provided is indeed the one previously created. It matches the secure header content with the values provided and checks if it owns the heap.

## Parameters

### `SecurePoolHandle` [in]

Supplies the handle for the heap.

### `Tag` [in]

Supplies the pool tag for this allocation.

### `Allocation` [in]

Supplies a pointer to the allocation it wants to validate.

### `Cookie` [in]

Supplies a cookie value used for identifying this allocation.

## Return value

A LOGICAL value indicating if validation succeeded.

## Remarks

## See also