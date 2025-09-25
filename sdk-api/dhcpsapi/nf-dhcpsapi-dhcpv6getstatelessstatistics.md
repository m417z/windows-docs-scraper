# DhcpV6GetStatelessStatistics function

## Description

The **DhcpV6GetStatelessStatistics** function retrieves the stateless server IPv6 subnet statistics.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `StatelessStats` [out]

Pointer to a [DHCPV6_STATELESS_STATS](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_stateless_stats) structure that contain DHCPv6 stateless server IPv6 subnet statistics.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

*StatelessStats* and its member, **ScopeStats**, should be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## See also

[DhcpV6GetStatelessStoreParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6getstatelessstoreparams)

[DhcpV6SetStatelessStoreParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6setstatelessstoreparams)