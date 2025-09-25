# ClusterResourceTypeOpenEnum function

## Description

Opens an enumerator for iterating through a [resource type's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types)
possible owner [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) or resources. The **PCLUSAPI_CLUSTER_RESOURCE_TYPE_OPEN_ENUM** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

[Cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) handle.

### `lpszResourceTypeName` [in]

A null-terminated Unicode string containing the name of the resource type.

### `dwType` [in]

Bitmask describing the type of [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) to be
enumerated. The following values of the [CLUSTER_RESOURCE_TYPE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_type_enum) enumeration are valid.

#### CLUSTER_RESOURCE_TYPE_ENUM_NODES (1)

The object is a node that can be a possible owner of the resource type.

#### CLUSTER_RESOURCE_TYPE_ENUM_RESOURCES (2)

The object is a resource that is an instance of the resource type.

#### CLUSTER_RESOURCE_TYPE_ENUM_ALL (3)

Enumerate both nodes and resources.

## Return value

If the operation succeeds, the function returns an enumeration handle which can be used in subsequent calls
to [ClusterResourceTypeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeenum).

If the operation fails, the function returns **NULL**. For more information about the
error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[CLUSTER_RESOURCE_TYPE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_type_enum)

[ClusterResourceTypeCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypecloseenum)

[ClusterResourceTypeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeenum)

[Resource Type Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-type-management-functions)