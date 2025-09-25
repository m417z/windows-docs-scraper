# DhcpAddSubnetElementV5 function

## Description

The **DhcpAddSubnetElementV5** function adds an element describing a feature or aspect of the subnet to the subnet entry in the DHCP database. **Windows 2000 and earlier:** This function is not available.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a Unicode string that contains the IP address or hostname of the subnet DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IP address of the subnet.

### `AddElementInfo` [in]

Pointer to a [DHCP_SUBNET_ELEMENT_DATA_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v5) structure that contains the element data to add to the subnet. The V5 structure adds support for BOOTP clients.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## Remarks

This API emulates the RPC interface used by the Windows NT 4.0 DHCP server. It is provided for backward compatibility with older versions of the DHCP Administrator application.

## See also

[DHCP_SUBNET_ELEMENT_DATA_V5](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v5)