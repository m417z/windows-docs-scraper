# SCOPE_MIB_INFO structure

## Description

The **SCOPE_MIB_INFO** structure defines information about an available scope for use within returned DHCP-specific SNMP Management Information Block (MIB) data.

## Members

### `Subnet`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the subnet mask for this scope.

### `NumAddressesInuse`

Contains the number of IP addresses currently in use for this scope.

### `NumAddressesFree`

Contains the number of IP addresses currently available for this scope.

### `NumPendingOffers`

Contains the number of IP addresses currently in the offer state for this scope.

## See also

[DHCP_MIB_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_mib_info)

[DHCP_MIB_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_mib_info_v6)