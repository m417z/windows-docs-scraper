# DhcpGetOptionValueV6 function

## Description

The **DhcpGetOptionValueV6** function retrieves the option value for a specific option defined on the DHCPv6 server for a specific user or vendor class.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IPv6 address or hostname of the DHCPv6 server.

### `Flags` [in]

Flag value that indicates whether the option is for a specific or default vendor class.

| Value | Meaning |
| --- | --- |
| 0x00000000 | The option value is retrieved for a default vendor class. |
| **DHCP_FLAGS_OPTION_IS_VENDOR**<br><br>0x00000003 | The option value is retrieved for a specific vendor class. The vendor name is supplied in *VendorName*. |

### `OptionID` [in]

**DHCP_OPTION_ID** value that specifies the option identifier for the option being retrieved.

### `ClassName` [in]

Pointer to a null-terminated Unicode string that contains the name of the user class for which the option value is being requested. This parameter is optional.

### `VendorName` [in]

Pointer to a null-terminated Unicode string that contains the name of the vendor class for which the option value is being requested. This parameter is optional; if no value is specified, the default vendor class is assumed.

### `ScopeInfo` [in]

Pointer to a [DHCP_OPTION_SCOPE_INFO6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info6) structure that contains information about the DHCPv6 scope for which the option is value is requested. Specifically, it defines whether the option is being retrieved for the default, server, or scope level, or for a specific IPv6 reservation.

### `OptionValue` [out]

Pointer to the address of a [DHCP_OPTION_VALUE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value) structure returned by the operation, and which contains the option value corresponding to *OptionID*.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_FILE_NOT_FOUND** | The system cannot find the specified file. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified subnet is not defined on the DHCPv6 server. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option is not defined at the specified level on the DHCPv6 server. |
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The reserved IPv6 client is not defined on the DHCPv6 server. |

## Remarks

The caller of this function must release the memory pointed to by *OptionValue*.

## See also

[DHCP_OPTION_SCOPE_INFO6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info6)