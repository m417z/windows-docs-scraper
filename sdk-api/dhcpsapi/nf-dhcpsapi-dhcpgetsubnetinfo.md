# DhcpGetSubnetInfo function

## Description

The **DhcpGetSubnetInfo** function returns information on a specific subnet.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the subnet ID.

### `SubnetInfo` [out]

[DHCP_SUBNET_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info) structure that contains the returned information for the subnet matching the ID specified by *SubnetAddress*.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

This function uses host byte ordering for all [DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) values in the [DHCP_SUBNET_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info) structure passed back to the caller in the *SubnetInfo* parameter. However, this function uses network byte order for the **IpAddress** member of the [DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info) structure within the **DHCP_SUBNET_INFO** structure.

## See also

[DHCP_SUBNET_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info)