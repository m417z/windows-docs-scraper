# SetClusterNetworkPriorityOrder function

## Description

[This function is available for use in the operating systems specified in the Requirements
section. Support for this method was removed in Windows Server 2008 and this function does nothing and returns
**ERROR_CALL_NOT_IMPLEMENTED**.]

Sets the priority order for the set of [networks](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/networks) used for
internal communication between cluster [nodes](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes). The **PCLUSAPI_SET_CLUSTER_NETWORK_PRIORITY_ORDER** type defines a pointer to this function.

## Parameters

### `hCluster` [in]

Handle to the [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) to be affected.

### `NetworkCount` [in]

Number of items in the list specified by the *NetworkList* parameter.

### `NetworkList` [in]

Prioritized array of handles to network objects. The first handle in the array has the highest priority. The
list must contain only those networks that are used for internal communication between nodes in the cluster,
and there can be no duplicates.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS** (0).

If the operation fails, the function returns a
[system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error
codes.

| Return code/value | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER**<br><br>87 (0x57) | There was a duplicate network in *NetworkList*. |

## Remarks

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and
can have additional destructive effects. For information on how LPC and RPC handles are created, see
[Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and
[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[ClusterEnum](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-clusterenum)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterNetwork](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternetwork)