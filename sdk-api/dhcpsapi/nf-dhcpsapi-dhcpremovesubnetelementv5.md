# DhcpRemoveSubnetElementV5 function

## Description

The **DhcpRemoveSubnetElementV5** function removes an element from a subnet defined on the DHCP server.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the IP address of the subnet gateway and uniquely identifies it.

### `RemoveElementInfo` [in]

[DHCP_SUBNET_ELEMENT_DATA_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v5) structure that contains information used to find the element that will be removed from subnet specified in *SubnetAddress*.

### `ForceFlag` [in]

[DHCP_FORCE_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_force_flag) enumeration value that indicates whether or not the clients affected by the removal of the subnet element should also be deleted.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

This function emulates the RPC interface used by the Windows NT 4.0 DHCP server. It is provided for backward compatibility with older versions of the DHCP Administrator application.

## See also

[DHCP_FORCE_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_force_flag)

[DHCP_SUBNET_ELEMENT_DATA_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v5)

[DhcpAddSubnetElementV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpaddsubnetelementv5)