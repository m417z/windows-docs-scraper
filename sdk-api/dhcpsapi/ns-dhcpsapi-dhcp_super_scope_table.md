# DHCP_SUPER_SCOPE_TABLE structure

## Description

The **DHCP_SUPER_SCOPE_TABLE** structure defines the superscope of a DHCP server.

## Members

### `cEntries`

Specifies the number of subnets (and therefore scopes) present in the super scope.

### `pEntries`

Pointer to a list of [DHCP_SUPER_SCOPE_TABLE_ENTRY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_super_scope_table_entry) structures containing the names and IP addresses of each subnet defined within the superscope.

### `pEntries.size_is`

### `pEntries.size_is.cEntries`

## Remarks

A "superscope" is the set of all subnets defined on a DHCP server, and hence all scopes along with the IP address ranges each serves. Taken altogether, it provides a complete set of all IP addresses served by the DHCP server. The superscope table will only provide the IP addresses associated with each subnet; to obtain the IP ranges served by each, [DhcpGetSubnetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetsubnetinfo) should be called on the IP address provided in each [DHCP_SUPER_SCOPE_TABLE_ENTRY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_super_scope_table_entry) structure of the table.

## See also

[DHCP_SUPER_SCOPE_TABLE_ENTRY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_super_scope_table_entry)

[DhcpGetSuperScopeInfoV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetsuperscopeinfov4)