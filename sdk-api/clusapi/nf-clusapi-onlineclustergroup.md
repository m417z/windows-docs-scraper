# OnlineClusterGroup function

## Description

Brings a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) online. The **PCLUSAPI_ONLINE_CLUSTER_GROUP** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

Handle to the group to be brought online.

### `hDestinationNode` [in, optional]

Handle to the [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) where the group identified by *hGroup* should be brought online or **NULL**.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following are possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_HOST_NODE_NOT_AVAILABLE** | A suitable host node was not available. |
| **ERROR_IO_PENDING** | The operation is in progress. |

## Remarks

If the group cannot be brought online on the node identified by the *hDestinationNode* parameter, the **OnlineClusterGroup** function fails.

If the *hDestinationNode* parameter is set to **NULL**, **OnlineClusterGroup** brings the group online on the current node.

Do not call **OnlineClusterGroup** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and can have additional destructive effects. For information on how LPC and RPC handles are created, see [Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[OfflineClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-offlineclustergroup)

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)