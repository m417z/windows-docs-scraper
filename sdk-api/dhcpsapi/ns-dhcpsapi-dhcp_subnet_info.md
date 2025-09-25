# DHCP_SUBNET_INFO structure

## Description

The **DHCP_SUBNET_INFO** structure defines information describing a subnet.

## Members

### `SubnetAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the subnet ID.

### `SubnetMask`

[DHCP_IP_MASK](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the subnet IP mask.

### `SubnetName`

Unicode string that specifies the network name of the subnet.

### `SubnetComment`

Unicode string that contains an optional comment particular to this subnet.

### `PrimaryHost`

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info) structure that contains information about the DHCP server servicing this subnet.

### `SubnetState`

[DHCP_SUBNET_STATE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_subnet_state) enumeration value indicating the current state of the subnet (enabled/disabled).

## See also

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info)

[DHCP_SUBNET_STATE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_subnet_state)

[DhcpGetSubnetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetsubnetinfo)