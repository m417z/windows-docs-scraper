# GetClusterFromGroup function

## Description

Returns a handle to the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) associated with a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups). The **PCLUSAPI_GET_CLUSTER_FROM_GROUP** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

Handle to the group.

## Return value

If the operation succeeds, the function returns a handle to the cluster that owns the group.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For *hGroup* to be a valid handle, there must necessarily be an open cluster handle (see [OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)). **GetClusterFromGroup** returns another instance of the handle from which *hGroup* was obtained.

Be sure to call [CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster) on the handle returned from **GetClusterFromGroup** before the handle goes out of scope. Closing this handle does not invalidate *hGroup* or the cluster handle from which *hGroup* was obtained.

## See also

[CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster)

[GetClusterFromNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnetinterface)

[GetClusterFromNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnetwork)

[GetClusterFromNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnode)

[GetClusterFromResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromresource)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)