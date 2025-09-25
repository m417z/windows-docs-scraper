# CLUSTER_RESOURCE_STATE enumeration

## Description

Describes the operational condition of a resource. These values are used by the
[GetClusterResourceState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterresourcestate) function, the
**State** property of the
[MSCluster_Resource](https://learn.microsoft.com/previous-versions/windows/desktop/cluswmi/mscluster-resource) class, and the
[State](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusresource-state) property of the
[ClusResource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusresource-object) object.

## Constants

### `ClusterResourceStateUnknown:-1`

The operation was not successful. For more information about the error, call the function
[GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

### `ClusterResourceInherited`

The resource has been inherited.

### `ClusterResourceInitializing`

The resource is performing initialization.

### `ClusterResourceOnline`

The resource is operational and functioning normally.

### `ClusterResourceOffline`

The resource is not operational.

### `ClusterResourceFailed`

The resource has [failed](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/f-gly).

### `ClusterResourcePending:128`

The resource is in the process of coming online or going
[offline](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/o-gly).

### `ClusterResourceOnlinePending`

The resource is in the process of coming online.

### `ClusterResourceOfflinePending`

The resource is in the process of going offline.

## See also

[CLUS_MAINTENANCE_MODE_INFOEX](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-clus_maintenance_mode_infoex)

[CLUS_PROVIDER_STATE_CHANGE_INFO](https://learn.microsoft.com/windows/desktop/api/clusapi/ns-clusapi-clus_provider_state_change_info)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[GetClusterResourceState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterresourcestate)

[MSCluster_Resource](https://learn.microsoft.com/previous-versions/windows/desktop/cluswmi/mscluster-resource)

[State Property of the ClusResource Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusresource-state)