# CLUSTER_ENUM enumeration

## Description

Describes the type of cluster objects being enumerated. This enumeration is used by the
[ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum) and
[ClusterEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterenum) functions.

## Constants

### `CLUSTER_ENUM_NODE:0x1`

The [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) in the cluster.

### `CLUSTER_ENUM_RESTYPE:0x2`

The [resource types](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) in the cluster.

### `CLUSTER_ENUM_RESOURCE:0x4`

The [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in the cluster.

### `CLUSTER_ENUM_GROUP:0x8`

The [groups](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) in the cluster.

### `CLUSTER_ENUM_NETWORK:0x10`

The [networks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) in the cluster.

### `CLUSTER_ENUM_NETINTERFACE:0x20`

The [network interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) in the cluster.

### `CLUSTER_ENUM_SHARED_VOLUME_GROUP:0x20000000`

The cluster shared volumes (CSV) in the cluster.

**Windows Server 2012, Windows Server 2008 R2 and Windows Server 2008:** This value is not supported before
Windows Server 2012 R2.

### `CLUSTER_ENUM_SHARED_VOLUME_RESOURCE:0x40000000`

The cluster shared volumes in the cluster.

**Windows Server 2008:** This value is not supported before
Windows Server 2008 R2.

### `CLUSTER_ENUM_INTERNAL_NETWORK:0x80000000`

The networks used by the cluster for internal communication.

### `CLUSTER_ENUM_ALL`

All the cluster objects.

## See also

[ClusterEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterenum)

[ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)