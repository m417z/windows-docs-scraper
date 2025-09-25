# PEER_GRAPH_SCOPE enumeration

## Description

The **PEER_GRAPH_SCOPE** enumeration specifies the network scope of a peer graph.

## Constants

### `PEER_GRAPH_SCOPE_ANY:0`

The peer graph's network scope can contain any IP address, valid or otherwise.

### `PEER_GRAPH_SCOPE_GLOBAL:1`

The IP addresses for the peer graph's network scope can be from any unblocked address range.

### `PEER_GRAPH_SCOPE_SITELOCAL:2`

The IP addresses for the peer graph's network scope must be within the IP range defined for the site.

### `PEER_GRAPH_SCOPE_LINKLOCAL:3`

The IP addresses for the peer graph's network scope must be within the IP range defined for the local area network.

### `PEER_GRAPH_SCOPE_LOOPBACK:4`

The peer graph's network scope is the local computer's loopback IP address.