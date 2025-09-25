# DhcpCreateClassV6 function

## Description

The **DhcpCreateClassV6** function creates a custom DHCPv6 option class.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ReservedMustBeZero` [in]

Reserved. This field must be set to zero.

### `ClassInfo` [in]

[DHCP_CLASS_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info_v6) structure that contains the specific option class data.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_CLASS_ALREADY_EXISTS** | The specified class name is already defined on the DHCP server, or the class information is already in use. |

## See also

[DHCP_CLASS_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info_v6)