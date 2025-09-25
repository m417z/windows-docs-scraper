# GetClusterNetInterfaceState function

## Description

Returns the current state of a
[network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces). The **PCLUSAPI_GET_CLUSTER_NET_INTERFACE_STATE** type defines a pointer to this function.

## Parameters

### `hNetInterface` [in]

Handle to the network interface for which state information should be returned.

## Return value

**GetClusterNetInterfaceState** returns
the current state of the network interface, which is represented by one of the following values enumerated by
the [CLUSTER_NETINTERFACE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_netinterface_state)
enumeration.

| Return code/value | Description |
| --- | --- |
| **ClusterNetInterfaceFailed**<br><br>1 | The network interface cannot communicate with any other network interface. |
| **ClusterNetInterfaceUnreachable**<br><br>2 | The network interface cannot communicate with at least one other network interface whose state is not **ClusterNetInterfaceFailed** or **ClusterNetInterfaceUnavailable**. |
| **ClusterNetInterfaceUp**<br><br>3 | The network interface can communicate with all other network interfaces whose state is not **ClusterNetInterfaceFailed** or **ClusterNetInterfaceUnavailable**. |
| **ClusterNetInterfaceUnavailable**<br><br>0 | The node that owns the network interface is down. |
| **ClusterNetInterfaceStateUnknown**<br><br>-1 | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## See also

[CLUSTER_NETINTERFACE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_netinterface_state)

[OpenClusterNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetinterface)

[State Property of the ClusNetInterface Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusnetinterface-state)