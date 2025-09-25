# DeleteClusterGroup function

## Description

Removes an offline and empty
[group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) from a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). The **PCLUSAPI_DELETE_CLUSTER_GROUP** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

Handle to the group to be removed. You must close this handle separately.

## Return value

This function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). If the
operation completes successfully the function returns **ERROR_SUCCESS** (0). Any other
returned system error code would indicate that the
operation failed.

## Remarks

The **PCLUSAPI_DELETE_CLUSTER_GROUP** type defines a pointer to this function.

Because the **DeleteClusterGroup** function only
removes groups that are empty, a group must not have any
[resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) if it is to be successfully deleted. To delete a group
with resources, use the [DestroyClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-destroyclustergroup)
function.

**DeleteClusterGroup** does not close the group
handle specified by *hGroup*. To avoid memory leaks, be sure to close this handle with
[CloseClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclustergroup).

Do not call **DeleteClusterGroup** from a resource
DLL. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[CloseClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclustergroup)

[CreateClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-createclustergroup)

[DestroyClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-destroyclustergroup)

[Group Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-management-functions)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)