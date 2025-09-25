# MF_TOPOLOGY_RESOLUTION_STATUS_FLAGS enumeration

## Description

Defines status flags for the [MF_TOPOLOGY_RESOLUTION_STATUS](https://learn.microsoft.com/windows/desktop/medfound/mf-topology-resolution-status-attribute) attribute.

## Constants

### `MF_TOPOLOGY_RESOLUTION_SUCCEEDED:0`

The topology was resolved successfully.

### `MF_OPTIONAL_NODE_REJECTED_MEDIA_TYPE:0x1`

An optional topology node was rejected because the topology loader could not find a media type for the connection.

### `MF_OPTIONAL_NODE_REJECTED_PROTECTED_PROCESS:0x2`

An optional topology node was rejected because it could not be loaded into a protected process.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)