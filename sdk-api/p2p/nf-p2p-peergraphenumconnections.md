# PeerGraphEnumConnections function

## Description

The **PeerGraphEnumConnections** function creates and returns an enumeration handle used to enumerate the connections of a local node.

## Parameters

### `hGraph` [in]

Handle to a peer graph.

### `dwFlags` [in]

The type of connection to enumerate. This parameter is required. Valid values are specified by [PEER_CONNECTION_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_connection_flags).

### `phPeerEnum` [out]

Receives a handle to an enumeration. Use [PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem) to retrieve the actual connection information. When this handle is not required, free it by calling [PeerGraphEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphendenumeration).

## Return value

If the function call succeeds, the return value is **S_OK**. Otherwise, it returns one of the following values.

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | One of the parameters is not valid. |
| **E_OUTOFMEMORY** | There is not enough memory to perform a specified operation. |
| **PEER_E_INVALID_GRAPH** | The handle to a peer graph is invalid. |
| **PEER_E_NOT_INITIALIZED** | The peer graph must be initialized with a call to [PeerGraphStartup](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphstartup) before using this function. |

## Remarks

When [PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem) is called with the enumeration handle returned by **PeerGraphEnumConnections**, **PeerGraphGetNextItem** returns a [PEER_CONNECTION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_connection_info) structure.

## See also

[PEER_CONNECTION_INFO](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_connection_info)

[PeerGraphEndEnumeration](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphendenumeration)

[PeerGraphGetItemCount](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetitemcount)

[PeerGraphGetNextItem](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnextitem)