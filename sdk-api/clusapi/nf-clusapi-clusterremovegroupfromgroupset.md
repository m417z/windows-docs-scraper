# ClusterRemoveGroupFromGroupSet function

## Description

Removes the specified group from the groupset to which it is currently a member.

## Parameters

### `hGroup` [in]

A handle to the group to remove.

## Return value

Returns **ERROR_SUCCESS** if successful, or if the group was not currently a member of a collection.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).