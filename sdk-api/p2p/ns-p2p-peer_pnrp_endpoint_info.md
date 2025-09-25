# PEER_PNRP_ENDPOINT_INFO structure

## Description

The **PEER_PNRP_ENDPOINT_INFO** structure contains the IP addresses and data associated with a peer endpoint.

## Members

### `pwzPeerName`

The peer name associated with this peer endpoint.

### `cAddresses`

The number of SOCKADDR structures in **pAddresses**.

### `ppAddresses`

Pointer to an array of pointers to SOCKADDR structures that contain the IP addresses for the peer endpoint's network interface.

### `pwzComment`

Pointer to a zero-terminated Unicode string that contains a comment for this peer endpoint.

### `payload`

Pointer to a [PEER_DATA](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_data) structure that contains application-specific data for the peer endpoint (such as a message or an image).