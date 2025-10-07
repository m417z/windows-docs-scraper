# DhcpV4GetOptionValue function

## Description

The **DhcpV4GetOptionValue** function retrieves a DHCP option value (the option code and associated data) for a particular scope. This function extends the functionality provided by [DhcpGetOptionValueV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpgetoptionvaluev5) by allowing the caller to specify a policy for the option.

## Parameters

### `ServerIpAddress` [in, optional]

Pointer to a null-terminated Unicode string that represents the IP address or hostname of the DHCP server.

### `Flags` [in]

Indicates whether the option is for a specific or default vendor.

| Flags | Meaning |
| --- | --- |
| 0x00000000 | The option value is retrieved for a default vendor. |
| **DHCP_FLAGS_OPTION_IS_VENDOR**<br><br>0x00000003 | The option value is retrieved for a specific vendor. The vendor is in *VendorName*. |

### `OptionID` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) structure that specifies the unique option code for the option value to retrieve. A complete list of standard DHCP and BOOTP option codes can be found at \<http://www.ietf.org/rfc/rfc2132.txt>

### `PolicyName` [in, optional]

A null-terminated Unicode string that represents the name of the policy inside the subnet of the option value to retrieve. The subnet is identified by the **SubnetScopeInfo** member of *ScopeInfo*.

### `VendorName` [in, optional]

A null-terminated Unicode string that represents the vendor of the option. This parameter is optional, and should be **NULL** when *Flags* is not **DHCP_FLAGS_OPTION_IS_VENDOR**. If the vendor is not specified, the option value is returned for the default vendor.

### `ScopeInfo` [in]

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains information on the scope of the option value to retrieve.

### `OptionValue` [out]

Pointer to a [DHCP_OPTION_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data) structure that contains the data value corresponding to the DHCP option code specified by *OptionID*.

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

## Remarks

*OptionValue* should be free using [DhcpRpcFreeMemory](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcprpcfreememory).

## See also

[DhcpV4GetAllOptionValues](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4getalloptionvalues)

[DhcpV4RemoveOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4removeoptionvalue)

[DhcpV4SetOptionValue](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setoptionvalue)

[DhcpV4SetOptionValues](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpv4setoptionvalues)