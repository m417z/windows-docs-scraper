# DOT11_ADHOC_NETWORK_CONNECTION_STATUS enumeration

## Description

Specifies the connection state of an ad hoc network.

## Constants

### `DOT11_ADHOC_NETWORK_CONNECTION_STATUS_INVALID`

The connection status cannot be determined. A network with this status should not be used.

### `DOT11_ADHOC_NETWORK_CONNECTION_STATUS_DISCONNECTED`

There are no hosts or clients connected to the network. There are also no pending connection requests for this network.

### `DOT11_ADHOC_NETWORK_CONNECTION_STATUS_CONNECTING`

There is an outstanding connection request. Once the client or host succeeds or fails in its connection attempt, the connection status is updated.

### `DOT11_ADHOC_NETWORK_CONNECTION_STATUS_CONNECTED`

A client or host is connected to the network.

### `DOT11_ADHOC_NETWORK_CONNECTION_STATUS_FORMED`

The network has been formed. Once a client or host connects to the network, the connection status is updated.