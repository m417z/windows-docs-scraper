# PEER_ENDPOINT structure

## Description

The **PEER_ENDPOINT** structure contains the address and friendly name of a peer endpoint.

## Members

### `address`

[PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address) structure that contains the IPv6 network address of the endpoint.

### `pwzEndpointName`

Zero-terminated Unicode string that contains the specific displayable name of the endpoint.

## Remarks

A peer "endpoint" describes a contact's presence location — the unique network address configuration that describes the currently available instance of the contact within the peer collaboration network. A single contact can be available at multiple endpoints within the peer collaboration network.

A peer watching a contact can query any of the endpoints associated with that contact for specific peer presence, application, or object updates.

## See also

[PEER_ADDRESS](https://learn.microsoft.com/windows/desktop/api/p2p/ns-p2p-peer_address)

[Peer Collaboration API Structures](https://learn.microsoft.com/windows/desktop/P2PSdk/collaboration-api-structures)