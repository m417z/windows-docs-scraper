# AddClusterGroupToGroupSetDependency function

## Description

Adds a dependency between a cluster group and a cluster groupset.A group can only be dependent on one groupset.

## Parameters

### `hDependentGroup` [in]

The dependent group

### `hProviderGroupSet` [in]

The collection *hDependentGroup* depends on

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).