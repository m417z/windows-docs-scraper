# MF_CONNECT_METHOD enumeration

## Description

Specifies how the topology loader connects a topology node. This enumeration is used with the [MF_TOPONODE_CONNECT_METHOD](https://learn.microsoft.com/windows/desktop/medfound/mf-toponode-connect-method-attribute) attribute.

## Constants

### `MF_CONNECT_DIRECT:0`

Connect the node directly to its upstream neighbor. Fail otherwise.

### `MF_CONNECT_ALLOW_CONVERTER:0x1`

Add a converter transform upstream from this node, if needed to complete the connection. Converter transforms include color-space converters for video, and audio resamplers for audio.

### `MF_CONNECT_ALLOW_DECODER:0x3`

Add a decoder transform upstream upstream from this node, if needed to complete the connection. The numeric value of this flag includes the **MF_CONNECT_ALLOW_CONVERTER** flag. Therefore, setting the **MF_CONNECT_ALLOW_DECODER** flag sets the **MF_CONNECT_ALLOW_CONVERTER** flag as well.

### `MF_CONNECT_RESOLVE_INDEPENDENT_OUTPUTTYPES:0x4`

Controls the order in which the topology loader attempts to
use different output types from this node. Currently, this flag applies only to source nodes. For more information, see [MF_TOPOLOGY_ENUMERATE_SOURCE_TYPES](https://learn.microsoft.com/windows/desktop/medfound/mf-topology-enumerate-source-types).

**Note** Requires Windows 7 or later.

### `MF_CONNECT_AS_OPTIONAL:0x10000`

This node is optional. If the topology loader cannot connect this node, it will skip the node and continue.

### `MF_CONNECT_AS_OPTIONAL_BRANCH:0x20000`

The entire topology branch starting at this node is optional. If the topology loader cannot resolve this branch, it will skip the branch and continue.

## See also

[Media Foundation Enumerations](https://learn.microsoft.com/windows/desktop/medfound/media-foundation-enumerations)