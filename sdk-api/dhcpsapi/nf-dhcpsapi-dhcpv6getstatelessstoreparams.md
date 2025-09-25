# DhcpV6GetStatelessStoreParams function

## Description

The **DhcpV6GetStatelessStoreParams** function retrieves the current DHCPv6 stateless client inventory configuration settings at the server or scope level.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `fServerLevel` [in]

If **TRUE** the stateless client inventory configuration settings at server level are retrieved. Otherwise, the scope level configuration settings are retrieved.

### `SubnetAddress` [in]

A [DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that contains the IPv6 subnet address of the stateless client inventory configuration settings to be retrieved.
If the value of *fServerLevel* is **TRUE**, this must be 0.

### `Params` [out]

Pointer to a [DHCPV6_STATELESS_PARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_stateless_params) structure that contains the stateless client inventory configuration settings for a DHCPv6 server.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | IPv6 subnet does not exist on the DHCPv6 server. |

## Remarks

*Params* should be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## See also

[DhcpV6GetStatelessStatistics](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6getstatelessstatistics)

[DhcpV6SetStatelessStoreParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6setstatelessstoreparams)