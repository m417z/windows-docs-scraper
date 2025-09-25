# DhcpEnumOptions function

## Description

The **DhcpEnumOptions** function returns an enumerated set of options stored on the DHCPv4 server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IPv4 address of the DHCP server.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes worth of options are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

The presence of additional enumerable data is indicated when this function returns ERROR_MORE_DATA. If no additional enumerable data is available on the DHCPv4 server, ERROR_NO_MORE_ITEMS is returned.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of options to return. If the number of remaining unenumerated options (in bytes) is less than this value, then that amount will be returned.

To retrieve all the option definitions for the default user and vendor class, set this parameter to 0xFFFFFFFF.

### `Options` [out]

Pointer to a [DHCP_OPTION_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_array) structure containing the returned options. If there are no options available on the DHCPv4 server, this parameter will return null.

### `OptionsRead` [out]

Pointer to a DWORD value that specifies the number of options returned in *Options*.

### `OptionsTotal` [out]

Pointer to a DWORD value that specifies the total number of remaining options stored on the DHCPv4 server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_MORE_DATA** | There are more elements available to enumerate. |
| **ERROR_NO_MORE_ITEMS** | There are no more elements left to enumerate. |

## Remarks

The caller of this function must free the memory pointed to by *Options* after the call completes.

## See also

[DHCP_OPTION_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_option_array)

[DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions)

[DhcpCreateOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateoption)

[DhcpRemoveOption](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpremoveoption)