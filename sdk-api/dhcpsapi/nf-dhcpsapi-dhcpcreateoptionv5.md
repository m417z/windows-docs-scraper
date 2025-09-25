# DhcpCreateOptionV5 function

## Description

The **DhcpCreateOptionV5** function creates a DHCP option.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Flag value that indicates whether the option is for a specific or default vendor class.

| Value | Meaning |
| --- | --- |
| 0x00000000 | The option value is retrieved for a default vendor class. |
| **DHCP_FLAGS_OPTION_IS_VENDOR**<br><br>0x00000003 | The option value is retrieved for a specific vendor class. The vendor name is supplied in *VendorName*. |

### `OptionId` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the unique option ID number (also called an "option code") of the new option. Many of these option ID numbers are defined; a complete list of standard DHCP and BOOTP option codes can be found in [DHCP Options and BOOTP Vendor Extensions](https://www.ietf.org/rfc/rfc2132.txt).

### `ClassName` [in, optional]

Unicode string that specifies the name of the DHCP class that will contain this option. This field is optional.

### `VendorName` [in, optional]

Unicode string that contains a vendor name string if the class specified in *ClassName* is a vendor-specific class.

### `OptionInfo` [in]

[DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option) structure that contains information describing the new DHCP option, including the name, an optional comment, and any related data items.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_OPTION_EXISTS** | The specified option definition already exists in the DHCP server database. |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The specified class name is unknown or incorrectly formed. |

## See also

 [DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option)