## Description

The **DHCP_FAILOVER_RELATIONSHIP_ARRAY** structure defines an array of DHCPv4 failover relationships between partner servers.

## Members

### `NumElements`

Integer that specifies the number of DHCPv4 failover relationships in **pRelationships.**

### `pRelationships`

Pointer to an array of [DHCP_FAILOVER_RELATIONSHIP](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_failover_relationship) structures.

## See also

[DhcpV4FailoverEnumRelationship](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4failoverenumrelationship)