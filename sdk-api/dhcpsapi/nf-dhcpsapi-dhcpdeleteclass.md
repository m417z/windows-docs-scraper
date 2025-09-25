# DhcpDeleteClass function

## Description

The **DhcpDeleteClass** function deletes a DHCP class from the DHCP server.

## Parameters

### `ServerIpAddress` [in]

Pointer to a Unicode string that contains the IPv6 address of the DHCP server. This string is used as a handle for resolving RPC API calls.

### `ReservedMustBeZero` [in]

Reserved. This parameter must be set to 0.

### `ClassName` [in]

Unicode string that specifies the name of the DHCP class to delete.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCP server's database. |
| **ERROR_DHCP_CLASS_NOT_FOUND** | The class name could not be found in the database. |
| **ERROR_DHCP_DELETE_BUILTIN_CLASS** | The class is a built-in class and cannot be deleted. |

## See also

[DhcpCreateClass](https://learn.microsoft.com/previous-versions/windows/desktop/api/dhcpsapi/nf-dhcpsapi-dhcpcreateclass)