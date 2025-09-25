# PauseClusterNodeEx function

## Description

Requests that a
node temporarily suspends its cluster activity.

## Parameters

### `hNode` [in]

A handle to the node to suspend.

### `bDrainNode` [in]

**TRUE** to drain the node; otherwise **FALSE**.

### `dwPauseFlags` [in] [in]

One of the following flags:
- CLUSAPI_NODE_PAUSE_REMAIN_ON_PAUSED_NODE_ON_MOVE_ERROR 0x00000001
- CLUSAPI_NODE_AVOID_PLACEMENT 0x00000002
- CLUSAPI_NODE_PAUSE_RETRY_DRAIN_ON_FAILURE 0x00000004

### `hNodeDrainTarget` [in, optional] [in, optional]

The node drain topic.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## See also

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)