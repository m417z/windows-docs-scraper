# PEER_CONNECTION_INFO structure

## Description

The **PEER_CONNECTION_INFO** structure contains information about a connection. This structure is returned when you are enumerating peer graphing or grouping connections.

## Members

### `dwSize`

Specifies the size a structure.

### `dwFlags`

Specifies the type of connection to a remote node. Valid values are specified by [PEER_CONNECTION_FLAGS](https://learn.microsoft.com/windows/desktop/api/p2p/ne-p2p-peer_connection_flags).

### `ullConnectionId`

Specifies the unique ID of a connection.

### `ullNodeId`

Specifies the unique ID of a node.

### `pwzPeerId`

Points to a string that identifies the node on the other end of a connection.

### `address`

Specifies the address of a remote node. The address is contained in a [PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address) structure.

## See also

[PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address)

[PeerGraphEnumConnections](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphenumconnections)

[PeerGroupEnumConnections](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergroupenumconnections)