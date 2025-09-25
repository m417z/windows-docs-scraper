# CLUSTER_CHANGE_REGISTRY_V2 enumeration

## Description

Defines the notifications that are generated for a registry key.

## Constants

### `CLUSTER_CHANGE_REGISTRY_ATTRIBUTES_V2:0x00000001`

Indicates that the registry attributes changed.

### `CLUSTER_CHANGE_REGISTRY_NAME_V2:0x00000002`

Indicates that the registry key name has changed.

### `CLUSTER_CHANGE_REGISTRY_SUBTREE_V2:0x00000004`

Indicates that the registry subtree has changed.

### `CLUSTER_CHANGE_REGISTRY_VALUE_V2:0x00000008`

Indicates that the registry value has changed.

### `CLUSTER_CHANGE_REGISTRY_HANDLE_CLOSE_V2:0x00000010`

Indicates that the registry's context handle was closed.

### `CLUSTER_CHANGE_REGISTRY_ALL_V2`

Indicates all V2 registry notifications.

## Remarks

Protocol version 2.0 servers do not support this enumeration.