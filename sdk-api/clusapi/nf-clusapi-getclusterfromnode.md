# GetClusterFromNode function

## Description

Returns a handle to the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) associated with a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes). The **PCLUSAPI_GET_CLUSTER_FROM_NODE** type defines a pointer to this function.

## Parameters

### `hNode` [in]

Handle to the node.

## Return value

If the operation succeeds, the function returns a handle to the cluster that owns the node.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For *hNode* to be a valid handle, there must necessarily be an open cluster handle (see [OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)). **GetClusterFromNode** returns another instance of the handle from which *hNode* was obtained.

Be sure to call [CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster) on the handle returned from **GetClusterFromNode** before the handle goes out of scope. Closing this handle does not invalidate *hNode* or the cluster handle from which *hNode* was obtained.

## See also

[CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster)

[CloseClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternode)

[GetClusterFromGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromgroup)

[GetClusterFromNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnetinterface)

[GetClusterFromNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnetwork)

[GetClusterFromResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromresource)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)