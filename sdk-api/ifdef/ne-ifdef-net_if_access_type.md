# NET_IF_ACCESS_TYPE enumeration

## Description

The NET_IF_ACCESS_TYPE enumeration type specifies the
[NDIS network interface](https://learn.microsoft.com/windows-hardware/drivers/network/ndis-network-interfaces2) access
type.

## Constants

### `NET_IF_ACCESS_LOOPBACK:1`

Specifies the loopback access type. This access type indicates that the interface loops back
transmit data as receive data.

### `NET_IF_ACCESS_BROADCAST:2`

Specifies the LAN access type, which includes Ethernet. This access type indicates that the
interface provides native support for multicast or broadcast services.

### `NET_IF_ACCESS_POINT_TO_POINT:3`

Specifies point-to-point access that supports CoNDIS and WAN, except for non-broadcast
multi-access (NBMA) interfaces.

### `NET_IF_ACCESS_POINT_TO_MULTI_POINT:4`

Specifies point-to-multipoint access that supports non-broadcast multi-access (NBMA) media,
including the "RAS Internal" interface, and native (non-LANE) ATM.

### `NET_IF_ACCESS_MAXIMUM:5`

A maximum value for testing purposes.