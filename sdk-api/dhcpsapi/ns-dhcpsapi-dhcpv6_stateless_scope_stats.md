# DHCPV6_STATELESS_SCOPE_STATS structure

## Description

The **DHCPV6_STATELESS_SCOPE_STATS** structure defines the address counters for a specific IPv6 stateless subnet. The number of stateless IPv6 clients added and removed from the stateless client inventory are stored in this structure.

## Members

### `SubnetAddress`

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that specifies the IPv6 prefix of the DHCPv6 stateless scope.

### `NumStatelessClientsAdded`

Integer that specifies the number of IPv6 stateless clients that have been added to the DHCPv6 stateless client inventory for the prefix in **SubnetAddress**.

### `NumStatelessClientsRemoved`

Integer that specifies the number of IPv6 stateless clients that have been removed from the DHCPv6 stateless client inventory for the prefix in **SubnetAddress**.

## See also

[DHCPV6_STATELESS_STATS](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_stateless_stats)

[DhcpV6GetStatelessStatistics](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6getstatelessstatistics)