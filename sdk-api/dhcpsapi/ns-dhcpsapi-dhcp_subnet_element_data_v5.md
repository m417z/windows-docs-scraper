# DHCP_SUBNET_ELEMENT_DATA_V5 structure

## Description

The **DHCP_SUBNET_ELEMENT_DATA_V5** structure defines an element that describes a feature or restriction of a subnet. Together, a set of elements describes the set of IP addresses served for a subnet by DHCP or BOOTP. **DHCP_SUBNET_ELEMENT_DATA_V5** specifically allows for the definition of BOOTP-served addresses.

## Members

### `ElementType`

[DHCP_SUBNET_ELEMENT_TYPE](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ne-dhcpsapi-dhcp_subnet_element_type) enumeration value describing the type of element in the subsequent field.

### `Element.IpRange.case`

### `Element.IpRange.case.DhcpIpRanges`

### `Element.SecondaryHost.case`

### `Element.SecondaryHost.case.DhcpSecondaryHosts`

### `Element.ReservedIp.case`

### `Element.ReservedIp.case.DhcpReservedIps`

### `Element.ExcludeIpRange.case`

### `Element.ExcludeIpRange.case.DhcpExcludedIpRanges`

### `Element.IpUsedCluster.case`

### `Element.IpUsedCluster.case.DhcpIpUsedClusters`

### `Element.switch_type`

### `Element.switch_type.DHCP_SUBNET_ELEMENT_TYPE`

### `Element`

### `Element.IpRange`

[DHCP_BOOTP_IP_RANGE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_bootp_ip_range) structure that contains the set of BOOTP-served IP addresses. This member is present if **ElementType** is set to **DhcpIpRangesBootpOnly**.

### `Element.SecondaryHost`

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info) structure that contains the IP addresses of secondary DHCP servers available on the subnet. This member is present if **ElementType** is set to **DhcpSecondaryHosts**.

### `Element.ReservedIp`

[DHCP_IP_RESERVATION_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_v4) structure that contains the set of reserved IP addresses for the subnet. This member is present if **ElementType** is set to **DhcpReservedIps**.

### `Element.ExcludeIpRange`

[DHCP_IP_RANGE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_range) structure that contains a range of IP addresses. This member is present if **ElementType** is set to **DhcpIpRanges** or **DhcpExcludedIpRanges**.

### `Element.IpUsedCluster`

### `_DHCP_SUBNET_ELEMENT_UNION_V5`