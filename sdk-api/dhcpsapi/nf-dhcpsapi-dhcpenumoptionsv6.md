# DhcpEnumOptionsV6 function

## Description

The **DhcpEnumOptionsV6** function returns an enumerated list of DHCP options for a given class and/or vendor.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the option is vendor-specific. If it is not, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_OPTION_IS_VENDOR** | This flag should be set if the option is provided by a vendor. |

### `ClassName` [in]

Unicode string that contains the name of the class whose options will be enumerated.

### `VendorName` [in]

Unicode string that contains the name of the vendor for the class. This parameter is optional.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes worth of options are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of options to return. If the number of remaining unenumerated options (in bytes) is less than this value, then that amount will be returned.

### `Options` [out]

Pointer to a [DHCP_OPTION_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_array) structure containing the returned options. If there are no options available on the DHCP server, this parameter will return null.

### `OptionsRead` [out]

Pointer to a DWORD value that specifies the number of options returned in *Options*.

### `OptionsTotal` [out]

Pointer to a DWORD value that specifies the total number of options stored on the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_NO_MORE_ITEMS** | No more items to enumerate. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory failure. |
| **ERROR_MORE_DATA** | More data is available to enumerate. |