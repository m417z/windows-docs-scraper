# IPX_PATTERN structure

## Description

The **IPX_PATTERN** structure applies a specific pattern or corresponding mask for the IPX protocol. The
**IPX_PATTERN** structure designation is used by the traffic control interface in the application of packet filters.

## Members

### `Src`

### `Src.NetworkAddress`

### `Src.NodeAddress`

### `Src.Socket`

### `Dest`

### `Src,` Dest

Structure used to contain source and destination address information for traffic flow.

#### NetworkAddress

IPX network address to which the node belongs.

#### NodeAddress

IPX node address of the computer.

#### Socket

Socket on which the mask is to be applied.

## See also

[FLOWSPEC](https://learn.microsoft.com/windows/desktop/api/qos/ns-qos-flowspec)