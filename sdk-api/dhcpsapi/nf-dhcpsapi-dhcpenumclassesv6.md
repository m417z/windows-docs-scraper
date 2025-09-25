# DhcpEnumClassesV6 function

## Description

The **DhcpEnumClassesV6** function enumerates the user or vendor classes configured for the DHCPv6 server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that specifies the IP address or hostname of the DHCPv6 server.

### `ReservedMustBeZero` [in]

Reserved. This field must be set to zero.

### `ResumeHandle` [in, out]

Pointer to a [DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions) value that identifies the enumeration operation. Initially, this value should be zero, with a successful call returning the handle value used for subsequent enumeration requests. For example, if *PreferredMaximum* is set to 100 classes, and 200 classes are stored on the server, the resume handle can be used after the first 100 classes are retrieved to obtain the next 100 on a subsequent call, and so forth.

### `PreferredMaximum` [in]

Specifies the preferred maximum number of classes to return. If the number of remaining unenumerated classes is less than this value, then that amount will be returned. To retrieve all classes available on the DHCPv6 server, set this parameter to 0xFFFFFFFF.

### `ClassInfoArray` [out]

Pointer to a [DHCP_CLASS_INFO_ARRAY_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info_array_v6) structure that contains the returned classes. If there are no classes available on the DHCP server, this parameter will return null.

### `nRead` [out]

Pointer to a DWORD value that specifies the number of classes returned in *ClassInfoArray*.

### `nTotal` [out]

Pointer to a DWORD value that specifies the total number of classes stored on the DHCP server.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |

## Remarks

The caller of this function must free the memory pointed to by *ClassInfoArray*.

## See also

[DHCP_CLASS_INFO_ARRAY_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info_array_v6)

[DHCP_RESUME_HANDLE](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-type-definitions)