# GetClusterResourceState function

## Description

Returns
the current state of a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The **PCLUSAPI_GET_CLUSTER_RESOURCE_STATE** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle specifying the resource for which state information should be returned.

### `lpszNodeName` [out, optional]

Pointer to a buffer that receives the name of the specified resource's current owner node as a
**NULL**-terminated Unicode string. Pass **NULL** if the node name
is not required.

### `lpcchNodeName` [in, out, optional]

Pointer to the size of the *lpszNodeName* buffer as a count of characters. This
pointer cannot be **NULL** unless *lpszNodeName* is also
**NULL**. On input, specifies the maximum number of characters the buffer can hold,
including the terminating **NULL**. On output, specifies the number of characters in the
resulting name, excluding the terminating **NULL**.

### `lpszGroupName` [out, optional]

Pointer to a buffer that receives the name of the [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) that
contains the specified resource. The name is returned as a **NULL**-terminated Unicode
string. Pass **NULL** if the group name is not required.

### `lpcchGroupName` [in, out, optional]

Pointer to the size of the *lpszGroupName* buffer as a count of characters. This
pointer cannot be **NULL** unless *lpszNodeName* is also
**NULL**. On input, specifies the maximum number of characters the buffer can hold,
including the terminating **NULL**. On output, specifies the number of characters in the
resulting name, excluding the terminating **NULL**.

## Return value

**GetClusterResourceState** returns the
current state of the resource enumerated from the
[CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state) enumeration, which can be
represented by one of the following values.

| Return code/value | Description |
| --- | --- |
| **ClusterResourceInitializing**<br><br>1 | The resource is performing initialization. |
| **ClusterResourceOnline**<br><br>2 | The resource is operational and functioning normally. |
| **ClusterResourceOffline**<br><br>3 | The resource is not operational. This value will be returned if the resource reported a state of **ClusterResourceOffline** (3) or **ClusterResourceCannotComeOnlineOnThisNode** (127). |
| **ClusterResourceFailed**<br><br>4 | The resource has failed. This value will be returned if the resource reported a state of **ClusterResourceFailed** (4) or **ClusterResourceCannotComeOnlineOnAnyNode** (126). |
| **ClusterResourcePending**<br><br>128 | The resource is in the process of coming online or going offline. |
| **ClusterResourceOnlinePending**<br><br>129 | The resource is in the process of coming online. |
| **ClusterResourceOfflinePending**<br><br>130 | The resource is in the process of going offline. |
| **ClusterResourceStateUnknown**<br><br>-1 | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

Do not call **GetClusterResourceState** from
any resource DLL entry point function.
**GetClusterResourceState** can safely be called
from a worker thread. For more information, see
[Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

#### Examples

See [Getting Object States](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/getting-object-states) for an example.

## See also

[CLUSTER_RESOURCE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_resource_state)

[Offline](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-poffline_routine)

[OfflineClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-offlineclusterresource)

[Online](https://learn.microsoft.com/previous-versions/windows/desktop/api/resapi/nc-resapi-ponline_routine)

[OnlineClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-onlineclusterresource)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)