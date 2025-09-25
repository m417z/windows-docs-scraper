# CLUSTER_CHANGE_GROUPSET_V2 enumeration

## Description

Defines the list of notifications that are generated for a groupset.

## Constants

### `CLUSTER_CHANGE_GROUPSET_DELETED_v2:0x1`

Indicates that a groupset was deleted.

### `CLUSTER_CHANGE_GROUPSET_COMMON_PROPERTY_V2:0x2`

Indicates that a common property of the groupset has changed.

### `CLUSTER_CHANGE_GROUPSET_PRIVATE_PROPERTY_V2:0x4`

Indicates that a private property of the groupset has changed.

### `CLUSTER_CHANGE_GROUPSET_STATE_V2:0x8`

Indicates that the group's state changed.

### `CLUSTER_CHANGE_GROUPSET_GROUP_ADDED:0x10`

Indicates that a group has been added to the groupset.

### `CLUSTER_CHANGE_GROUPSET_GROUP_REMOVED:0x20`

Indicates that a group has been removed from the groupset.

### `CLUSTER_CHANGE_GROUPSET_DEPENDENCIES_V2:0x40`

Indicates that the groupset's dependencies have changed.

### `CLUSTER_CHANGE_GROUPSET_DEPENDENTS_V2:0x80`

Indicates that the groupset's dependents have changed.

### `CLUSTER_CHANGE_GROUPSET_HANDLE_CLOSE_v2:0x100`

Indicates that the group's context handle was closed.

### `CLUSTER_CHANGE_GROUPSET_ALL_V2`