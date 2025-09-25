# NET_IF_OPER_STATUS enumeration

## Description

The NET_IF_OPER_STATUS enumeration type defines the current
[NDIS network interface](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-network-interfaces2) operational
status.

## Constants

### `NET_IF_OPER_STATUS_UP:1`

Specifies that the interface is ready to transmit and receive all supported packet types.

### `NET_IF_OPER_STATUS_DOWN:2`

Specifies that the interface is not ready to transmit or receive data. For example, the media is
disconnected or the port is not authenticated. In this state, it might be possible to transmit or
receive some information. For example, if the interface is down because it has not been authenticated,
802.1*x* authentication packets can be transmitted and received.

### `NET_IF_OPER_STATUS_TESTING:3`

Specifies that the interface is in a test mode and no operational packets can be transmitted or
received.

### `NET_IF_OPER_STATUS_UNKNOWN:4`

Specifies that the operational status of the network interface cannot be determined.

### `NET_IF_OPER_STATUS_DORMANT:5`

Specifies that the network interface cannot send or receive packets because the interface is
waiting for an external event.

### `NET_IF_OPER_STATUS_NOT_PRESENT:6`

Specifies that the network interface is not ready to transmit or receive data because a component
is missing in the managed system. This state is more specific than, but similar to, the
**NET_IF_OPER_STATUS_DOWN** state.

### `NET_IF_OPER_STATUS_LOWER_LAYER_DOWN:7`

Specifies that the network interface is not ready to transmit or receive data because underlying
interfaces are down. This state is more specific than, but similar to, the NET_IF_OPER_STATUS_DOWN
state.