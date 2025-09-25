# DhcpV4SetOptionValues function

## Description

The **DhcpV4SetOptionValues** function sets option codes and their associated data values for a specific scope defined on the DHCP server. This function extends the functionality provided by [DhcpSetOptionValuesV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpsetoptionvaluesv5) by allowing the caller to specify a policy for the options.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `Flags` [in]

Reserved. Must be 0.

### `PolicyName` [in, optional]

A null-terminated Unicode string that represents the name of the policy inside the subnet of the option value to set. The subnet is identified by the **SubnetScopeInfo** member of *ScopeInfo*.

### `VendorName` [in, optional]

A null-terminated Unicode string that represents the vendor of the option. This parameter is optional, and if **NULL**, the option value is set for the default vendor.

### `ScopeInfo` [in]

Pointer to a [DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information describing the DHCP scope of the option values to set. This parameter specifies whether the option value is set for the default, server, or scope level, or for an IPv4 reservation.

### `OptionValues` [in]

Pointer to a [DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array) structure that contains a list of option codes and the corresponding data value that will be set.

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist. |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The class name being used is unknown or incorrect. |
| **ERROR_DHCP_POLICY_NOT_FOUND** | The specified policy name does not exist. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option definition does not exist on the DHCP server database. |
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The specified DHCP client is not a reserved client. |

## Remarks

*OptionValues* and its member, **Values**, should be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## See also

[DhcpV4GetAllOptionValues](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getalloptionvalues)

[DhcpV4GetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getoptionvalue)

[DhcpV4RemoveOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4removeoptionvalue)

[DhcpV4SetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setoptionvalue)