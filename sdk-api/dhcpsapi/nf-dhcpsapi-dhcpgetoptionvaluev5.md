# DhcpGetOptionValueV5 function

## Description

The **DhcpGetOptionValueV5** function retrieves a DHCP option value (the option code and associated data) for a particular scope. This function extends the functionality provided by [DhcpGetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetoptionvalue) by allowing the caller to specify a class and/or vendor for the option.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Flag value that indicates whether the option is for a specific or default vendor class.

| Value | Meaning |
| --- | --- |
| 0x00000000 | The option value is retrieved for a default vendor class. |
| **DHCP_FLAGS_OPTION_IS_VENDOR**<br><br>0x00000003 | The option value is retrieved for a specific vendor class. The vendor name is supplied in *VendorName*. |

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the code for the option value to retrieve.

### `ClassName` [in]

Unicode string that specifies the DHCP class name of the option. This parameter is optional.

### `VendorName` [in]

Unicode string that specifies the vendor of the option. This parameter is optional, and should be null when *Flags* is not set to DHCP_FLAGS_OPTION_IS_VENDOR. If the vendor class is not specified, the option value is returned for the default vendor class.

### `ScopeInfo` [in]

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information on the scope where the option value is set.

### `OptionValue` [out]

[DHCP_OPTION_VALUE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value) structure that contains the returned option code and data.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet is not defined on the DHCP server. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option definition does not exist in the DHCP server database. |
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The specified DHCP client is not a reserved client. |

## See also

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info)

[DHCP_OPTION_VALUE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value)

[DhcpGetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetoptionvalue)

[DhcpSetOptionValueV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvaluev5)