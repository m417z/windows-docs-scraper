# CLUSTER_CHANGE_RESOURCE_V2 enumeration

## Description

Defines the list of notifications that are generated for a resource.

## Constants

### `CLUSTER_CHANGE_RESOURCE_COMMON_PROPERTY_V2:0x00000001`

Indicates that the resource's common properties have changed.

### `CLUSTER_CHANGE_RESOURCE_PRIVATE_PROPERTY_V2:0x00000002`

Indicates that the resource's private properties have changed.

### `CLUSTER_CHANGE_RESOURCE_STATE_V2:0x00000004`

Indicates that the state of the resource has changed.

### `CLUSTER_CHANGE_RESOURCE_OWNER_GROUP_V2:0x00000008`

Indicates that the owner group of the resource has changed.

### `CLUSTER_CHANGE_RESOURCE_DEPENDENCIES_V2:0x00000010`

Indicates that the resource's dependencies have changed.

### `CLUSTER_CHANGE_RESOURCE_DEPENDENTS_V2:0x00000020`

Indicates that the resource's dependents have changed.

### `CLUSTER_CHANGE_RESOURCE_POSSIBLE_OWNERS_V2:0x00000040`

Indicates that the resource's possible owner nodes have changed.

### `CLUSTER_CHANGE_RESOURCE_DELETED_V2:0x00000080`

Indicates that the resource has been deleted.

### `CLUSTER_CHANGE_RESOURCE_DLL_UPGRADED_V2:0x00000100`

Indicates that the resource's DLL has been upgraded.

### `CLUSTER_CHANGE_RESOURCE_HANDLE_CLOSE_V2:0x00000200`

Indicates that the resource's context handle was closed.

### `CLUSTER_CHANGE_RESOURCE_TERMINAL_STATE_V2:0X00000400`

TBD

### `CLUSTER_CHANGE_RESOURCE_ALL_V2`

Indicates all V2 resource notifications.

## Remarks

Protocol version 2.0 servers do not support this enumeration.