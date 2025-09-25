# CLUSTER_CHANGE_NODE_V2 enumeration

## Description

Defines the notifications that are generated for a cluster node.

## Constants

### `CLUSTER_CHANGE_NODE_NETINTERFACE_ADDED_V2:0x00000001`

Indicates that the network interface for the cluster node has been added.

### `CLUSTER_CHANGE_NODE_DELETED_V2:0x00000002`

Indicates that the cluster node has been deleted.

### `CLUSTER_CHANGE_NODE_COMMON_PROPERTY_V2:0x00000004`

Indicates that the common properties for the cluster node have been changed.

### `CLUSTER_CHANGE_NODE_PRIVATE_PROPERTY_V2:0x00000008`

Indicates that the private properties for the cluster node have been changed.

### `CLUSTER_CHANGE_NODE_STATE_V2:0x00000010`

Indicates that the state of the cluster node has changed.

### `CLUSTER_CHANGE_NODE_GROUP_GAINED_V2:0x00000020`

Indicates that the cluster node has gained a group.

### `CLUSTER_CHANGE_NODE_GROUP_LOST_V2:0x00000040`

Indicates that the cluster node has lost a group.

### `CLUSTER_CHANGE_NODE_HANDLE_CLOSE_V2:0x00000080`

Indicates that the cluster node's context handle was closed.

### `CLUSTER_CHANGE_NODE_ALL_V2`

Indicates all V2 cluster node notifications.

## Remarks

Protocol version 2.0 servers do not support this enumeration.