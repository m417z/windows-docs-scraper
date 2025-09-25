# ClusterNetworkOpenEnum function

## Description

Opens an enumerator for iterating through [objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) on a
[network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks). The **PCLUSAPI_CLUSTER_NETWORK_OPEN_ENUM** type defines a pointer to this function.

## Parameters

### `hNetwork` [in]

A handle to a network.

### `dwType` [in]

A bitmask that describes the type of objects to be enumerated. One or more of the following values
[CLUSTER_NETWORK_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_network_enum) enumeration are valid.

#### CLUSTER_NETWORK_ENUM_NETINTERFACES (1)

Enumerates the network interface objects on the network.

## Return value

If the operation was successful,
**ClusterNetworkOpenEnum** returns a handle to a
network enumerator.

If the operation fails, the function returns **NULL**. For
more information about the error, call the function
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications call the **ClusterNetworkOpenEnum**
function to create a particular type of enumerator.
**ClusterNetworkOpenEnum** can create enumerators
for iterating through all of the objects on a network or only the network interface objects.
**ClusterNetworkOpenEnum** returns a handle that
can be passed to [ClusterNetworkEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkenum) to access each
of the objects to be enumerated and to
[ClusterNetworkCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkcloseenum) to release the
enumerator.

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[Cluster Network Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-management-functions)

[ClusterNetworkCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkcloseenum)

[ClusterNetworkEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternetworkenum)

[OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork)