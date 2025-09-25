# DhcpGetSubnetInfoVQ function

## Description

The **DhcpGetSubnetInfoVQ** function retrieves the information about a specific IPv4 subnet defined on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

**DHCP_IP_ADDRESS** structure that contains the IPv4 address of the subnet for which the information will be modified.

### `SubnetInfo` [out]

A [DHCP_SUBNET_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info_vq) structure that contains the returned information for the subnet matching the IPv4 address specified by *SubnetAddress*.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified subnet is not defined on the DHCP server. |
| **ERROR_INVALID_PARAMETER** | One of the parameters provides an invalid value. |

## See also

[DHCP_SUBNET_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info_vq)