# DhcpSetSubnetInfoV6 function

## Description

The **DhcpSetSubnetInfoV6** function sets or updates the information for an IPv6 subnet defined on the DHCPv6 server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IPV6_ADDRESS](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_ipv6_address) structure that contains the IPv6 address of the subnet for which the information will be modified.

### `SubnetInfo` [in]

Pointer to a [DHCP_SUBNET_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info_v6) structure that contains the new or updated information for the IPv6 subnet identified by *SubnetAddress*.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified subnet is not defined on the DHCP server. |

## See also

[DHCP_SUBNET_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info_v6)