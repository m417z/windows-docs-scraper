# DHCP_HOST_INFO_V6 structure

## Description

The **DHCP_HOST_INFO_V6** structure contains network information about a DHCPv6 server (host), such as its IPv6 address and name.

## Members

### `IpAddress`

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that contains the IPv6 address of the DHCPv6 server.

### `NetBiosName`

Pointer to a Unicode string that contains the NetBIOS name of the DHCPv6 server.

### `HostName`

Pointer to a Unicode string that contains the network name of the DHCPv6 server.

## Remarks

When this structure is populated by the DHCP Server, the **HostName** and **NetBiosName** members may be set to **NULL**.

## See also

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address)