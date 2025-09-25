# DhcpEnumOptionValues function

## Description

The **DhcpEnumOptionValues** function returns an enumerated list of option values (just the option data and the associated ID number) for a given scope.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ScopeInfo` [in]

[DHCP_OPTION_SCOPE_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_scope_info) structure that contains the level (specifically: default, server, scope, or IPv4 reservation level) for which the option values are defined and should be enumerated.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes worth of option values are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

The presence of additional enumerable data is indicated when this function returns ERROR_MORE_DATA. If no additional enumerable data is available on the DHCPv4 server, ERROR_NO_MORE_ITEMS is returned.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of option values to return. If the number of remaining unenumerated options (in bytes) is less than this value, then that amount will be returned.

To retrieve all the option values for the default user and vendor class at the specified level, set this parameter to 0xFFFFFFFF.

### `OptionValues` [out]

Pointer to a [DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array) structure that contains the enumerated option values returned for the specified scope. If there are no option values available for this scope on the DHCP server, this parameter will return null.

### `OptionsRead` [out]

Pointer to a DWORD value that specifies the number of option values returned in *OptionValues*.

### `OptionsTotal` [out]

Pointer to a DWORD value that specifies the total number of remaining option values for this scope stored on the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_MORE_DATA** | There are more elements available to enumerate. |
| **ERROR_NO_MORE_ITEMS** | There are no more elements left to enumerate. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist on the DHCP server. |
| **ERROR_DHCP_NOT_RESERVED_CLIENT** | The specified DHCPv4 client is not an IPv4 reserved client. |

## See also

[DHCP_OPTION_VALUE_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_value_array)

[DhcpEnumOptionValuesV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumoptionvaluesv5)