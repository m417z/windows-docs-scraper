# AddClusterGroupDependency function

## Description

Adds a dependency between two cluster groups.

## Parameters

### `hDependentGroup` [in]

The dependent group

### `hProviderGroup` [in]

The group *hDependentGroup* depends on

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).