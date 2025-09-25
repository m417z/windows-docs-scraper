# CLUSTER_GROUP_ENUM enumeration

## Description

Describes the type of cluster object being enumerated by the
[ClusterGroupEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupenum) and
[ClusterGroupOpenEnum](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-clustergroupopenenum) functions.

## Constants

### `CLUSTER_GROUP_ENUM_CONTAINS:0x00000001`

The resources in the group.

### `CLUSTER_GROUP_ENUM_NODES:0x00000002`

The nodes in the preferred owners list of the group.

### `CLUSTER_GROUP_ENUM_ALL`

All the resources in the group and all the nodes in the preferred owners list of the group.

## Remarks

The **CLUSTER_GROUP_ENUM_ALL** enumeration value is not a valid value for the
*lpdwType* parameter of the
[ClusterGroupEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupenum) function.

## See also

[ClusterGroupEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupenum)

[ClusterGroupOpenEnum](https://learn.microsoft.com/windows/win32/api/clusapi/nf-clusapi-clustergroupopenenum)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)