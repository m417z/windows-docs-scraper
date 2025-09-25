# DhcpGetSuperScopeInfoV4 function

## Description

The **DhcpGetSuperScopeInfoV4** function returns information on the superscope of a DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `SuperScopeTable` [out]

[DHCP_SUPER_SCOPE_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_super_scope_table) structure that contains the returned information for the superscope of the supplied DHCP server.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |

## Remarks

A superscope is the set of all subnets defined on a DHCP server, and hence all scopes along with the IP address ranges each serves. Taken altogether, a superscope provides a complete set of all IP addresses served by the DHCP server. The superscope table provides the IP addresses associated with each subnet. To obtain the IP ranges served by each, [DhcpGetSubnetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetsubnetinfo) should be called on the IP address provided in each [DHCP_SUPER_SCOPE_TABLE_ENTRY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_super_scope_table_entry) structure of the table.

## See also

[DHCP_SUPER_SCOPE_TABLE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_super_scope_table)

[DhcpGetSubnetInfo](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetsubnetinfo)

[DhcpSetSuperScopeV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetsuperscopev4)