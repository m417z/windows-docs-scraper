# CLUSTER_RESOURCE_CREATE_FLAGS enumeration

## Description

Determines which resource monitor a given resource will be assigned to.

## Constants

### `CLUSTER_RESOURCE_DEFAULT_MONITOR:0`

The [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) determines the
[Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor) to which the new resource will be
assigned.

### `CLUSTER_RESOURCE_SEPARATE_MONITOR:1`

Causes the Cluster service to create a separate Resource Monitor dedicated exclusively to the new
resource.

### `CLUSTER_RESOURCE_VALID_FLAGS`

Contains all valid flags for the
[CLUSTER_RESOURCE_CREATE_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_create_flags)
enumeration.

## See also

[CreateClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclusterresource)

[CreateItem Method of the ClusResDependencies Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusresdependencies-createitem)

[CreateItem Method of the ClusResDependents Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusresdependents-createitem)

[CreateItem Method of the ClusResTypeResources Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusrestyperesources-createitem)

[CreateItem Method of the ClusResources Object](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/clusresources-createitem)

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)