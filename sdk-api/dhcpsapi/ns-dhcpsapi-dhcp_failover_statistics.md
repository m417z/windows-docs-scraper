## Description

The **DHCP_FAILOVER_STATISTICS** structure defines DHCP server scope statistics that are part of a failover relationship.

## Members

### `NumAddr`

Value that specifies the total number of addresses in a DHCPv4 scope that are part of a failover relationship.

### `AddrFree`

Value that specifies the total number of free IPv4 addresses that can be leased out to clients in a DHCPv4 scope that are part of a failover relationship.

### `AddrInUse`

Value that specifies the total number of IPv4 addresses that are leased out to clients in a DHCPv4 scope that are part of a failover relationship.

### `PartnerAddrFree`

Value that specifies the number of free IPv4 addresses on the partner server that can be leased out to clients in a DHCPv4 scope that are part of a failover relationship.

### `ThisAddrFree`

Value that specifies the number of free IPv4 addresses on the local server that can be leased out to clients in a DHCPv4 scope that are part of a failover relationship.

### `PartnerAddrInUse`

Value that specifies the number of IPv4 addresses on the partner server that are leased out to clients in a DHCPv4 scope that are part of a failover relationship.

### `ThisAddrInUse`

Value that specifies the number of IPv4 addresses on the local server that are leased out to clients in a DHCPv4 scope that are part of a failover relationship.

## See also

[DhcpV4FailoverGetScopeStatistics](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failovergetscopestatistics)