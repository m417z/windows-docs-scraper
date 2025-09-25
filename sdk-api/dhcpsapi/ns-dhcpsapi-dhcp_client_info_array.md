# DHCP_CLIENT_INFO_ARRAY structure

## Description

The **DHCP_CLIENT_INFO_ARRAY** structure defines an array of [DHCP_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info) structures for use with enumeration functions.

## Members

### `NumElements`

Specifies the number of elements present in **Clients**.

### `Clients`

Pointer to a list of [DHCP_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info) structures that contain information on specific DHCP subnet clients.).

### `Clients.size_is`

### `Clients.size_is.NumElements`

## See also

[DHCP_CLIENT_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info)

[DhcpEnumSubnetClients](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetclients)