# DhcpGetAllOptionValues function

## Description

The **DhcpGetAllOptionValues** function returns an array that contains all option values defined for a specific scope on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether the options are vendor-specific. If the qualification of vendor options is not necessary, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_OPTION_IS_VENDOR** | This flag should be set if vendor-specific options are desired. |

### `ScopeInfo` [in]

Pointer to a [DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information on the specific scope whose option values will be returned. This information defines the option values that are being retrieved from the default, server, or scope level, or for a specific IPv4 reservation.

### `Values` [out]

Pointer to a [DHCP_ALL_OPTION_VALUES](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_all_option_values) structure that contains the returned option values for the scope specified in *ScopeInfo*.

**Note**

The memory for this parameter must be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | This specified IPv4 sunet is not defined on the DHCP server. |
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The specified DHCP client is not a reserved client. |

## Remarks

There will be one option value in the array specified by *Values* for each vendor/class pair defined on the DHCP server.

## See also

[DhcpGetAllOptions](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetalloptions)