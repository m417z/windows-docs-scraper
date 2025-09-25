# CLUSTER_RESOURCE_ENUM enumeration

## Description

Describes the type of cluster object being enumerated by the
[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum) or
[ClusterResourceOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenum)
functions.

## Constants

### `CLUSTER_RESOURCE_ENUM_DEPENDS:0x00000001`

A resource that the resource identified by the
[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum) or
[ClusterResourceOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenum) functions directly
depends on.

### `CLUSTER_RESOURCE_ENUM_PROVIDES:0x00000002`

A resource that directly depends on the resource identified by the
[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum) or
[ClusterResourceOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenum) functions.

### `CLUSTER_RESOURCE_ENUM_NODES:0x00000004`

A node that can host the resource identified by the
[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum) or
[ClusterResourceOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenum) functions.

### `CLUSTER_RESOURCE_ENUM_ALL`

All nodes and resources identified by the
[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum) or
[ClusterResourceOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenum) functions.

## See also

[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum)

[ClusterResourceOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenum)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)