# SetGroupDependencyExpression function

## Description

Sets the dependency expression for a cluster group.

## Parameters

### `hGroup` [in]

A handle to the group on which to set the dependency expression.

### `lpszDependencyExpression` [in]

The dependency expression to set on the group.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).