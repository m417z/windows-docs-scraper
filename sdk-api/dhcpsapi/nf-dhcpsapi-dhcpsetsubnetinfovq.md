# DhcpSetSubnetInfoVQ function

## Description

The **DhcpSetSubnetInfoVQ** function sets information about a subnet defined on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the IP address of the subnet gateway, as well as uniquely identifies the subnet.

### `SubnetInfo` [in]

Pointer to a [DHCP_SUBNET_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info_vq) structure that contains the information about the subnet.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet is not defined on the DHCP server. |

## See also

[DHCP_SUBNET_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info_vq)