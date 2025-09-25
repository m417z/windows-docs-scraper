# DHCP_SUBNET_STATE enumeration

## Description

The **DHCP_SUBNET_STATE** enumeration defines the set of possible states for a subnet.

## Constants

### `DhcpSubnetEnabled:0`

The subnet is enabled; the server will distribute addresses, extend leases, and release addresses within the subnet range to clients.

### `DhcpSubnetDisabled`

The subnet is disabled; the server will not distribute addresses or extend leases within the subnet range to clients. However, the server will still release addresses within the subnet range.

### `DhcpSubnetEnabledSwitched`

The subnet is enabled; the server will distribute addresses, extend leases, and release addresses within the subnet range to clients. The default gateway is set to the local machine itself.

### `DhcpSubnetDisabledSwitched`

The subnet is disabled; the server will not distribute addresses or extend leases within the subnet range to clients. However, the server will still release addresses within the subnet range. The default gateway is set to the local machine itself.

### `DhcpSubnetInvalidState`

The subnet is in an invalid state.

## See also

[DHCP_SUBNET_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_info)