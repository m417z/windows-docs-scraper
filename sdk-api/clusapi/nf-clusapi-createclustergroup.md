# CreateClusterGroup function

## Description

Adds a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) to a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and returns a handle to the newly added group. The **PCLUSAPI_CREATE_CLUSTER_GROUP** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to the target cluster.

### `lpszGroupName` [in]

Pointer to a null-terminated Unicode string containing the name of the group to be added to the cluster identified by *hCluster*. If there is not a group by this name, **CreateClusterGroup** creates it.

## Return value

If the operation succeeds,
the function returns a group handle.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

Do not call **CreateClusterGroup** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

The **CreateClusterGroup** function calls the [CreateClusterGroupEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclustergroupex) function with a **NULL** CLUSTER_CREATE_GROUP_INFO. The new group is created with a group type of ClusGroupTypeUnknown.

#### Examples

See [Creating Groups](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/creating-groups).

## See also

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)