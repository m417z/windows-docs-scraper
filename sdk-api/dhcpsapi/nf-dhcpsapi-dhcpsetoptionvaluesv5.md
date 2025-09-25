# DhcpSetOptionValuesV5 function

## Description

The **DhcpSetOptionValuesV5** function sets option codes and their associated data values for a specific scope defined on the DHCP server. This function extends the functionality provided by [DhcpSetOptionValues](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvalues) by allowing the caller to specify a class and/or vendor for the options.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IPv4 address of the DHCP server.

### `Flags` [in]

This parameter must be set to 0 and ignored upon receipt.

### `ClassName` [in]

Unicode string that specifies the DHCP class of the options. This parameter is optional.

### `VendorName` [in]

Unicode string that specifies the vendor of the options. If no vendor class is specified, then the option value is set for the default vendor class. This parameter is optional.

### `ScopeInfo` [in]

Pointer to a [DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information describing the DHCP scope these option values will be set on. This parameter indicates whether the option value is set for the default, server, or scope level, or for an IPv4 reservation.

### `OptionValues` [in]

Pointer to a [DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array) structure that contains a list of option codes and the corresponding data value that will be set for them.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist on the DHCP server. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option definition could not be found in the DHCP server database. |
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The specified DHCP client is not an IPv4 reserved client. |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The specified class name cannot be found in the DHCP server database. |

## Remarks

The caller of this function must release the memory pointed to by *OptionValues* after the call completes.

## See also

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info)

[DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array)

[DhcpSetOptionValueV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvaluesv5)

[DhcpSetOptionValues](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvalues)