# DHCP_SUBNET_ELEMENT_DATA_V4 structure

## Description

The **DHCP_SUBNET_ELEMENT_DATA_V4** structure defines an element that describes a feature or restriction of a subnet. Together, a set of elements describes the set of IP addresses served for a subnet by DHCP. [DHCP_SUBNET_ELEMENT_DATA_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v5) specifically allows for IP reservations that take client type into consideration

.

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

### `Element`

### `Element.IpRange`

[DHCP_IP_RANGE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_range) structure that contains the set of DHCP-served IP addresses. This member is present if **ElementType** is set to **DhcpIpRanges**.

### `Element.SecondaryHost`

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info) structure that contains the IP addresses of secondary DHCP servers available on the subnet. This member is present if **ElementType** is set to **DhcpSecondaryHosts**.

### `Element.ReservedIp`

[DHCP_IP_RESERVATION_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_reservation_v4) structure that contains the set of reserved IP addresses for the subnet. This member is present if **ElementType** is set to **DhcpExcludedIpRanges**.

### `Element.ExcludeIpRange`

[DHCP_IP_RANGE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_range) structure that contains the set of excluded IP addresses. This member is present if **ElementType** is set to **DhcpExcludedIpRanges**.

### `Element.IpUsedCluster`

[DHCP_IP_CLUSTER](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ip_cluster) structure that contains the set of clusters within the subnet. This member is present if **ElementType** is set to **DhcpIpUsedClusters**.

### `_DHCP_SUBNET_ELEMENT_UNION_V4`

## See also

[DHCP_SUBNET_ELEMENT_INFO_ARRAY_V4](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_info_array_v4)

[DHCP_SUBNET_ELEMENT_TYPE](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ne-dhcpsapi-dhcp_subnet_element_type)