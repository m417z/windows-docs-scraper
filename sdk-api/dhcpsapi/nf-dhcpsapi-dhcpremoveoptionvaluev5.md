# DhcpRemoveOptionValueV5 function

## Description

The **DhcpRemoveOptionValueV5** function removes an option value from a scope defined on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the option is vendor-specific. If it is not, this parameter should be zero.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_OPTION_IS_VENDOR** | This flag should be set if the option is provided by a vendor. |

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the code for the option value to remove.

### `ClassName` [in]

Unicode string that specifies the DHCP class name of the option value. This parameter is optional.

### `VendorName` [in]

Unicode string that specifies the vendor of the option. This parameter is optional, and should be **NULL** when *Flags* is not set to DHCP_FLAGS_OPTION_IS_VENDOR.

### `ScopeInfo` [in]

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information describing the specific scope to remove the option value from.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

## See also

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info)

[DhcpSetOptionValueV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvaluev5)

[DhcpV4RemoveOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4removeoptionvalue)