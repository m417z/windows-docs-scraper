# DhcpRemoveSubnetElementV4 function

## Description

The **DhcpRemoveSubnetElementV4** function removes an IPv4 subnet element from an IPv4 subnet defined on the DHCPv4 server. The function extends the functionality provided by [DhcpRemoveSubnetElement](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpremovesubnetelement) by allowing the specification of a subnet that contains client type (DHCP or BOOTP) information.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the IP address of the subnet gateway and uniquely identifies it.

### `RemoveElementInfo` [in]

[DHCP_SUBNET_ELEMENT_DATA_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v4) structure that contains information used to find the element that will be removed from subnet specified in *SubnetAddress*.

### `ForceFlag` [in]

[DHCP_FORCE_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_force_flag) enumeration value that indicates whether or not the clients affected by the removal of the subnet element should also be deleted.

**Note** If the flag is set to **DhcpNoForce** and this subnet has served an IPv4 address to DHCPv4/BOOTP clients, the IPv4 range is not deleted; conversely, if the flag is set to **DhcpFullForce**, the IPv4 range is deleted along with the DHCPv4 client lease record on the DHCPv4 server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet is not defined on the DHCP server. |
| **ERROR_DHCP_RESERVED_CLIENT** | The specified DHCP client is a reserved client. |
| **ERROR_DHCP_INVALID_RANGE** | The specified IPv4 address range either overlaps an existing IPv4 address range, or is invalid. |
| **ERROR_DHCP_ELEMENT_CANT_REMOVE** | At least one multicast IPv4 address has been leased out to a MADCAP client. |

## See also

[DHCP_FORCE_FLAG](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_force_flag)

[DHCP_SUBNET_ELEMENT_DATA_V4](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_data_v4)

[DhcpAddSubnetElementV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpaddsubnetelementv4)