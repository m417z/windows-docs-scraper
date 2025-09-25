# DHCP_SUBNET_ELEMENT_DATA_V6 structure

## Description

The **DHCP_SUBNET_ELEMENT_DATA_V6** structure contains definitions for the elements of the IPv6 prefix, such as IPv6 reservation, IPv6 exclusion range, and IPv6 range.

## Members

### `ElementType`

Defines the set of possible prefix element types. This value is used to determine which of the values are chosen from the subsequent union element.

### `Element.IpRange.case`

### `Element.IpRange.case.Dhcpv6IpRanges`

### `Element.ReservedIp.case`

### `Element.ReservedIp.case.Dhcpv6ReservedIps`

### `Element.ExcludeIpRange.case`

### `Element.ExcludeIpRange.case.Dhcpv6ExcludedIpRanges`

### `Element`

A union of different IPv6 prefix element types. The value of this union is dependent on the **ElementType** member.

### `Element.IpRange`

Pointer to a [DHCP_IP_RANGE_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_range_v6) structure that contains the IPv6 range for this IPv6 prefix.

### `Element.ReservedIp`

Pointer to a [DHCP_IP_RESERVATION_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_v6) structure that contains the IPv6 reservation information.

### `Element.ExcludeIpRange`

Pointer to a [DHCP_IP_RANGE_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_range_v6) structure that contains the IPv6 exclusion range information.

### `_DHCP_SUBNET_ELEMENT_UNION_V6`

## See also

**DHCP_IP_RANGE_V6**

[DHCP_IP_RESERVATION_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_v6)

[DHCP_SUBNET_ELEMENT_DATA_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v6)