# ClusterResourceGetEnumCountEx function

## Description

Returns the number of [cluster objects](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-objects) that are associated with a [resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) enumeration handle.

## Parameters

### `hResourceEnumEx` [in]

The handle to a resource enumeration. This handle is obtained from
the [ClusterResourceOpenEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenumex) function. A valid handle is required. This parameter cannot be **NULL**.

## Return value

The number of objects that are associated with the enumeration handle.

## See also

[ClusterResourceOpenEnumEx](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterresourceopenenumex)

[Failover Cluster Resource Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resource-management-functions)