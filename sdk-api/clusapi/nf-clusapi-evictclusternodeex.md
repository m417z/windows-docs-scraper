# EvictClusterNodeEx function

## Description

Evicts a
[node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) from the
[cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) and initiates cleanup operations on the node. The **PCLUSAPI_EVICT_CLUSTER_NODE_EX** type defines a pointer to this function.

## Parameters

### `hNode` [in]

Handle to the node to remove from the cluster.

### `dwTimeOut` [in]

Specifies the number of milliseconds for the function to wait for cleanup operations to occur. The function
will return when the cleanup is complete or when the specified time elapses, whichever is sooner.

### `phrCleanupStatus` [out]

Pointer to an **HRESULT** that describes the results of the cleanup operation.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes), including the following value.

| Return code | Description |
| --- | --- |
| **ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP** | The node was evicted but the cleanup operation returned a value other than S_OK. |

## See also

[EvictClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-evictclusternode)

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)