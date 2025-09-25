# DestroyClusterGroup function

## Description

Deletes the specified [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) from a
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). Unlike
[DeleteClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-deleteclustergroup) the group can contain resources
and it can be online. The **PCLUSAPI_DESTROY_CLUSTER_GROUP** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

This parameter takes a handle to the cluster group to be destroyed.

## Return value

This function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). If the
operation completes successfully the function returns **ERROR_SUCCESS** (0). Any other
returned system error code would indicate that the
operation failed.

## Remarks

The **PCLUSAPI_DESTROY_CLUSTER_GROUP** type defines a pointer to this function.

**DestroyClusterGroup** does not close the group
handle specified by the *hGroup* parameter. To avoid memory leaks, be sure to close this handle with
the [CloseClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclustergroup) function.

Do not call **DestroyClusterGroup** from a resource
DLL. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[CloseClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclustergroup)

[DeleteClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-deleteclustergroup)

[Group Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-management-functions)