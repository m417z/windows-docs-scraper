# CLUSTER_CHANGE_NODE_UPGRADE_PHASE_V2 enumeration

## Description

Defines the notifications that are generated for the upgrade of a cluster node.

## Constants

### `CLUSTER_CHANGE_UPGRADE_NODE_PREPARE:0x00000001`

Indicates that the upgrade is being prepared.

### `CLUSTER_CHANGE_UPGRADE_NODE_COMMIT:0x00000002`

Indicates that the upgrade is in progress.

### `CLUSTER_CHANGE_UPGRADE_NODE_POSTCOMMIT:0x00000004`

Indicates that the upgrade is finished.

### `CLUSTER_CHANGE_UPGRADE_ALL`

Indicates all **CLUSTER_CHANGE_NODE_UPGRADE_PHASE_V2** notifications.

## See also

[Failover Cluster Enumerations](https://learn.microsoft.com/previous-versions/windows/desktop/mscs/cluster-enumerations)