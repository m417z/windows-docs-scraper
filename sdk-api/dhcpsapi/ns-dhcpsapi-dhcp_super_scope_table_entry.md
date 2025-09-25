# DHCP_SUPER_SCOPE_TABLE_ENTRY structure

## Description

The **DHCP_SUPER_SCOPE_TABLE_ENTRY** structure defines a subnet entry within the superscope table.

## Members

### `SubnetAddress`

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the IP address of the gateway for the subnet. This address is used to uniquely identify a subnet served by the DHCP server.

### `SuperScopeNumber`

Specifies the index value assigned to this subnet entry, and its enumerated position within the super scope table.

### `NextInSuperScope`

Specifies the index value of the next subnet entry in the superscope table. If this value is ---, this table entry is the last one in the super scope.

### `SuperScopeName`

Unicode string that contains the name assigned to this subnet entry within the superscope.

## See also

[DHCP_SUPER_SCOPE_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_super_scope_table)