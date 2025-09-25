# CLUSTER_CHANGE_NETWORK_V2 enumeration

## Description

Defines the notifications that are generated for a cluster network.

## Constants

### `CLUSTER_CHANGE_NETWORK_DELETED_V2:0x00000001`

Indicates that the cluster network has been deleted.

### `CLUSTER_CHANGE_NETWORK_COMMON_PROPERTY_V2:0x00000002`

Indicates that the common properties for the cluster network have changed.

### `CLUSTER_CHANGE_NETWORK_PRIVATE_PROPERTY_V2:0x00000004`

Indicates that the private properties for the cluster network have changed.

### `CLUSTER_CHANGE_NETWORK_STATE_V2:0x00000008`

Indicates that the cluster network state has changed.

### `CLUSTER_CHANGE_NETWORK_HANDLE_CLOSE_V2:0x00000010`

Indicates that the cluster network's context handle was closed.

### `CLUSTER_CHANGE_NETWORK_ALL_V2`

Indicates all V2 cluster network notifications.

## Remarks

Protocol version 2.0 servers do not support this enumeration.