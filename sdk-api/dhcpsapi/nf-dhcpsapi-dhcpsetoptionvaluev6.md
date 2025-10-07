# DhcpSetOptionValueV6 function

## Description

The **DhcpSetOptionValueV6** function sets information for a specific option value on the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the option is vendor-specific. If it is not, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_OPTION_IS_VENDOR** | This flag should be set if the option is provided by a vendor. |

### `OptionId` [in]

DHCP_OPTION_ID value that contains the unique option ID number (also called an "option code") of the option being set. Many of these option ID numbers are defined; a complete list of standard DHCP and BOOTP option codes can be found at \<http://www.ietf.org/rfc/rfc2132.txt>.

### `ClassName` [in]

Unicode string that specifies the DHCP class of the option. This parameter is optional.

### `VendorName` [in]

Unicode string that specifies the vendor of the option. This parameter is optional, and should be **NULL** when *Flags* is not set to DHCP_FLAGS_OPTION_IS_VENDOR.

### `ScopeInfo` [in]

Pointer to a DHCP_OPTION_SCOPE_INFO6 structure that contains information describing the DHCP scope this option value will be set on.

### `OptionValue` [in]

Pointer to a [DHCP_OPTION_DATA](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_data) structure that contains the data value corresponding to the DHCP option code specified by *OptionID*.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option is not present on the DHCP server. |