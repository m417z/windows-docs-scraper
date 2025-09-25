# DHCP_SUBNET_ELEMENT_INFO_ARRAY_V6 structure

## Description

The **DHCP_SUBNET_ELEMENT_INFO_ARRAY_V6** structure contains data that defines an array of [DHCP_SUBNET_ELEMENT_DATA_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v6) IPv6 prefix elements.

## Members

### `NumElements`

A **DWORD** value containing the number of IPv6 subnet elements in the **Elements** member.

### `Elements`

Pointer to an array of [DHCP_SUBNET_ELEMENT_DATA_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v6) structures that contain IPv6 prefix elements.

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DHCP_SUBNET_ELEMENT_DATA_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v6)