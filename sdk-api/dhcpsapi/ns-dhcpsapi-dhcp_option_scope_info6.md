# DHCP_OPTION_SCOPE_INFO6 structure

## Description

The DHCP_OPTION_SCOPE_INFO6 structure defines the data associated with a DHCP option scope.

## Members

### `ScopeType`

[DHCP_OPTION_SCOPE_TYPE6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_option_scope_type6) enumeration value that indicates the type of the DHCP option. This value is used as the selector for the union arms listed in the following fields.

### `ScopeInfo.SubnetScopeInfo.case`

### `ScopeInfo.SubnetScopeInfo.case.DhcpScopeOptions6`

### `ScopeInfo.ReservedScopeInfo.case`

### `ScopeInfo.ReservedScopeInfo.case.DhcpReservedOptions6`

### `ScopeInfo.switch_type`

### `ScopeInfo.switch_type.DHCP_OPTION_SCOPE_TYPE6`

### `ScopeInfo`

### `ScopeInfo.DefaultScopeInfo`

Pointer to data the specifies the default scope information. This must be set to null.

### `ScopeInfo.SubnetScopeInfo`

IPv6 mask for the subnet that defines the DHCP scope.

### `ScopeInfo.ReservedScopeInfo`

DHCP_RESERVED_SCOPE6 structure that contains the reserved DHCP scope information.

### `_DHCP_OPTION_SCOPE_UNION6`

## See also

[DHCP_OPTION_SCOPE_TYPE6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_option_scope_type6)