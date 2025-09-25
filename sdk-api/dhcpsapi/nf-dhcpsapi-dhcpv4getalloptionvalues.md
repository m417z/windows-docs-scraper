# DhcpV4GetAllOptionValues function

## Description

The **DhcpV4GetAllOptionValues** function retrieves an array of DHCP option values (the option code and associated data) for a particular scope.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `Flags` [in]

Indicates whether the option values are for a specific or default vendor.

| Flags | Meaning |
| --- | --- |
| 0x00000000 | The option values are retrieved for a default vendor. |
| **DHCP_FLAGS_OPTION_IS_VENDOR**<br><br>0x00000003 | The option values are retrieved for specific vendors. |

### `ScopeInfo` [in]

A pointer to a [DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information on the scope of the option values to retrieve.

### `Values` [out]

Pointer to a [DHCP_ALL_OPTION_VALUES_PB](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_all_option_values_pb) structure that contains the retrieved option values for the scope specified in *ScopeInfo*.

There is one option value in the array for each vendor/policy pair defined on the DHCP server.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |

## Remarks

*Values* should be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## See also

[DhcpV4GetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getoptionvalue)

[DhcpV4RemoveOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4removeoptionvalue)

[DhcpV4SetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setoptionvalue)

[DhcpV4SetOptionValues](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setoptionvalues)