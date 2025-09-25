# NET_IF_CONNECTION_TYPE enumeration

## Description

The NET_IF_CONNECTION_TYPE enumeration type specifies the
[NDIS network interface](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-network-interfaces2) connection
type.

## Constants

### `NET_IF_CONNECTION_DEDICATED:1`

Specifies the dedicated connection type. The connection comes up automatically when media sense is
**TRUE**. For example, an Ethernet connection is dedicated.

### `NET_IF_CONNECTION_PASSIVE:2`

Specifies the passive connection type. The other end must bring up the connection to the local
station. For example, the RAS interface is passive.

### `NET_IF_CONNECTION_DEMAND:3`

Specifies the demand-dial connection type. A demand-dial connection comes up in response to a
local action--for example, sending a packet.

### `NET_IF_CONNECTION_MAXIMUM:4`

A maximum value for testing purposes.