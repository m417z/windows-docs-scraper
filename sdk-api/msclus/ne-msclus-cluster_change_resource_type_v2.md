# CLUSTER_CHANGE_RESOURCE_TYPE_V2 enumeration

## Description

Defines the set of notifications that are generated for a resource type.

## Constants

### `CLUSTER_CHANGE_RESOURCE_TYPE_DELETED_V2:0x1`

Indicates that the resource type has been deleted.

### `CLUSTER_CHANGE_RESOURCE_TYPE_COMMON_PROPERTY_V2:0x2`

Indicates that the resource type common properties have changed.

### `CLUSTER_CHANGE_RESOURCE_TYPE_PRIVATE_PROPERTY_V2:0x4`

Indicates that the resource type private properties have changed.

### `CLUSTER_CHANGE_RESOURCE_TYPE_POSSIBLE_OWNERS_V2:0x8`

Indicates that the possible owners for the resource type have changed.

### `CLUSTER_CHANGE_RESOURCE_TYPE_DLL_UPGRADED_V2:0x10`

Indicates that the resource type DLL has been upgraded.

### `CLUSTER_RESOURCE_TYPE_SPECIFIC_V2:0x20`

An indication that is specific to the resource type.

**Windows Server 2012 R2 and Windows Server 2012:** This member is not supported until Windows Server 2016.

### `CLUSTER_CHANGE_RESOURCE_TYPE_ALL_V2`

Indicates all V2 resource type notifications.