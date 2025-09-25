# DHCP_CLIENT_INFO_PB_ARRAY structure

## Description

The **DHCP_CLIENT_INFO_PB_ARRAY** structure defines an array of DHCPv4 client information elements.

## Members

### `NumElements`

Integer that contains the number of DHCPv4 clients in **Clients**.

### `Clients`

Pointer to an array of [DHCP_CLIENT_INFO_PB](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_pb) structures that contain DHCPv4 client information.

### `Clients.size_is`

### `Clients.size_is.NumElements`

## See also

[DhcpV4EnumSubnetClients](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4enumsubnetclients)