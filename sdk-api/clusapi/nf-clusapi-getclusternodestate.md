# GetClusterNodeState function

## Description

Returns the
current state of a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes). The **PCLUSAPI_GET_CLUSTER_NODE_STATE** type defines a pointer to this function.

## Parameters

### `hNode` [in]

Handle to the node for which state information should be returned.

## Return value

**GetClusterNodeState** returns the current state
of the node, which is represented by one of the following values.

The returned values are from the
[CLUSTER_NODE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_node_state) enumeration.

| Return code/value | Description |
| --- | --- |
| **ClusterNodeUp**<br><br>0 | The node is physically plugged in, turned on, booted, and capable of executing programs. |
| **ClusterNodeDown**<br><br>1 | The node is turned off or not operational. |
| **ClusterNodeJoining**<br><br>3 | The node is in the process of joining a [cluster](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/c-gly). |
| **ClusterNodePaused**<br><br>2 | The node is running but not participating in cluster operations. |
| **ClusterNodeStateUnknown**<br><br>-1 | The operation was not successful. For more information about the error, call the function [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror). |

## Remarks

The **ClusterNodeDown** state only indicates that a node is inactive; it does not
specify the reason for the inactivity. A node can be in the **ClusterNodeDown** state for
the following reasons:

* The node is not running.
* The [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) on the node is not
  running.
* The node cannot communicate with the node controlling the
  [quorum resource](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/quorum-resource).
* The node is inactive for any other reason.

When a node is operating as an active member of a cluster but cannot host any resources or groups, it is in
the **ClusterNodePaused** state (see the
[PauseClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-pauseclusternode) function). Nodes that are undergoing
maintenance are typically placed in this state.

## See also

[CLUSTER_NODE_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-cluster_node_state)

[OpenClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-openclusternode)

[PauseClusterNode](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-pauseclusternode)