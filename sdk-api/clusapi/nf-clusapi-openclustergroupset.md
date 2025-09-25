# OpenClusterGroupSet function

## Description

Opens a handle to the specified groupset.

## Parameters

### `hCluster` [in]

A handle to the cluster containing the collection.

### `lpszGroupSetName` [in]

The name of the collection to be opened

## Return value

If the operation succeeds,
the function returns a groupset handle.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).