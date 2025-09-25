# CLUSTER_NODE_ENUM enumeration

## Description

Describes the types of cluster objects that are enumerated by the
[ClusterNodeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeenum) and
[ClusterNodeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenum) functions.

## Constants

### `CLUSTER_NODE_ENUM_NETINTERFACES:0x1`

Network interfaces on the node.

### `CLUSTER_NODE_ENUM_GROUPS:0x2`

Cluster groups on the node.

**Windows Server 2008:** This value is not supported before
Windows Server 2008 R2.

### `CLUSTER_NODE_ENUM_PREFERRED_GROUPS:0x4`

Cluster groups that list this node as their preferred owner.

**Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is supported before
Windows Server 2012 R2.

### `CLUSTER_NODE_ENUM_ALL`

Network interfaces on the node, groups on the node, and groups that list the node as their preferred owner..

## See also

[ClusterNodeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeenum)

[ClusterNodeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusternodeopenenum)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)