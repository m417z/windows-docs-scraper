# DHCP_CLIENT_INFO_ARRAY_V6 structure

## Description

The **DHCP_CLIENT_INFO_ARRAY_V6** structure defines an array of [DHCP_CLIENT_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v6) structures for use with DHCPv6 client enumeration functions.

## Members

### `NumElements`

Specifies the number of elements present in **Clients**.

### `Clients`

Pointer to a list of [DHCP_CLIENT_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v6) structures that contain information on specific DHCPv6 subnet clients, including the dynamic address type (DHCP and/or BOOTP) and address state information.

### `Clients.size_is`

### `Clients.size_is.NumElements`

## See also

[DHCP_CLIENT_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v6)