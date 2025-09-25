# CLUSTER_NETINTERFACE_STATE enumeration

## Description

Enumerates the possible values of the state of a
[network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces).

## Constants

### `ClusterNetInterfaceStateUnknown:-1`

The operation was not successful. For more information about the error, call the function
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### `ClusterNetInterfaceUnavailable`

The node that owns the network interface is down.

### `ClusterNetInterfaceFailed`

The network interface cannot communicate with any other network interface.

### `ClusterNetInterfaceUnreachable`

The network interface cannot communicate with at least one other network interface whose state is not
**ClusterNetInterfaceFailed** or
**ClusterNetInterfaceUnavailable**.

### `ClusterNetInterfaceUp`

The network interface can communicate with all other network interfaces whose state is not
**ClusterNetInterfaceFailed** or
**ClusterNetInterfaceUnavailable**.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[GetClusterNetInterfaceState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternetinterfacestate)

[State Property of the ClusNetInterface Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusnetinterface-state)