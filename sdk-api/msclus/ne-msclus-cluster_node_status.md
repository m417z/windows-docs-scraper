# CLUSTER_NODE_STATUS enumeration

## Description

Describes the status of a cluster node. This enumeration is used by the **CLUSREG_NAME_NODE_STATUS_INFO** property.

## Constants

### `NodeStatusNormal:0`

The node status is normal.

### `NodeStatusIsolated:0x1`

The node has been isolated.

### `NodeStatusQuarantined:0x2`

The node has been quarantined.

### `NodeStatusDrainInProgress:0x4`

The node is in the process of being drained.

### `NodeStatusDrainCompleted:0x8`

The node has completed a node drain operation.

### `NodeStatusDrainFailed:0x10`

A node drain operation failed on the node.

### `NodeStatusAvoidPlacement:0x20`

### `NodeStatusMax`

The node has experienced a node drain failure, and is therefore isolated and quarantined.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)