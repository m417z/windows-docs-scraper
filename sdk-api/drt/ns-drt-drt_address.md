# DRT_ADDRESS structure

## Description

The **DRT_ADDRESS** structure contains endpoint information about a DRT node that participated in a search. This information is intended for use in debugging connectivity problems.

## Members

### `socketAddress`

Contains the endpoint on which the DRT protocol is listening on the remote node.

### `flags`

Holds information explaining how this node behaved in the key lookup.

### `nearness`

Contains the number of bits that the key published by this node shares in common with the target key in the search.

### `latency`

Round trip time to this node.

## See also

[DRT_ADDRESS_LIST](https://learn.microsoft.com/windows/desktop/api/drt/ns-drt-drt_address_list)