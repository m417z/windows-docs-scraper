# DHCP_IP_RANGE_ARRAY structure

## Description

The **DHCP_IP_RANGE_ARRAY** structure defines an array of DHCP IPv4 ranges.

## Members

### `NumElements`

Integer that specifies the number of DHCP IPv4 ranges in **Elements.**

### `Elements`

Pointer to a list of [DHCP_IP_RANGE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_range) structures.

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DHCP_POLICY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_policy)