# GetClusterGroupKey function

## Description

Opens the root of the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) subtree for a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups).

## Parameters

### `hGroup` [in]

Handle to a group.

### `samDesired` [in]

Access mask that describes the security access needed for the key.

## Return value

If the operation succeeds, the function returns a database key handle for the group.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetClusterGroupKey** function returns a handle to a cluster database key representing the subtree root for the group identified by *hGroup*. Callers should call [ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey) to close the key handle retrieved by **GetClusterGroupKey** when they are done with it.

## See also

[ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)