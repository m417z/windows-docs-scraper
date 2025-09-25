# ClusterResourceOpenEnum function

## Description

Opens an enumerator for iterating through a
[resource's](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources)
[dependencies](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-dependencies) and
[nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes). The **PCLUSAPI_CLUSTER_RESOURCE_OPEN_ENUM** type defines a pointer to this function.

## Parameters

### `hResource` [in]

A handle to a resource.

### `dwType` [in]

A bitmask that describes the type of [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects)
to be enumerated.

The following values of the
[CLUSTER_RESOURCE_ENUM](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_enum) enumeration are valid.

#### CLUSTER_RESOURCE_ENUM_DEPENDS (1)

The object is a resource that the resource identified by the *hResource* parameter
directly depends on.

#### CLUSTER_RESOURCE_ENUM_PROVIDES (2)

The object is a resource that depends on the resource identified by *hResource*.

#### CLUSTER_RESOURCE_ENUM_NODES (4)

The object is a node that can host the resource identified by *hResource*.

## Return value

If the operation succeeds, the function returns an enumeration handle.

If the operation fails, the function returns **NULL**. For more information about the
error, call the [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) function.

## Remarks

Do not call **ClusterResourceOpenEnum** from
any resource DLL entry point function.
**ClusterResourceOpenEnum** can safely be called
from a worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

#### Examples

See [Enumerating Objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/enumerating-objects).

## See also

[Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)

[ClusterResourceCloseEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcecloseenum)

[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum)