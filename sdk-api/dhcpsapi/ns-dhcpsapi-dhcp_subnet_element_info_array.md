# DHCP_SUBNET_ELEMENT_INFO_ARRAY structure

## Description

The **DHCP_SUBNET_ELEMENT_INFO_ARRAY** structure defines an array of subnet element data.

## Members

### `NumElements`

Specifies the number of elements in **Elements**.

### `Elements`

Pointer to a list of [DHCP_SUBNET_ELEMENT_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data) structures that contain the data for the corresponding subnet elements.

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DHCP_SUBNET_ELEMENT_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data)

[DhcpEnumSubnetElements](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetelements)