# CLUSTER_CHANGE_NETINTERFACE_V2 enumeration

## Description

Defines the set of notifications that are generated for a cluster network interface.

## Constants

### `CLUSTER_CHANGE_NETINTERFACE_DELETED_V2:0x1`

Indicates that the cluster network interface has been deleted.

### `CLUSTER_CHANGE_NETINTERFACE_COMMON_PROPERTY_V2:0x2`

Indicates that the common properties for the cluster interface have changed.

### `CLUSTER_CHANGE_NETINTERFACE_PRIVATE_PROPERTY_V2:0x4`

Indicates that the private properties for the cluster interface have changed.

### `CLUSTER_CHANGE_NETINTERFACE_STATE_V2:0x8`

Indicates that the state of the cluster interface has changed.

### `CLUSTER_CHANGE_NETINTERFACE_HANDLE_CLOSE_V2:0x10`

Indicates that the cluster interface's context handle was closed.

### `CLUSTER_CHANGE_NETINTERFACE_ALL_V2`

Indicates all V2 network interface notifications.

## Remarks

Protocol version 2.0 servers do not support this enumeration.