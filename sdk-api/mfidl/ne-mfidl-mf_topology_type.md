# MF_TOPOLOGY_TYPE enumeration

## Description

Defines the type of a topology node.

## Constants

### `MF_TOPOLOGY_OUTPUT_NODE:0`

Output node. Represents a media sink in the topology.

### `MF_TOPOLOGY_SOURCESTREAM_NODE`

Source node. Represents a media stream in the topology.

### `MF_TOPOLOGY_TRANSFORM_NODE`

Transform node. Represents a Media Foundation Transform (MFT) in the topology.

### `MF_TOPOLOGY_TEE_NODE`

Tee node. A tee node does not hold a pointer to an object. Instead, it represents a fork in the stream. A tee node has one input and multiple outputs, and samples from the upstream node are delivered to all of the downstream nodes.

### `MF_TOPOLOGY_MAX:0xffffffff`

Reserved.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)