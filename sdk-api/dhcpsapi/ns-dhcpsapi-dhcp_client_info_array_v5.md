# DHCP_CLIENT_INFO_ARRAY_V5 structure

## Description

The **DHCP_CLIENT_INFO_ARRAY_V5** structure defines an array of [DHCP_CLIENT_INFO_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v5) structures for use with enumeration functions.

## Members

### `NumElements`

Specifies the number of elements present in **Clients**.

### `Clients`

Pointer to a list of [DHCP_CLIENT_INFO_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v5) structures that contain information on specific DHCP subnet clients, including the dynamic address type (DHCP and/or BOOTP) and address state information.

### `Clients.size_is`

### `Clients.size_is.NumElements`

## See also

[DHCP_CLIENT_INFO_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_client_info_v5)

[DhcpEnumSubnetClientsV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetclientsv5)