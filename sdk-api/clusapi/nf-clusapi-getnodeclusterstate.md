# GetNodeClusterState function

## Description

Determines whether the [Cluster service](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-service) is installed and
running on a [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes). The **PCLUSAPI_GET_NODE_CLUSTER_STATE** type defines a pointer to this function.

## Parameters

### `lpszNodeName` [in, optional]

Pointer to a null-terminated Unicode string containing the name of the node to query. If
*lpszNodeName* is **NULL**, the local node is queried.

### `pdwClusterState` [out]

Pointer to a value describing the state of the Cluster service on the node. A node will be described by one
of the following [NODE_CLUSTER_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-node_cluster_state) enumeration
values.

#### ClusterStateNotInstalled (0)

The Cluster service is not installed on the node.

#### ClusterStateNotConfigured (1)

The Cluster service is installed on the node but has not yet been configured.

#### ClusterStateNotRunning (3)

The Cluster service is installed and configured on the node but is not currently running.

#### ClusterStateRunning (19 (0x13))

The Cluster service is installed, configured, and running on the node.

## Return value

If the operation succeeds, the function returns **ERROR_SUCCESS** (0). If the operation
fails, the function returns a [system error code](https://learn.microsoft.com/windows/desktop/Debug/system-error-codes).

## Remarks

**Note** The **GetNodeClusterState** function does not
support a 64-bit Windows-based [node](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/nodes) if the calling application is
32-bit Windows-based.

## See also

[NODE_CLUSTER_STATE](https://learn.microsoft.com/previous-versions/windows/desktop/api/clusapi/ne-clusapi-node_cluster_state)

[Node Management Functions](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/node-management-functions)