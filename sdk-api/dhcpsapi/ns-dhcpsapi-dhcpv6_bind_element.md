# DHCPV6_BIND_ELEMENT structure

## Description

The **DHCPV6_BIND_ELEMENT** structure defines an IPv6 interface binding for the DHCP server over which it receives DHCPv6 packets.

## Members

### `Flags`

A set of bit flags indicating properties of the interface binding.

| Value | Meaning |
| --- | --- |
| **DHCP_ENDPOINT_FLAG_CANT_MODIFY** | The endpoints cannot be modified. |

### `fBoundToDHCPServer`

If **TRUE**, the interface is bound to the DHCPv6 server; if **FALSE**, it is not.

### `AdapterPrimaryAddress`

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that contains the IPv6 address assigned to the interface over which the DHCP server is receiving DHCPv6 packets.

### `AdapterSubnetAddress`

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that contains the IPv6 prefix ID of the subnet from which this interface is receiving DHCPv6 packets.

### `IfDescription`

Pointer to a null-terminated Unicode string that specifies the name assigned to this interface.

### `IpV6IfIndex`

Integer that specifies the IPv6 interface index of the current interface.

### `IfIdSize`

Integer that specifies the size of the interface GUID stored in **IfId**.

### `IfId`

 Pointer to a BYTE blob that contains the GUID value assigned to this interface.

### `IfId.size_is`

### `IfId.size_is.IfIdSize`

## See also

[DHCPV6_BIND_ELEMENT_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_bind_element_array)

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address)