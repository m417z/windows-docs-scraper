# EvictClusterNode function

## Description

Deletes a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) from the [cluster database](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-database). The **PCLUSAPI_EVICT_CLUSTER_NODE** type defines a pointer to this function.

## Parameters

### `hNode` [in]

Handle to the node to delete.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

To reinstate an evicted node, you must first remove the [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) from the node and then reinstall it. During installation, choose the **Join an Existing Cluster** option.

## See also

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)