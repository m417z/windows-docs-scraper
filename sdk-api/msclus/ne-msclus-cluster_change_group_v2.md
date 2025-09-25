# CLUSTER_CHANGE_GROUP_V2 enumeration

## Description

Defines the list of notifications that are generated for a group.

## Constants

### `CLUSTER_CHANGE_GROUP_DELETED_V2:0x1`

Indicates that a group was deleted.

### `CLUSTER_CHANGE_GROUP_COMMON_PROPERTY_V2:0x2`

Indicates that a group's common property changed.

### `CLUSTER_CHANGE_GROUP_PRIVATE_PROPERTY_V2:0x4`

Indicates that a group's private property changed.

### `CLUSTER_CHANGE_GROUP_STATE_V2:0x8`

Indicates that the group's state changed.

### `CLUSTER_CHANGE_GROUP_OWNER_NODE_V2:0x10`

Indicates that the group's owner node has changed.

### `CLUSTER_CHANGE_GROUP_PREFERRED_OWNERS_V2:0x20`

Indicates that the group's preferred owners have changed.

### `CLUSTER_CHANGE_GROUP_RESOURCE_ADDED_V2:0x40`

Indicates that a resource was added to the group.

### `CLUSTER_CHANGE_GROUP_RESOURCE_GAINED_V2:0x80`

Indicates that the group gained a resource.

### `CLUSTER_CHANGE_GROUP_RESOURCE_LOST_V2:0x100`

Indicates that a resource is no longer part of the group.

### `CLUSTER_CHANGE_GROUP_HANDLE_CLOSE_V2:0x200`

Indicates that the group's context handle was closed.

### `CLUSTER_CHANGE_GROUP_ALL_V2`

Indicates all V2 group notifications.

## Remarks

Protocol version 2.0 servers do not support this enumeration.