# GetClusterKey function

## Description

Opens the root of the
[cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) subtree for a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

## Parameters

### `hCluster` [in]

Handle to a cluster.

### `samDesired` [in]

Access mask that describes the security access needed for the new key. For more information and possible
values, see
[Registry Key Security and Access Rights](https://learn.microsoft.com/windows/desktop/SysInfo/registry-key-security-and-access-rights).

## Return value

If the operation succeeds, the function returns a database key handle for the cluster.

If the operation fails, the function returns **NULL**. For more information about the error, call
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetClusterKey** function returns a handle to a
cluster database key representing the cluster database subtree root for the cluster identified by
*hCluster*. Callers should call
[ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey) to close the key handle
retrieved by **GetClusterKey** when they are done with it.

## See also

[ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)