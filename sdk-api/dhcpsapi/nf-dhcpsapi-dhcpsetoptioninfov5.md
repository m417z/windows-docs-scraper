# DhcpSetOptionInfoV5 function

## Description

The **DhcpSetOptionInfoV5** function sets information for a specific DHCP option.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the option is vendor-specific. If it is not, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_OPTION_IS_VENDOR** | This flag should be set if the option is provided by a vendor. |

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the code for a specific DHCP option.

### `ClassName` [in]

Pointer to a Unicode string that specifies the DHCP class name of the option. This parameter is optional.

### `VendorName` [in]

Pointer to a Unicode string that specifies the vendor of the option. This parameter is optional, and should be **NULL** when *Flags* is not set to DHCP_FLAGS_OPTION_IS_VENDOR.

### `OptionInfo` [in]

Pointer to a [DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option) structure that contains the information on the option specified by *OptionID*.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCPv6 server's database. |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The provided class name is either incorrect or does not exist on the DHCP server. |

## See also

[DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option)

[DhcpGetOptionInfoV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetoptioninfov5)