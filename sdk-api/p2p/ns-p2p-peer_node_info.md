# PEER_NODE_INFO structure

## Description

The **PEER_NODE_INFO** structure contains information that is specific to a particular node in a peer graph.

## Members

### `dwSize`

Specifies the size of the data structure. Set the value to sizeof(**PEER_NODE_INFO**). This member is required and has no default value.

### `ullNodeId`

Specifies a unique ID that identifies an application's connection to its neighbor. An application cannot set the value of this member, it is created by the Peer Graphing Infrastructure.

### `pwzPeerId`

Specifies the ID of this peer. This value is set for the application by the Peer Graphing Infrastructure. when the application creates or opens a peer graph.

### `cAddresses`

Specifies the number of addresses in **pAddresses**. This member is required and has no default value.

### `pAddresses`

Points to an array of [PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address) structures that indicate which addresses and ports this instance is listening to for group traffic. This member is required and has no default value.

### `pwzAttributes`

Points to a string that contains the attributes that describe this particular node. This string is a free-form text string that is specific to the application. This parameter is optional; the default value is **NULL**.

## See also

[PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address)

[PeerGraphGetNodeInfo](https://learn.microsoft.com/windows/desktop/api/p2p/nf-p2p-peergraphgetnodeinfo)