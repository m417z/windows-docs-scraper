# PeerGraphRegisterEvent function

## Description

The **PeerGraphRegisterEvent** function registers a peer's request to be notified of changes associated with a peer graph and event type.

## Parameters

### `hGraph` [in]

Handle to the peer graph.

### `hEvent` [in]

Handle created by [CreateEvent](https://learn.microsoft.com/windows/desktop/P2PSdk/graphing-reference-links) that the application is signaled on when an event is triggered. When an application is signaled, it must call [PeerGraphGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgeteventdata) to retrieve events until PEER_S_NO_EVENT_DATA returned.

### `cEventRegistrations` [in]

Specifies the number of [PEER_GRAPH_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_registration) structures in *pEventRegistrations*.

### `pEventRegistrations` [in]

Points to an array of [PEER_GRAPH_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_registration) structures that specify what events the application requests notifications for.

### `phPeerEvent` [out]

Receives a **HPEEREVENT** handle. This handle must be used when calling [PeerGraphUnregisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphunregisterevent) to stop receiving notifications.

## Return value

If the function call succeeds, the return value is S_OK. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform the specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to the peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## See also

[PEER_GRAPH_EVENT_REGISTRATION](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_graph_event_registration)

[PeerGraphGetEventData](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgeteventdata)

[PeerGraphUnregisterEvent](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphunregisterevent)