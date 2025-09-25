# DHCP_OPTION_SCOPE_INFO structure

## Description

The **DHCP_OPTION_SCOPE_INFO** structure defines information about the options provided for a certain DHCP scope.

## Members

### `ScopeType`

[DHCP_OPTION_SCOPE_TYPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_option_scope_type) enumeration value that defines the scope type of the associated DHCP options, and indicates which of the following fields in the union will be populated.

### `ScopeInfo.SubnetScopeInfo.case`

### `ScopeInfo.SubnetScopeInfo.case.DhcpSubnetOptions`

### `ScopeInfo.ReservedScopeInfo.case`

### `ScopeInfo.ReservedScopeInfo.case.DhcpReservedOptions`

### `ScopeInfo.MScopeInfo.case`

### `ScopeInfo.MScopeInfo.case.DhcpMScopeOptions`

### `ScopeInfo`

### `ScopeInfo.DefaultScopeInfo`

Pointer to a [DHCP_OPTION_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_array) structure that contains the default DHCP scope options. This member is not currently used.

### `ScopeInfo.GlobalScopeInfo`

Pointer to a [DHCP_OPTION_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_array) structure that contains the global DHCP server options.

### `ScopeInfo.SubnetScopeInfo`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the subnet ID as a DWORD.

### `ScopeInfo.ReservedScopeInfo`

[DHCP_RESERVED_SCOPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_reserved_scope) structure that contains a reserved IP address and its corresponding subnet ID.

### `ScopeInfo.MScopeInfo`

Pointer to a Unicode string that contains the multicast scope name (usually represented as the IP address of the multicast router).

### `_DHCP_OPTION_SCOPE_UNION`

## See also

[DHCP_OPTION_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_array)

[DHCP_OPTION_SCOPE_TYPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_option_scope_type)

[DHCP_RESERVED_SCOPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_reserved_scope)