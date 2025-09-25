# ClusterNodeOpenEnum function

## Description

Opens an
enumerator for iterating through the [network interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces)
or [groups](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) installed on a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes). The **PCLUSAPI_CLUSTER_NODE_OPEN_ENUM** type defines a pointer to this function.

## Parameters

### `hNode` [in]

Handle to a node.

### `dwType` [in]

Bitmask describing the type of objects to be enumerated. The following values of the
[CLUSTER_NODE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_node_enum) enumeration are valid.

#### CLUSTER_NODE_ENUM_NETINTERFACES (0x00000001)

Enumerate the network interface objects on the node.

#### CLUSTER_NODE_ENUM_GROUPS (0x00000002)

Enumerate the cluster groups on the node.

#### CLUSTER_NODE_ENUM_ALL ((CLUSTER_NODE_ENUM_NETINTERFACES | CLUSTER_NODE_ENUM_GROUPS))

Enumerate the network interfaces objects and cluster groups on the node.

**Windows Server 2008:** The **CLUSTER_NODE_ENUM_GROUPS** value is not supported before
Windows Server 2008 R2.

## Return value

If the operation succeeds,
**ClusterNodeOpenEnum** returns a handle to a node
enumerator.

If the operation fails, the function returns **NULL**. For more information about the
error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

The **ClusterNodeOpenEnum** function returns a
handle that can be passed to [ClusterNodeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeenum) to
access each of the objects to be enumerated and to
[ClusterNodeCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodecloseenum) to release the
enumerator.

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[CLUSTER_NODE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_node_enum)

[ClusterNodeCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodecloseenum)

[ClusterNodeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeenum)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)