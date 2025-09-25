# PeerGraphSetPresence function

## Description

The **PeerGraphSetPresence** function explicitly turns on or off the publication of presence records for a specific node. This function can override the presence settings in the peer graph properties. Calling this function enables nodes to be enumerated with [PeerGraphEnumNodes](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumnodes).

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `fPresent` [in]

Specify **TRUE** to force the Peer Graphing Infrastructure to publish a presence record for this node, which overrides the setting specified by the **cPresenceMax** in [PEER_GRAPH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_properties). Specify **FALSE** to return the node to the default behavior specified in the peer graph properties.

**Note** Depending on the peer graphing presence policy, setting *fPresent* to **FALSE** does not guarantee that a peer's presence information is removed. It means that a peer's presence is not published anymore.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. The presence information cannot be published. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

If presence information has not been explicitly published by the peer graph, the nodes are not visible when a peer graph is enumerated.

## See also

[PeerGraphEnumNodes](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumnodes)