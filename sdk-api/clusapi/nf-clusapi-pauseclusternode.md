# PauseClusterNode function

## Description

Requests that a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) temporarily suspend its [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly) activity. The **PCLUSAPI_PAUSE_CLUSTER_NODE** type defines a pointer to this function.

## Parameters

### `hNode` [in]

Handle to the node to suspend activity.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS**.

If the operation fails,
the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

When a node temporarily suspends its cluster activity, [groups](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/groups) cannot be moved to the node. Furthermore, groups that would normally fail over to the node cannot do so when it is in the paused state.

Groups that are owned by a paused node remain owned by the node. A paused node's groups and resources can be taken offline, but they cannot be brought online. Because the paused state is persistent, a paused node that is rebooted continues to be paused when it comes back up.

A paused node is said to be in the **ClusterNodePaused** state (see [GetClusterNodeState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternodestate)). To resume a node's cluster activity, use the [ResumeClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-resumeclusternode) function.

## See also

[GetClusterNodeState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getclusternodestate)

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)

[ResumeClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-resumeclusternode)