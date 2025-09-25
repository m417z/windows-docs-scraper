# NODE_CLUSTER_STATE enumeration

## Description

Indicates the state of the cluster. The
[GetNodeClusterState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getnodeclusterstate) function uses this
enumeration.

## Constants

### `ClusterStateNotInstalled:0`

The Cluster service is not installed on the node.

### `ClusterStateNotConfigured:0x1`

The Cluster service is installed on the node but has not yet been configured.

### `ClusterStateNotRunning`

The Cluster service is installed and configured on the node but is not currently running.

### `ClusterStateRunning`

The Cluster service is installed, configured, and running on the node.

## Remarks

The following constants are defined in ClusAPI.h.

| Constant | Value |
| --- | --- |
| **CLUSTER_INSTALLED** | 0x00000001 |
| **CLUSTER_CONFIGURED** | 0x00000002 |
| **CLUSTER_RUNNING** | 0x00000010 |

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)

[GetNodeClusterState](https://learn.microsoft.com/windows/desktop/api/clusapi/nf-clusapi-getnodeclusterstate)