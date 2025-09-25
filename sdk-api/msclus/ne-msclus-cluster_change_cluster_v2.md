# CLUSTER_CHANGE_CLUSTER_V2 enumeration

## Description

Defines the list of notifications that are generated for a cluster.

## Constants

### `CLUSTER_CHANGE_CLUSTER_RECONNECT_V2:0x1`

Indicates that a reconnect procedure occurred. This notification applies to clients only.

### `CLUSTER_CHANGE_CLUSTER_STATE_V2:0x2`

Indicates that a cluster state changed. This notification applies to clients only.

### `CLUSTER_CHANGE_CLUSTER_GROUP_ADDED_V2:0x4`

Indicates that a new group was created.

### `CLUSTER_CHANGE_CLUSTER_HANDLE_CLOSE_V2:0x8`

Indicates that a context handle was closed. This notification applies to clients only.

### `CLUSTER_CHANGE_CLUSTER_NETWORK_ADDED_V2:0x10`

Indicates that a cluster network was added to the cluster.

### `CLUSTER_CHANGE_CLUSTER_NODE_ADDED_V2:0x20`

Indicates that a node was added to the cluster. Nodes are added to a cluster in an implementation-specific way.

### `CLUSTER_CHANGE_CLUSTER_RESOURCE_TYPE_ADDED_V2:0x40`

Indicates that a new resource type was added to the cluster.

### `CLUSTER_CHANGE_CLUSTER_COMMON_PROPERTY_V2:0x80`

Indicates that a cluster common property changed.

### `CLUSTER_CHANGE_CLUSTER_PRIVATE_PROPERTY_V2:0x100`

Indicates that a cluster private property changed.

### `CLUSTER_CHANGE_CLUSTER_LOST_NOTIFICATIONS_V2:0x200`

Indicates that notifications might have been lost due to a transient condition on the server.

### `CLUSTER_CHANGE_CLUSTER_RENAME_V2:0x400`

Indicates that the cluster's name changed.

### `CLUSTER_CHANGE_CLUSTER_MEMBERSHIP_V2:0x800`

Indicates that the cluster's membership changed.

### `CLUSTER_CHANGE_CLUSTER_UPGRADED_V2:0x1000`

Indicates that the cluster upgraded the Cluster service.

**Windows Server 2012 R2 and Windows Server 2012:** This value is not supported until Windows Server 2016.

### `CLUSTER_CHANGE_CLUSTER_ALL_V2`

Indicates all V2 cluster notifications.

**Windows Server 2012 R2 and Windows Server 2012:** The value of this constant is 4095 (0x0FFF).