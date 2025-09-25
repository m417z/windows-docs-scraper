# STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR structure

## Description

The **STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR** structure is one of the query result structures returned from an [IOCTL_STORAGE_QUERY_PROPERTY](https://learn.microsoft.com/windows/desktop/api/winioctl/ni-winioctl-ioctl_storage_query_property) request. This structure describes storage device physical topology.

## Members

### `Version`

Contains the size of this structure, in bytes. Set to `sizeof(STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR)`.

### `Size`

Specifies the total size of the data, in bytes. Should be >= `sizeof(STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR)`.

### `NodeCount`

Specifies the number of nodes.

### `Reserved`

Reserved.

### `Node`

A node as specified by a [STORAGE_PHYSICAL_NODE_DATA](https://learn.microsoft.com/windows/desktop/api/winioctl/ns-winioctl-storage_physical_node_data) structure.