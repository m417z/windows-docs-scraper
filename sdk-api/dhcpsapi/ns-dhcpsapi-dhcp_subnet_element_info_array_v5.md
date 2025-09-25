# DHCP_SUBNET_ELEMENT_INFO_ARRAY_V5 structure

## Description

The **DHCP_SUBNET_ELEMENT_INFO_ARRAY_V5** structure defines an array of subnet element data. Element data in the V5 structure is BOOTP specific.

## Members

### `NumElements`

Specifies the number of elements in **Elements**.

### `Elements`

Pointer to a list of [DHCP_SUBNET_ELEMENT_DATA_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v5) structures that contain the data for the corresponding subnet elements.

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DHCP_SUBNET_ELEMENT_DATA_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v5)

[DhcpEnumSubnetElementsV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetelementsv5)