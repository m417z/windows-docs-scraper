# ClusterResourceCloseEnum function

## Description

Closes a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) enumeration handle. The **PCLUSAPI_CLUSTER_RESOURCE_CLOSE_ENUM** type defines a pointer to this function.

## Parameters

### `hResEnum` [in]

A resource enumeration handle to be closed.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.
If the operation fails,
the function returns a different [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)

[ClusterResourceEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceenum)

[ClusterResourceOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenum)