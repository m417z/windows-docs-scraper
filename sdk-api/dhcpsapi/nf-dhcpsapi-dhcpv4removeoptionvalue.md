# DhcpV4RemoveOptionValue function

## Description

The **DhcpV4RemoveOptionValue** function removes an option value from a scope defined on the DHCP server. This function extends the functionality provided by [DhcpRemoveOptionValueV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpremoveoptionvaluev5) by allowing the caller to specify a policy for the option.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `Flags` [in]

Indicates whether the option value is for a specific or default vendor.

| Flags | Meaning |
| --- | --- |
| 0x00000000 | The option value is removed for a default vendor. |
| **DHCP_FLAGS_OPTION_IS_VENDOR**<br><br>0x00000003 | The option value is removed for a specific vendor. The vendor is in *VendorName*. |

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that specifies the option code for the option value to remove. A complete list of standard DHCP and BOOTP option codes can be found at \<http://www.ietf.org/rfc/rfc2132.txt>

### `PolicyName` [in, optional]

A null-terminated Unicode string that represents the name of the policy inside the subnet of the option value to remove. The subnet is identified by the **SubnetScopeInfo** member of *ScopeInfo*.

### `VendorName` [in, optional]

A null-terminated Unicode string that represents the vendor of the option. This parameter is optional, and should be **NULL** when *Flags* is not **DHCP_FLAGS_OPTION_IS_VENDOR**. If the vendor is not specified, the option value is set for the default vendor.

### `ScopeInfo` [in]

Pointer to a [DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information on the scope of the option value to remove

## Return value

If the function succeeds, it returns **ERROR_SUCCESS**.

If the function fails, it returns one of the following or an error code from [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Value | Meaning |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | One or more of the parameters were invalid. |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The class name being used is unknown or incorrect. |
| **ERROR_DHCP_POLICY_NOT_FOUND** | The specified policy name does not exist. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option definition does not exist on the DHCP server database or there is no value set for the specified option ID on the specified policy. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist. |

## See also

[DhcpV4GetAllOptionValues](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getalloptionvalues)

[DhcpV4GetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getoptionvalue)

[DhcpV4SetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setoptionvalue)

[DhcpV4SetOptionValues](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setoptionvalues)