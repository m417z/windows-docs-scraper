# DhcpRemoveOptionValue function

## Description

The **DhcpRemoveOptionValue** function removes the option value for a specific option on the DHCP4 server for the default user class and vendor class, for the specified scope.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the code uniquely identifying the specific option to remove from the DHCP server.

### `ScopeInfo` [in]

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information describing the specific scope (default, server, scope, or IPv4 reservation level) from which to remove the option value.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option definition could not be found in the DHCP server database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet is not defined on the DHCP server. |
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The specified DHCP client is not a reserved client. |

## See also

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info)

[DhcpRemoveOptionValueV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpremoveoptionv5)

[DhcpSetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvalue)