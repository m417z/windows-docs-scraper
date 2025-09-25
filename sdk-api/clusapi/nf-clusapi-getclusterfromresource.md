# GetClusterFromResource function

## Description

Returns a handle to the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) associated with a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources). The **PCLUSAPI_GET_CLUSTER_FROM_RESOURCE** type defines a pointer to this function.

## Parameters

### `hResource` [in]

Handle to the resource.

## Return value

If the operation succeeds, the function returns a handle to the cluster that owns the resource.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For *hResource* to be a valid handle, there must necessarily be an open cluster handle (see [OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)). **GetClusterFromResource** returns another instance of the handle from which *hResource* was obtained.

Be sure to call [CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster) on the handle returned from **GetClusterFromResource** before the handle goes out of scope. Closing this handle does not invalidate *hResource* or the cluster handle from which *hResource* was obtained.

## See also

[CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster)

[CloseClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusterresource)

[GetClusterFromGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromgroup)

[GetClusterFromNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnetinterface)

[GetClusterFromNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnetwork)

[GetClusterFromNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnode)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusterresource)