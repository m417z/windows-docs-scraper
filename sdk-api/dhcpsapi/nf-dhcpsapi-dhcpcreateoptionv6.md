# DhcpCreateOptionV6 function

## Description

The **DhcpCreateOptionV6** function creates a DHCP option.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the option is vendor-specific. If it is not, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_OPTION_IS_VENDOR** | This flag must be set if the option is provided by a vendor. |

### `OptionId` [in]

[DHCP_OPTION_ID](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that contains the unique option ID number (also called an "option code") of the new option. Many of these option ID numbers are defined; a complete list of standard DHCP and BOOTP option codes can be found at [http://www.ietf.org/rfc/rfc3315.txt](https://www.ietf.org/rfc/rfc3315.txt).

### `ClassName` [in, optional]

Unicode string that specifies the name of the DHCP class that will contain this option. This field is optional.

### `VendorName` [in, optional]

Unicode string that contains a vendor name string if the class specified in *ClassName* is a vendor-specific class.

### `OptionInfo` [in]

[DHCP_OPTION](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option) structure that contains information describing the new DHCP option, including the name, an optional comment, and any related data items.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_DUPLICATE_TAG** | The specified scope already exists. |
| **ERROR_FILE_NOT_FOUND** | The vendor name is invalid. Typically, this is because the vendor name is greater than 255 characters in length. |