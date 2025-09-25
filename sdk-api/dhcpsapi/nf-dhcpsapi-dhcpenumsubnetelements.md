# DhcpEnumSubnetElements function

## Description

The **DhcpEnumSubnetElements** function returns an enumerated list of elements for a specific DHCP subnet.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IPv4 address of the DHCP server.

### `SubnetAddress` [in]

[DHCP_IP_ADDRESS](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that specifies the address of the IPv4 subnet whose elements will be enumerated.

### `EnumElementType` [in]

[DHCP_SUBNET_ELEMENT_TYPE](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ne-dhcpsapi-dhcp_subnet_element_type) enumeration value that indicates the type of subnet element to enumerate.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 1000 bytes, and 2000 bytes worth of subnet elements are stored on the server, the resume handle can be used after the first 1000 bytes are retrieved to obtain the next 1000 on a subsequent call, and so forth.

The presence of additional enumerable data is indicated when this function returns ERROR_MORE_DATA. If no additional enumerable data is available on the DHCPv4 server, ERROR_NO_MORE_ITEMS is returned.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of bytes of subnet elements to return. If the number of remaining unenumerated options (in bytes) is less than this value, then that amount will be returned.

To retrieve all the subnet client elements for the default user and vendor class at the specified level, set this parameter to 0xFFFFFFFF.

### `EnumElementInfo` [out]

Pointer to a pointer to a [DHCP_SUBNET_ELEMENT_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_info_array) structure containing an enumerated list of all elements available for the specified subnet. If no elements are available for enumeration, this value will be null.

### `ElementsRead` [out]

Pointer to a DWORD value that specifies the number of subnet elements returned in *EnumElementInfo*.

### `ElementsTotal` [out]

Pointer to a DWORD value that specifies the total number of as-yet unenumerated elements remaining on the server for the specified subnet.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server database. |
| **ERROR_MORE_DATA** | There are more elements available to enumerate. |
| **ERROR_NO_MORE_ITEMS** | There are no more elements left to enumerate. |
| **ERROR_DHCP_SUBNET_NOT_PRESENT** | The specified IPv4 subnet does not exist on the DHCP server. |

## See also

[DHCP_SUBNET_ELEMENT_INFO_ARRAY](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_subnet_element_info_array)

[DHCP_SUBNET_ELEMENT_TYPE](https://learn.microsoft.com/windows/win32/api/dhcpsapi/ne-dhcpsapi-dhcp_subnet_element_type)

[DhcpEnumSubnetElementsV4](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetelementsv4)

[DhcpEnumSubnetElementsV5](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpenumsubnetelementsv5)