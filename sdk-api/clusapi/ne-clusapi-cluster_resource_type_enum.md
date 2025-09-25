# CLUSTER_RESOURCE_TYPE_ENUM enumeration

## Description

Describes the type of cluster object being enumerated by the
[ClusterResourceTypeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeenum) and
[ClusterResourceTypeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeopenenum)
functions.

## Constants

### `CLUSTER_RESOURCE_TYPE_ENUM_NODES:0x00000001`

The object is a node that can be a possible owner of the resource type.

### `CLUSTER_RESOURCE_TYPE_ENUM_RESOURCES:0x00000002`

The object is a resource that is an instance of the resource type.

**Windows Server 2008:** This value is not supported before Windows Server 2008 R2. To emulate this on earlier platforms,
enumerate all resources in the cluster (see the
[ClusterOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusteropenenum) function) and filter the results
using the [ResUtilResourceTypesEqual](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilresourcetypesequal)
function. If the call is made on a system without ResUtils.dll, then use the steps mentioned in the Remarks
section of the **ResUtilResourceTypesEqual**
function.

### `CLUSTER_RESOURCE_TYPE_ENUM_ALL`

All cluster objects identified by the
[ClusterResourceTypeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeenum) and
[ClusterResourceTypeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeopenenum)
functions.

## See also

[ClusterResourceTypeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeenum)

[ClusterResourceTypeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeopenenum)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)