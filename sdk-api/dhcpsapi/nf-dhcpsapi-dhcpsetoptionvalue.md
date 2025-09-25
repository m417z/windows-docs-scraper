# DhcpSetOptionValue function

## Description

The **DhcpSetOptionValue** function sets information for a specific option value on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the unique code for a DHCP option.

### `ScopeInfo` [in]

Pointer to a [DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information describing the level (default, server, scope, or IPv4 reservation) at which this option value will be set.

### `OptionValue` [in]

Pointer to a [DHCP_OPTION_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data) structure that contains the data value corresponding to the DHCP option code specified by *OptionID*.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option definition could not be found in the DHCP server database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist on the DHCP server. |
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The specified DHCP client is not a reserved client. |
| **ERROR_FILE_NOT_FOUND** | The multicast scope specified in *ScopeInfo* was not found on the DHCP server. |

## Remarks

When this function is called for the first time, it creates the supplied option value in the DHCP server database. Otherwise, it modifies the option value for a specific option associated with the default user class and vendor class. These values can be set for the default, server, scope, or IPv4 reservation level on the DHCP server.

## See also

[DHCP_OPTION_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data)

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info)

[DhcpSetOptionValueV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvaluev5)

[DhcpSetOptionValues](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvalues)