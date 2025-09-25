# DhcpV6SetStatelessStoreParams function

## Description

The **DhcpV6SetStatelessStoreParams** function sets the DHCPv6 stateless client inventory configuration settings at the server or scope level.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `fServerLevel` [in]

If **TRUE** the stateless client inventory configuration settings at server level are modified. Otherwise, the scope level configuration settings are modified.

### `SubnetAddress` [in]

A [DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that contains the IPv6 subnet address of the stateless client inventory configuration settings to be modified.
If the value of *fServerLevel* is **TRUE**, this must be 0.

### `FieldModified` [in]

A value from the [DHCPV6_STATELESS_PARAM_TYPE](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcpv6_stateless_param_type) enumeration that defines the DHCPv6 stateless client inventory configuration parameter type to be modified.

### `Params` [in]

Pointer to a [DHCPV6_STATELESS_PARAMS](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcpv6_stateless_params) structure that contains the stateless client inventory configuration settings for a DHCPv6 server.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | IPv6 subnet does not exist on the DHCPv6 server. |

## See also

[DhcpV6GetStatelessStatistics](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6getstatelessstatistics)

[DhcpV6GetStatelessStoreParams](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv6getstatelessstoreparams)