# DhcpCreateSubnetVQ function

## Description

The **DhcpCreateSubnetVQ** function creates a new IPv4 subnet and its associated NAP state information on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

A [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the IPv4 address of the subnet's gateway.

### `SubnetInfo` [in]

Pointer to a [DHCP_SUBNET_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info_vq) structure that contains specific settings for the subnet, including the subnet mask and IPv4 address of the subnet gateway.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes). Commonly returned error codes include:

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_SUBNET_EXISTS** | The IPv4 scope parameters specified in the *SubnetInfo* parameter are incorrect. Either the IPv4 scope already exists, or its subnet address and mask are inconsistent with the subnet address and mask of an existing scope. |

## See also

[DHCP_SUBNET_INFO_VQ](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info_vq)