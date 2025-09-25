# ResUtilGetCoreClusterResources function

## Description

Returns handles to the
[core](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/core-resources) [Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name),
[IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address) and
[quorum](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource) resources. The **PRESUTIL_GET_CORE_CLUSTER_RESOURCES** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Cluster handle (see [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)).

### `phClusterNameResource` [out]

Pointer to a resource handle to the core
[Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource for the
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly), which stores the cluster name.

### `phClusterIPAddressResource` [out]

Not used.

### `phClusterQuorumResource` [out]

Pointer to a resource handle to the cluster's
[quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource).

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)