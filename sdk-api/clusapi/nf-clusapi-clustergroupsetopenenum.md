# ClusterGroupSetOpenEnum function

## Description

Starts the enumeration of groupset for a cluster.

## Parameters

### `hCluster` [in]

A handle to the cluster containing the groupset.

## Return value

If successful, returns a handle suitable for use with [ClusterGroupSetEnum](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clustergroupsetenum)

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).