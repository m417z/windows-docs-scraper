# GetClusterNetInterfaceKey function

## Description

Opens the root of the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database) subtree for a [network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) object.

## Parameters

### `hNetInterface` [in]

Handle to a network interface.

### `samDesired` [in]

Access mask that describes the security access needed for the key.

## Return value

If the operation succeeds, the function returns a registry key handle for the network interface.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetClusterNetInterfaceKey** function returns a handle to a cluster database key representing the subtree root for the network interface identified by *hNetInterface*. Callers should call [ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey) to close the key handle retrieved by **GetClusterNetInterfaceKey** when they are done with it.

## See also

[ClusterRegCloseKey](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/nf-clusapi-clusterregclosekey)

[OpenClusterNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetinterface)