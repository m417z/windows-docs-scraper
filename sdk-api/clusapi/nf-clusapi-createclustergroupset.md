# CreateClusterGroupSet function

## Description

Adds a groupset to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and returns a handle to the newly added groupset.

## Parameters

### `hCluster` [in]

A handle to the target cluster.

### `groupSetName` [in]

Pointer to a null-terminated Unicode string containing the name of the groupset to be added.

## Return value

If the operation succeeds,
returns a groupset handle.

If the operation fails,
returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).