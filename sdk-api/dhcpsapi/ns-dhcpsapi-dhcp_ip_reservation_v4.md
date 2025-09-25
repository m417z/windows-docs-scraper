# DHCP_IP_RESERVATION_V4 structure

## Description

The **DHCP_IP_RESERVATION_V4** structure defines a client IP reservation. This structure extends an IP reservation by including the type of client (DHCP or BOOTP) holding the reservation.

## Members

### `ReservedIpAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the reserved IP address.

### `ReservedForClient`

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure that contains the hardware address (MAC address) of the DHCPv4 client that holds this reservation.

### `bAllowedClientTypes`

Value that specifies the DHCPv4 reserved client type. The possible values are below:

| Value | Meaning |
| --- | --- |
| **CLIENT_TYPE_DHCP**<br><br>1 | The DHCPv4 client supports the DHCP protocol only. |
| **CLIENT_TYPE_BOOTP**<br><br>2 | The DHCPv4 client supports the BOOTP protocol only. |
| **CLIENT_TYPE_BOTH**<br><br>3 | The DHCPv4 client supports both the DHCPv4 and the BOOTP protocols. |

## See also

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions)

[DHCP_IP_RESERVATION_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_info)

[DHCP_IP_RESERVATION_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_v6)