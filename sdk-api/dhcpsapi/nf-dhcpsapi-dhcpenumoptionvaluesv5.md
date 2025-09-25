# DhcpEnumOptionValuesV5 function

## Description

The **DhcpEnumOptionValuesV5** function returns an enumerated list of option values (just the option data and the associated ID number) for a specific scope within a given user or vendor class.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `Flags` [in]

Specifies a bit flag that indicates whether or not the option is vendor specific. If it is not vendor specific, this parameter must be 0.

| Value | Meaning |
| --- | --- |
| 0x00000000 | The option values are enumerated for a default vendor class. |
| **DHCP_FLAGS_OPTION_IS_VENDOR**<br><br>0x00000003 | The option values are enumerated for a specific vendor class. |

### `ClassName` [in]

Pointer to a Unicode string that contains the name of the class whose scope option values will be enumerated.

### `VendorName` [in]

Pointer to a Unicode string that contains the name of the vendor for the class. This parameter is optional. If a vendor class name is not provided, the option values enumerated for a default vendor class.

### `ScopeInfo` [in]

Pointer to a [DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains the scope for which the option values are defined. This value defines the option values that will be retrieved from the server, scope, or default level, or for an IPv4 reservation.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes' worth of option values are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of option values to return. If the number of remaining unenumerated options (in bytes) is less than this value, all option values are returned.

### `OptionValues` [out]

Pointer to a [DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array) structure that contains the enumerated option values returned for the specified scope. If there are no option values available for this scope on the DHCP server, this parameter will return null.

### `OptionsRead` [out]

Pointer to a DWORD value that specifies the number of option values returned in *OptionValues*.

### `OptionsTotal` [out]

Pointer to a DWORD value that specifies the total number of as-yet unenumerated option values for this scope stored on the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The supplied user or vendor class name is either incorrect or unknown. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet is not defined on the DHCP server. |
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The specified DHCP client is not a reserved client. |

## See also

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info)

[DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array)