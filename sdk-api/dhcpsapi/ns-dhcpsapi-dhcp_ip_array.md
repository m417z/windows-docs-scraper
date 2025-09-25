# DHCP_IP_ARRAY structure

## Description

The **DHCP_IP_ARRAY** structure defines an array of IP addresses.

## Members

### `NumElements`

Specifies the number of IP addresses in **Elements**.

### `Elements`

Pointer to a list of [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) values.

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions)

[DhcpEnumSubnets](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnets)