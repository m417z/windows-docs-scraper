# DhcpSetOptionValues function

## Description

The **DhcpSetOptionValues** function sets option codes and their associated data values for a specific scope defined on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `ScopeInfo` [in]

Pointer to a [DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information describing the level (default, server, scope, or IPv4 reservation) at which this option value will be set.

### `OptionValues` [in]

Pointer to a [DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array) structure that contains a list of option codes and the corresponding data value that will be set for them.

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

When this function is called for the first time, it creates the supplied option values in the DHCP server database. Otherwise, it modifies the option values for one or more options associated with the default user class and vendor class. These values can be set for the default, server, scope, or IPv4 reservation level on the DHCP server.

## See also

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info)

[DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array)

[DhcpSetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvalue)

[DhcpSetOptionValuesV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvaluesv5)