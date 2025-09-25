# CreateClusterResource function

## Description

Creates a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The **PCLUSAPI_CREATE_CLUSTER_RESOURCE** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

Handle to the [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) that should receive the resource.

### `lpszResourceName` [in]

Pointer to a null-terminated Unicode string containing the name of the new resource. The specified name
must be unique within the cluster.

### `lpszResourceType` [in]

Pointer to the type of new resource. The specified type must be installed in the cluster.

### `dwFlags` [in]

Bitmask describing how the resource should be added to the cluster. The *dwFlags*
parameter can be set to one of the following values enumerated from the
[CLUSTER_RESOURCE_CREATE_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_create_flags)
enumeration.

#### CLUSTER_RESOURCE_DEFAULT_MONITOR (0)

The [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) determines the
[Resource Monitor](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-monitor) to which the new resource will be
assigned.

#### CLUSTER_RESOURCE_SEPARATE_MONITOR (1)

Causes the Cluster service to create a separate Resource Monitor dedicated exclusively to the new
resource.

## Return value

If the operation succeeds, the function returns a resource handle.

If the operation fails, the function returns **NULL**. For more information about the
error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Do not call **CreateClusterResource** from a
resource DLL. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[CLUSTER_RESOURCE_CREATE_FLAGS](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_create_flags)

[Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)

[DeleteClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-deleteclusterresource)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)