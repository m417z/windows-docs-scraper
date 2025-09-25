# ResUtilGetCoreClusterResourcesEx function

## Description

Returns handles to the
[core](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/core-resources), [Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name),
[IP Address](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/ip-address), and
[quorum](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource) resources. The **PRESUTIL_GET_CORE_CLUSTER_RESOURCES_EX** type defines a pointer to this function.

## Parameters

### `hClusterIn` [in]

The cluster handle (see [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)).

### `phClusterNameResourceOut` [out]

A pointer to a resource handle to the core
[Network Name](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/network-name) resource for the
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly), which stores the cluster name.

### `phClusterQuorumResourceOut` [out]

Not used.

### `dwDesiredAccess` [in]

The requested access privileges. This might be any combination of **GENERIC_READ** (0x80000000), **GENERIC_ALL** (0x10000000), or **MAXIMUM_ALLOWED** (0x02000000). If this value is zero (0), an undefined error might be returned. Using **GENERIC_ALL** is the same as calling [ResUtilGetCoreClusterResources](https://learn.microsoft.com/windows/desktop/api/resapi/nf-resapi-resutilgetcoreclusterresources).

#### - phClusterQuorumResource [out]

A pointer to a resource handle to the cluster's
[quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource).

## Return value

If the operations succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[Resource Utility Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-utility-functions)