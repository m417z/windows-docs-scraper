# GetClusterFromNetwork function

## Description

Returns a handle to the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) associated with a [network](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks). The **PCLUSAPI_GET_CLUSTER_FROM_NETWORK** type defines a pointer to this function.

## Parameters

### `hNetwork` [in]

Handle to the network.

## Return value

If the operation succeeds, the function returns a handle to the cluster that owns the network.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For *hNetwork* to be a valid handle, there must necessarily be an open cluster handle (see [OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork)). **GetClusterFromNetwork** returns another instance of the handle from which *hNetwork* was obtained.

Be sure to call [CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster) on the handle returned from **GetClusterFromNetwork** before the handle goes out of scope. Closing this handle does not invalidate *hNetwork* or the cluster handle from which *hNetwork* was obtained.

## See also

[CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster)

[CloseClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternetwork)

[GetClusterFromGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromgroup)

[GetClusterFromNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnetinterface)

[GetClusterFromNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnode)

[GetClusterFromResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromresource)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork)