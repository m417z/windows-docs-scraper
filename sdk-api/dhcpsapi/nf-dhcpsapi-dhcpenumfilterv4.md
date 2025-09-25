# DhcpEnumFilterV4 function

## Description

The **DhcpEnumFilterV4** function enumerates all of the filter records from the DHCP server's allow or deny list.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCP server.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_ADDR_PATTERN](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_addr_pattern) structure that identifies the enumeration operation. Initially this parameter must be set to zero (0), with a successful call returning the address/pattern value used for subsequent enumeration requests.

### `PreferredMaximum` [in]

A DWORD value that specifies the preferred maximum number of bytes to return. If the number of remaining unenumerated filter information size is less than this value, then all the filters configured on the particular list on the DHCP server are returned. The maximum value for this is 64 (kilobytes), and the minimum value is 1 (kilobyte).

### `ListType` [in]

A [DHCP_FILTER_LIST_TYPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_filter_list_type) that specifies the list of filters to be enumerated.

### `EnumFilterInfo` [out]

Pointer to the address of an array of [DHCP_FILTER_ENUM_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_filter_enum_info) structures that contain the returned link-layer filter information configured on the DHCP server.

### `ElementsRead` [out]

Pointer to a **DWORD** value that specifies the number of link-layer filter entries returned in *EnumFilterInfo*.

### `ElementsTotal` [out]

Pointer to a **DWORD** value that specifies the number of link-layer filter entries defined on the DHCP server that have not yet been enumerated.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_MORE_DATA** | There are no more elements available for enumeration. |
| **ERROR_NO_MORE_ITEMS** | There are no more elements left to enumerate. |

## See also

[DHCP_FILTER_ENUM_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_filter_enum_info)

[DHCP_FILTER_LIST_TYPE](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ne-dhcpsapi-dhcp_filter_list_type)