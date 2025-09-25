# GetClusterResourceTypeKey function

## Description

Opens the root of the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) subtree for a [resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types).

## Parameters

### `hCluster` [in]

Handle to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly).

### `lpszTypeName` [in]

Pointer to a NULL-terminated Unicode string specifying the name of a resource type (the registered type name, not the display name).

### `samDesired` [in]

Access mask that describes the security access needed for the opened key.

## Return value

If the operation succeeds, the function returns a registry key handle for the resource type.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetClusterResourceTypeKey** function returns a handle to a cluster database key representing the subtree root for the resource type pointed to by *lpszTypeName* in the cluster identified by *hCluster*. Callers should call [ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey) to close the key handle retrieved by **GetClusterResourceTypeKey** when they are done with it.

## See also

[ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)