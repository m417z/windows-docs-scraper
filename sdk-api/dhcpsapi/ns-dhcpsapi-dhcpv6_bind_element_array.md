# DHCPV6_BIND_ELEMENT_ARRAY structure

## Description

The **DHCPV6_BIND_ELEMENT_ARRAY** structure specifies an array of [DHCPV6_BIND_ELEMENT](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_bind_element) structures that contain DHCPv6 interface bindings.

## Members

### `NumElements`

Integer that contains the total number of elements in the array pointed to by **Elements**.

### `Elements`

Pointer to an array of [DHCPV6_BIND_ELEMENT](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_bind_element) structures that contains the DHCPv6 interface bindings.

### `Elements.size_is`

### `Elements.size_is.NumElements`

## See also

[DHCPV6_BIND_ELEMENT](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_bind_element)