# GetClusterFromNetInterface function

## Description

Returns a handle to the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) associated with a [network interface](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-interfaces). The **PCLUSAPI_GET_CLUSTER_FROM_NET_INTERFACE** type defines a pointer to this function.

## Parameters

### `hNetInterface` [in]

Handle to the network interface.

## Return value

If the operation succeeds, the function returns a handle to the cluster that owns the network interface.

If the operation fails,
the function returns **NULL**. For more information about the error, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

For *hNetInterface* to be a valid handle, there must necessarily be an open cluster handle (see [OpenClusterNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetinterface)). **GetClusterFromNetInterface** returns another instance of the handle from which *hNetInterface* was obtained.

Be sure to call [CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster) on the handle returned from **GetClusterFromNetInterface** before the handle goes out of scope. Closing this handle does not invalidate *hNetInterface* or the cluster handle from which *hNetInterface* was obtained.

## See also

[CloseCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closecluster)

[CloseClusterNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-closeclusternetinterface)

[GetClusterFromGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromgroup)

[GetClusterFromNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnetwork)

[GetClusterFromNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromnode)

[GetClusterFromResource](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusterfromresource)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterNetInterface](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetinterface)