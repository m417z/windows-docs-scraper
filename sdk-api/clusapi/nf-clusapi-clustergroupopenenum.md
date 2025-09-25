# ClusterGroupOpenEnum function

## Description

 Opens an enumerator for iterating through a
[group's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources)
and/or the [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) that are included in its list of preferred
owners. The **PCLUSAPI_CLUSTER_GROUP_OPEN_ENUM** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

A handle to the [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) to be enumerated.

### `dwType` [in]

A bitmask that describes the [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) to be
enumerated. The following are valid values of the
[CLUSTER_GROUP_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_group_enum) enumeration.

#### CLUSTER_GROUP_ENUM_CONTAINS (1)

Enumerates the resources in the group.

#### CLUSTER_GROUP_ENUM_NODES (2)

Enumerates the nodes in the preferred owners list of the group.

#### CLUSTER_GROUP_ENUM_ALL (3)

Enumerates the resources in the group and the preferred owners of the group.

## Return value

If the operation succeeds,
**ClusterGroupOpenEnum** returns a handle to an
enumerator that can be passed to the
[ClusterGroupEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupenum) function.

If the operation fails, the function returns **NULL**. For more information about the
error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Do not call **ClusterGroupOpenEnum** from any
resource DLL entry point function.
**ClusterGroupOpenEnum** can safely be called from a
worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[ClusterGroupCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupcloseenum)

[ClusterGroupEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clustergroupenum)

[Group Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-management-functions)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)