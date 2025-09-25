# ClusterAddGroupToGroupSet function

## Description

Adds the specified group to a groupset in the cluster. The group
must not currently be in a groupset

## Parameters

### `hGroupSet` [in]

The collection to which to add the group

### `hGroup` [in]

The group to add to the collection

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).