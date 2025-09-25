# DHCP_IP_RESERVATION_V6 structure

## Description

The **DHCP_IP_RESERVATION_V6** structure defines an IPv6 reservation for a DHCPv6 client in a specific IPv6 prefix.

## Members

### `ReservedIpAddress`

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that contains the IPv6 address of the DHCPv6 client for which an IPv6 reservation is created.

### `ReservedForClient`

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure that contains the hardware address (MAC address) of the DHCPv6 client for which the IPv6 reservation is created.

### `InterfaceId`

Integer that specifies the interface identifier for which the IPv6 reservation is created.

## See also

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address)

[DHCP_IP_RESERVATION_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_info)

[DHCP_IP_RESERVATION_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_v4)

[DHCP_SUBNET_ELEMENT_DATA_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v6)