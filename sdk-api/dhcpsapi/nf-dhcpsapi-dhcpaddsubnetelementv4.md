# DhcpAddSubnetElementV4 function

## Description

The **DhcpAddSubnetElementV4** function adds an element describing a feature or aspect of the subnet to the subnet entry in the DHCP database. This function extends [DhcpAddSubnetElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpaddsubnetelement) by incorporating subnet elements that consider client type.

**Note** This function is not available in Windows previous to Windows NT 4.0 Service Pack 1.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that contains the IP address of the subnet DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that contains the IP address of the subnet.

### `AddElementInfo` [in]

[DHCP_SUBNET_ELEMENT_DATA_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v4) structure that contains the element data to add to the subnet. The V4 structure adds support for differentiation between DHCP and BOOTP clients.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option definition does not exist in the DHCP server database. |
| **ERROR_DHCP_INVALID_RANGE** | The specified IPv4 address range either overlaps an existing range or is not valid. |
| **ERROR_DHCP_IPRANGE_CONV_ILLEGAL** | Conversion of a scope to a DHCPv4-only scope or to a BOOTP-only scope is not allowed when DHCPv4 and BOOTP clients are present in the scope to convert. Manually delete either the DHCPv4 or the BOOTP clients from the scope, as appropriate for the type of scope being created. |
| **ERROR_DHCP_IPRANGE_EXISTS** | The specified IPv4 address range already exists. |
| **ERROR_DHCP_MSCOPE_RANGE_TOO_SMALL** | The multicast scope range must allow for at least 256 IPv4 addresses. |
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The specified DHCPv4 client is not an IPv4 reserverdclient. |
| **ERROR_DHCP_RESERVEDIP_EXISTS** | The specified IPv4 address or hardware address is in use by another DHCPv4 client. |
| **ERROR_DHCP_ADDRESS** | The specified address is not available. |

## See also

[DHCP_SUBNET_ELEMENT_DATA_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v4)

[DhcpAddSubnetElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpaddsubnetelement)

[DhcpAddSubnetElementV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpaddsubnetelementv5)