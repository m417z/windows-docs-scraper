# DHCP_CLIENT_FILTER_STATUS_INFO_ARRAY structure

## Description

The **DHCP_CLIENT_FILTER_STATUS_INFO_ARRAY** structure contains an array of information elements for DHCPv4 clients.

## Members

### `NumElements`

Integer value that contains the number of DHCPv4 clients in the subsequent field Clients.

### `Clients`

Pointer to an array of [DHCP_CLIENT_FILTER_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_filter_status_info) structures that contain the DHCPv4 clients' information.

### `Clients.size_is`

### `Clients.size_is.NumElements`

## See also

[DHCP_CLIENT_FILTER_STATUS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_filter_status_info)