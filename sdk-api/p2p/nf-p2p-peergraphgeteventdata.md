# PeerGraphGetEventData function

## Description

The **PeerGraphGetEventData** function retrieves peer events. An application calls this function until the return value **PEER_S_NO_EVENT_DATA** is returned, which indicates that a call is successful, but that there are no more peer events to retrieve.

## Parameters

### `hPeerEvent` [in]

Peer event handle obtained by a call to [PeerGraphRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphregisterevent).

### `ppEventData` [out]

Receives a pointer to a [PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data) structure that contains the data about an event notification. When this structure is not needed, free it by calling [PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One parameter is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_S_NO_EVENT_DATA** | The function call succeeds, but there is no data associated with a peer event. |
| **PEER_E_NOT_INITIALIZED** | A peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

Peer event data is returned in a [PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data) structure. The type of data structure that **PEER_GRAPH_EVENT_DATA** points to depends on which event is triggered.

## See also

[PEER_GRAPH_EVENT_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_data)

[PeerGraphFreeData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphfreedata)

[PeerGraphRegisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphregisterevent)

[PeerGraphUnregisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphunregisterevent)