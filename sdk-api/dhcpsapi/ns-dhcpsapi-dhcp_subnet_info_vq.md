# DHCP_SUBNET_INFO_VQ structure

## Description

The **DHCP_SUBNET_INFO_VQ** structure defines information that describes a subnet.

## Members

### `SubnetAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the subnet ID.

### `SubnetMask`

[DHCP_IP_MASK](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the subnet IP mask.

### `SubnetName`

Pointer to a Unicode string that specifies the network name of the subnet.

### `SubnetComment`

Pointer to a Unicode string that contains an optional comment particular to this subnet.

### `PrimaryHost`

[DHCP_HOST_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_host_info) structure that contains information about the DHCP server servicing this subnet.

### `SubnetState`

[DHCP_SUBNET_STATE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_subnet_state) enumeration value indicating the current state of the subnet (enabled/disabled).

### `QuarantineOn`

Integer value used as a BOOL to represent whether or not Quarantine is enabled for the subnet. If **TRUE** (0x00000001), Quarantine is turned ON on the DHCP server; if **FALSE** (0x00000000), it is turned OFF.

### `Reserved1`

Reserved for future use.

### `Reserved2`

Reserved for future use.

### `Reserved3`

Reserved for future use.

### `Reserved4`

Reserved for future use.