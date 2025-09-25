# PeerGraphSetProperties function

## Description

The **PeerGraphSetProperties** function sets the peer graph properties.

## Parameters

### `hGraph` [in]

Handle to a graph.

### `pGraphProperties` [in]

Pointer to a [PEER_GRAPH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_properties) structure that specifies new values for the graph properties that an application can set.

An application can set only the following fields of [PEER_GRAPH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_properties):

* **pwzFriendlyName**
* **cPresenceMax**
* **pwzComment**
* **ulPresenceLifetime**

**Note** If remaining fields are set, then they are ignored.

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_ACCESSDENIED** | Cannot access a peer graph. |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **PEER_E_INVALID_GRAPH** | The handle to a peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

You can modify
the **pwzFriendlyName**,
**cPresenceMax**, **pwzComment** and
**ulPresenceLifetime** members of the [PEER_GRAPH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_properties) structure.

## See also

[PEER_GRAPH_PROPERTIES](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_properties)

[PeerGraphCreate](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphcreate)

[PeerGraphGetProperties](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetproperties)