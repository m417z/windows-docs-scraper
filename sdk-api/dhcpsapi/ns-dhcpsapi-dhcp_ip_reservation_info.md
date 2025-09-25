# DHCP_IP_RESERVATION_INFO structure

## Description

The **DHCP_IP_RESERVATION_INFO** structure defines an IPv4 reservation for a DHCPv4 client. It extends the [DHCP_IP_RESERVATION_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_v4) structure by including the reservation client name and description.

## Members

### `ReservedIpAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the reserved IP address.

### `ReservedForClient`

[DHCP_CLIENT_UID](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_binary_data) structure that contains the hardware address (MAC address) of the DHCPv4 client that holds this reservation.

### `ReservedClientName`

Pointer to a null-terminated Unicode string that represents the DHCPv4 reserved client machine name.

### `ReservedClientDesc`

Pointer to a null-terminated Unicode string that represents the description of the DHCPv4 reserved client.

### `bAllowedClientTypes`

Value that specifies the DHCPv4 reserved client type. The possible values are below:

| Value | Meaning |
| --- | --- |
| **CLIENT_TYPE_DHCP**<br><br>1 | The DHCPv4 client supports the DHCP protocol only. |
| **CLIENT_TYPE_BOOTP**<br><br>2 | The DHCPv4 client supports the BOOTP protocol only. |
| **CLIENT_TYPE_BOTH**<br><br>3 | The DHCPv4 client supports both the DHCPv4 and the BOOTP protocols. |

### `fOptionsPresent`

**TRUE** if the DHCPv4 reserved client has options configured at reservation level. Otherwise, it is **FALSE**.

## See also

[DHCP_IP_RESERVATION_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_v4)

[DHCP_IP_RESERVATION_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_v6)

[DHCP_RESERVATION_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_reservation_info_array)