# DhcpEnumOptionValuesV6 function

## Description

The **DhcpEnumOptionValuesV6** function returns an enumerated list of option values (the option data and the associated ID number) for a specific scope within a given class.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the option is vendor specific. If it is not vendor specific, this parameter should be 0.

| Value | Meaning |
| --- | --- |
| **DHCP_FLAGS_OPTION_IS_VENDOR** | This flag should be set if the option is provided by a vendor. |

### `ClassName` [in]

Unicode string that contains the name of the class whose scope's option values will be enumerated.

### `VendorName` [in]

Unicode string that contains the name of the vendor for the class. This parameter is optional.

### `ScopeInfo` [in]

DHCP_OPTION_SCOPE_INFO6 structure that contains the scope for which the option values are defined.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes worth of option values are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of option values to return. If the number of remaining unenumerated options (in bytes) is less than this value, then that amount will be returned.

### `OptionValues` [out]

Pointer to a [DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array) structure that contains the enumerated option values returned for the specified scope. If there are no option values available for this scope on the DHCP server, this parameter will return null.

### `OptionsRead` [out]

Pointer to a DWORD value that specifies the number of option values returned in *OptionValues*.

### `OptionsTotal` [out]

Pointer to a DWORD value that specifies the total number of option values for this scope stored on the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_INVALID_PARAMETER** | The parameters were invalid. |
| **ERROR_NO_MORE_ITEMS** | No more items to enumerate. |
| **ERROR_NOT_ENOUGH_MEMORY** | Memory failure. |
| **ERROR_MORE_DATA** | More data is available to enumerate. |