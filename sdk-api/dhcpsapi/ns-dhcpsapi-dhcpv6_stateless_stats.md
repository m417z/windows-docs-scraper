# DHCPV6_STATELESS_STATS structure

## Description

The **DHCPV6_STATELESS_STATS** structure defines an array of stateless IPv6 subnet statistics.

## Members

### `NumScopes`

Integer that specifies the number of subnet statistics in *ScopeStats*.

### `ScopeStats`

Pointer to a list of [DHCPV6_STATELESS_SCOPE_STATS](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_stateless_scope_stats) structures.

### `size_is`

### `size_is.NumScopes`

## See also

[DHCPV6_STATELESS_SCOPE_STATS](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_stateless_scope_stats)

[DhcpV6GetStatelessStatistics](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6getstatelessstatistics)