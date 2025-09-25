# CLUSTER_NETWORK_STATE enumeration

## Description

Enumerates the possible values of the state of a
[network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks).

## Constants

### `ClusterNetworkStateUnknown:-1`

The operation was not successful. For more information about the error, call the function
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### `ClusterNetworkUnavailable`

All of the network interfaces on the network are unavailable, which means that the nodes that own the network
interfaces are down.

### `ClusterNetworkDown`

The network is not operational; none of the [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) on the network
can communicate.

### `ClusterNetworkPartitioned`

The network is operational, but two or more nodes on the network cannot communicate. Typically a
path-specific problem has occurred.

### `ClusterNetworkUp`

The network is operational; all of the nodes in the cluster can communicate.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[GetClusterNetworkState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternetworkstate)

[State Property of the ClusNetwork Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusnetwork-state)