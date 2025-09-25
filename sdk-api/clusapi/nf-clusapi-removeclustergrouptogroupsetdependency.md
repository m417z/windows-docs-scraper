# RemoveClusterGroupToGroupSetDependency function

## Description

Removes a groupset from a group's dependency expression.

## Parameters

### `hGroup` [in]

The group from which to remove the dependency.

### `hDependsOn` [in]

The groupset to remove.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).