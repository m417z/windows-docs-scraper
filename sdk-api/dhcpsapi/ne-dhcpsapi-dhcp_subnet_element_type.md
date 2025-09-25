# DHCP_SUBNET_ELEMENT_TYPE enumeration

## Description

The **DHCP_SUBNET_ELEMENT_TYPE** enumeration defines the set of possible subnet element types.

## Constants

### `DhcpIpRanges`

The subnet element contains the range of DHCP-served IP addresses.

### `DhcpSecondaryHosts`

The subnet element contains the IP addresses of secondary DHCP hosts available in the subnet.

### `DhcpReservedIps`

The subnet element contains the individual reserved IP addresses for the subnet.

### `DhcpExcludedIpRanges`

The subnet element contains the IP addresses excluded from the range of DHCP-served addresses.

### `DhcpIpUsedClusters`

### `DhcpIpRangesDhcpOnly`

The subnet element contains the IP addresses served by DHCP to the subnet (as opposed to those served by other dynamic address services, such as BOOTP).

### `DhcpIpRangesDhcpBootp`

The subnet element contains the IP addresses served by both DHCP and BOOTP to the subnet.

### `DhcpIpRangesBootpOnly`

The subnet element contains the IP addresses served by BOOTP to the subnet (specifically excluding DHCP-served addresses).

## See also

[DHCP_SUBNET_ELEMENT_DATA_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v5)