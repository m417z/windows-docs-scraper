# DhcpRemoveOptionV5 function

## Description

The **DhcpRemoveOptionV5** function removes the definition of a specific option for a specific user class and vendor class at the default option level on the DHCP server. This extends the functionality in [DhcpRemoveOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpremoveoption) with support for specific class and vendor names.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the option is vendor-specific. If it is not, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| 0x00000000 | This flag should be set if the option is removed for the default vendor class.. |
| **DHCP_FLAGS_OPTION_IS_VENDOR**<br><br>0x00000003 | This flag should be set if the option is removed for a specific vendor class.. |

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the code for the option to remove.

### `ClassName` [in]

Unicode string that specifies the DHCP class name of the option. This parameter is optional.

### `VendorName` [in]

Unicode string that specifies the vendor of the option. This parameter is optional, and should be **NULL** when *Flags* is not set to DHCP_FLAGS_OPTION_IS_VENDOR.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option definition does not exist in the DHCP server database. |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The supplied class name is either unknown or incorrect. |

## See also

[DhcpCreateOptionV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateoptionv5)