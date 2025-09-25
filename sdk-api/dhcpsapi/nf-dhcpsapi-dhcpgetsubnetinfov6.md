# DhcpGetSubnetInfoV6 function

## Description

The **DhcpGetSubnetInfoV6** function returns information on a specific subnet.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

DHCP_IPV6_ADDRESS value that specifies the subnet ID.

### `SubnetInfo` [out]

DHCP_SUBNET_INFO_V6 structure that contains the returned information for the subnet matching the ID specified by *SubnetAddress*.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).