# ClusterResourceTypeCloseEnum function

## Description

Closes a [resource type](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-types) enumeration handle. The **PCLUSAPI_CLUSTER_RESOURCE_TYPE_CLOSE_ENUM** type defines a pointer to this function.

## Parameters

### `hResTypeEnum` [in]

Enumeration handle to be closed.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[ClusterResourceTypeEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeenum)

[ClusterResourceTypeOpenEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourcetypeopenenum)