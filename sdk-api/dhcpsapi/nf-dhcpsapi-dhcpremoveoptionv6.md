# DhcpRemoveOptionV6 function

## Description

The **DhcpRemoveOptionV6** function removes an option defined on the DHCP server..

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the option is vendor-specific. If it is not, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_OPTION_IS_VENDOR** | This flag should be set if the option is provided by a vendor. |

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
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_DHCP_OPTION_NOT_PRESENT** | The specified option is not present on the DHCP server. |