# MoveClusterGroup function

## Description

Moves a [group](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) and all of its [resources](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/resources) from one [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) to another. The **PCLUSAPI_MOVE_CLUSTER_GROUP** type defines a pointer to this function.

## Parameters

### `hGroup` [in]

Handle to the group to be moved.

### `hDestinationNode` [in, optional]

Handle to the node where the moved group should be brought back online or **NULL**.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes). The following is one of the possible error codes.

| Return code | Description |
| --- | --- |
| **ERROR_IO_PENDING** | The reassignment of ownership of the group is in progress. |

## Remarks

The return value from the **MoveClusterGroup** function does not imply anything about the state of the group or any of its resources. The return value only indicates whether the change of ownership was successful. After returning from **MoveClusterGroup**, the cluster always attempts to return the group to the state it was before the move.

If you want your application to ensure a particular state for a resource or a group after a move:

1. Check the state prior to the move. The cluster will attempt to restore that state after the move.
2. Poll for the state after the move and adjust as necessary. Or create a notification port (see [Receiving Cluster Events](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/receiving-cluster-events)) and wait for a **CLUSTER_CHANGE_GROUP_STATE** event.

When *hDestinationNode* is set to **NULL**, **MoveClusterGroup** attempts to move the group to the best possible node. If there is no node available that can accept the group, the function fails. **MoveClusterGroup** also fails if **MoveClusterGroup** determines that the group cannot be brought online on the node identified by the *hDestinationNode* parameter.

Do not call **MoveClusterGroup** from a resource DLL. For more information, see [Function Calls to Avoid in Resource DLLs](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/function-calls-to-avoid-in-resource-dlls).

Do not pass LPC and RPC handles to the same function call. Otherwise, the call will raise an RPC exception and can have additional destructive effects. For information on how LPC and RPC handles are created, see [Using Object Handles](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/using-object-handles) and [OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster).

## See also

[OpenCluster](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-opencluster)

[OpenClusterGroup](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclustergroup)

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)