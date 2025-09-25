# GetClusterNetworkKey function

## Description

Opens the root of the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) subtree for a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks).

## Parameters

### `hNetwork` [in]

Handle to a network.

### `samDesired` [in]

Access mask that describes the security access needed for the new key.

## Return value

If the operation succeeds, the function returns a registry key handle for the network.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetClusterNetworkKey** function returns a handle to a cluster database key representing the subtree root for the network identified by *hNetwork*. Callers should call [ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey) to close the key handle retrieved by **GetClusterNetworkKey** when they are done with it.

## See also

[ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey)

[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror)

[OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork)