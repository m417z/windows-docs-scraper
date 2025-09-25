# ClusterOpenEnum function

## Description

Opens an enumerator for iterating through
[cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) in a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The
**PCLUSAPI_CLUSTER_OPEN_ENUM** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

A handle to a cluster.

### `dwType` [in]

A bitmask that describes the type of objects to be enumerated. One or more of the following values of the
[CLUSTER_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_enum) enumeration are valid.

#### CLUSTER_ENUM_NODE (1 (0x1))

Enumerates the [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) in the cluster.

#### CLUSTER_ENUM_RESTYPE (2 (0x2))

Enumerates the [resource types](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) in the cluster.

#### CLUSTER_ENUM_RESOURCE (4 (0x4))

Enumerates the [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in the cluster.

#### CLUSTER_ENUM_GROUP (8 (0x8))

Enumerates the [groups](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) in the cluster.

#### CLUSTER_ENUM_NETWORK (16 (0x10))

Enumerates the [networks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) in the cluster.

#### CLUSTER_ENUM_NETINTERFACE (32 (0x20))

Enumerates the [network interfaces](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces) in the
cluster.

#### CLUSTER_ENUM_SHARED_VOLUME_RESOURCE (1073741824 (0x40000000))

Enumerates the cluster shared volumes that are used by the cluster.

**Note** Unlike most other enumeration bitmasks, this value must be used alone. Do not use the
**OR** operator to combine it with other bitmasks.

**Windows Server 2008:** The **CLUSTER_ENUM_SHARED_VOLUME_RESOURCE** value is not supported before
Windows Server 2008 R2.

#### CLUSTER_ENUM_INTERNAL_NETWORK (2147483648 (0x80000000))

Enumerates the networks that are used by the cluster for internal communication. The networks are enumerated in
order of highest-to-lowest priority as established by
[SetClusterNetworkPriorityOrder](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusternetworkpriorityorder).

**Note** Unlike most other enumeration bitmasks, this value must be used alone. Do not use the
**OR** operator to combine it with other bitmasks.

#### CLUSTER_ENUM_ALL ((CLUSTER_ENUM_NODE | CLUSTER_ENUM_RESTYPE | CLUSTER_ENUM_RESOURCE | CLUSTER_ENUM_GROUP | CLUSTER_ENUM_NETWORK | CLUSTER_ENUM_NETINTERFACE))

Enumerates all cluster objects.

## Return value

If the operation succeeds, **ClusterOpenEnum**
returns a handle to a cluster enumerator.

If the operation fails, the function returns **NULL**. For more information about the
error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Applications call the **ClusterOpenEnum** function to
create a particular type of enumerator.
**ClusterOpenEnum** can create enumerators for iterating
through groups, nodes, resource types, resources, or all of these. For example, an application can call
**ClusterOpenEnum** to get an enumeration of all of the
nodes and groups in a cluster by specifying
`CLUSTER_ENUM_GROUP | CLUSTER_ENUM_NODE` in the
*dwType* parameter.
**ClusterOpenEnum** returns a handle that can be passed
to [ClusterEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterenum) to access each of the cluster groups or
nodes and to [ClusterCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustercloseenum) to release the
enumerator.

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[Cluster Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-management-functions)

[ClusterCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustercloseenum)

[ClusterEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterenum)

[SetClusterNetworkPriorityOrder](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-setclusternetworkpriorityorder)