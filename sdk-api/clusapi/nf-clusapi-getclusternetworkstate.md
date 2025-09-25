# GetClusterNetworkState function

## Description

Returns
the current state of a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks). The **PCLUSAPI_GET_CLUSTER_NETWORK_STATE** type defines a pointer to this function.

## Parameters

### `hNetwork` [in]

Handle to the network for which state information should be returned.

## Return value

**GetClusterNetworkState** returns the current
state of the network, which is represented by one of the following values enumerated by the
[CLUSTER_NETWORK_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_network_state) enumeration.

| Return code/value | Description |
| --- | --- |
| **ClusterNetworkUnavailable**<br><br>0 | All of the network interfaces on the network are unavailable, which means that the nodes that own the network interfaces are down. |
| **ClusterNetworkDown**<br><br>1 | The network is not operational; none of the [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) on the network can communicate. |
| **ClusterNetworkPartitioned**<br><br>2 | The network is operational, but two or more nodes on the network cannot communicate. Typically a path-specific problem has occurred. |
| **ClusterNetworkUp**<br><br>3 | The network is operational; all of the nodes in the cluster can communicate. |
| **ClusterNetworkStateUnknown**<br><br>-1 | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## See also

[CLUSTER_NETWORK_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_network_state)

[OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork)