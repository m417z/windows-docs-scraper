# AddClusterGroupSetDependency function

## Description

Adds a dependency between two cluster groupsets. A groupset can only be dependent
on one other groupset.

## Parameters

### `hDependentGroupSet` [in]

The dependent collection

### `hProviderGroupSet` [in]

The collection *hDependentGroupSet* depends on.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).