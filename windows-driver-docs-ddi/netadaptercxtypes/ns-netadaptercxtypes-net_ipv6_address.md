# NET_IPV6_ADDRESS union

## Description

The **NET_IPV6_ADDRESS** union specifies an IPv6 address.

## Members

### `Unicast`

A structure that represents a IPv6 unicast address and contains the **NetworkPrefix** and **InterfaceIdentifier** values.

### `Unicast.NetworkPrefix`

A UINT64 value that represents the network prefix.

### `Unicast.InterfaceIdentifier`

A UINT64 value that represents the interface identifier.

### `Value`

A UINT8 array that represents an IPv6 address.

## Remarks

## See also

[**NET_IPV4_ADDRESS**](https://learn.microsoft.com/windows-hardware/drivers/ddi/netadaptercxtypes/ns-netadaptercxtypes-net_ipv4_address)