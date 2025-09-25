# GetClusterGroupState function

## Description

Returns the
current state of a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups). The **PCLUSAPI_GET_CLUSTER_GROUP_STATE** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

Handle to the group for which state information should be returned.

### `lpszNodeName` [out, optional]

Pointer to a null-terminated Unicode string containing the name of the node that currently owns the group.

### `lpcchNodeName` [in, out, optional]

Pointer to the size of the *lpszNodeName* buffer as a count of characters. On input,
specify the maximum number of characters the buffer can hold, including the terminating
**NULL**. On output, specifies the number of characters in the resulting name, excluding
the terminating **NULL**.

## Return value

**GetClusterGroupState** returns the current
state of the group, which is represented by one of the following values.

| Return code/value | Description |
| --- | --- |
| **ClusterGroupStateUnknown**<br><br>-1 | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |
| **ClusterGroupOnline**<br><br>0 | All of the resources in the group are [online](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/o-gly). |
| **ClusterGroupOffline**<br><br>1 | All of the resources in the group are [offline](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/o-gly) or there are no resources in the group. |
| **ClusterGroupFailed**<br><br>2 | At least one [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) in the group has failed (set a state of **ClusterResourceFailed** from the [CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state) enumeration). |
| **ClusterGroupPartialOnline**<br><br>3 | At least one resource in the group is online. No resources are [pending](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/p-gly) or [failed](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/f-gly). |
| **ClusterGroupPending**<br><br>4 | At least one resource in the group is in a pending state. There are no failed resources. |

## Remarks

Note that *lpcchName* refers to a count of characters and not a count of bytes, and
that the returned size does not include the terminating **NULL** in the count. For more
information on sizing buffers, see
[Data Size Conventions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/data-size-conventions).

Do not call **GetClusterGroupState** from any
resource DLL entry point function.
**GetClusterGroupState** can safely be called from a
worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

## See also

[CLUSTER_GROUP_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_group_state)

[CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state)

[Group Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/group-management-functions)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)