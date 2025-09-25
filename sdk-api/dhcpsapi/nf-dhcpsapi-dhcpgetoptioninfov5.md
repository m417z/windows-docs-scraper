# DhcpGetOptionInfoV5 function

## Description

The **DhcpGetOptionInfoV5** function returns information on a specific DHCP option.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the option is vendor-specific. If it is not, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| 0x00000000 | The option value is retrieved for a default vendor class. |
| **DHCP_FLAGS_OPTION_IS_VENDOR**<br><br>0x00000003 | The option value is retrieved for a specific vendor class. The vendor name is supplied in *VendorName*. |

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the code for the option to retrieve information on.

### `ClassName` [in]

Unicode string that specifies the DHCP class name of the option. This parameter is optional.

### `VendorName` [in]

Unicode string that specifies the vendor of the option. This parameter is optional, and must be null when *Flags* is not set to DHCP_FLAGS_OPTION_IS_VENDOR. If it is not set, then the option definition for the default vendor class is returned.

### `OptionInfo` [out]

Pointer to a [DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option) structure that contains the returned information on the option specified by *OptionID*.

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
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The specified DHCP client is not a reserved client. o |

## See also

[DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option)

[DhcpSetOptionInfoV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptioninfov5)