# GetClusterResourceKey function

## Description

Opens the root of the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) subtree for a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources).

## Parameters

### `hResource` [in]

Handle to a resource.

### `samDesired` [in]

Access mask that describes the security access needed for the opened key.

## Return value

If the operation succeeds, the function returns a registry key handle for the resource.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetClusterResourceKey** function returns a handle to a cluster database key representing the subtree root for the resource identified by *hResource*. Callers should call [ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey) to close the key handle retrieved by **GetClusterResourceKey** when they are done with it.

## See also

[ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)