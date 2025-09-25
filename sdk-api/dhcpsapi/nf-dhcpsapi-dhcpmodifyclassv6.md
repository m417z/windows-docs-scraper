# DhcpModifyClassV6 function

## Description

The **DhcpModifyClassV6** function modifies a DHCPv6 user or vendor class defined on the server.

## Parameters

### `ServerIpAddress` [in]

Unicode string that specifies the IP address or hostname of the DHCP server.

### `ReservedMustBeZero` [in]

Reserved. This value must be set to 0.

### `ClassInfo` [in]

Pointer to a [DHCP_CLASS_INFO_V6](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info_v6) structure that contains the new information for the class.

## Return value

This function returns **ERROR_SUCCESS** upon a successful call. Otherwise, it returns one of the [DHCP Server Management API Error Codes](https://learn.microsoft.com/previous-versions/windows/desktop/dhcp/dhcp-server-management-api-error-codes).

| Return code | Description |
| --- | --- |
| **ERROR_ACCESS_DENIED** | This call was performed by a client who is not a member of the "DHCP Administrators" security group. |
| **ERROR_INVALID_PARAMETER** | The [DHCP_CLASS_INFO](https://learn.microsoft.com/windows/desktop/api/dhcpsapi/ns-dhcpsapi-dhcp_class_info) structure provided in *ClassInfo* has null or invalid values for the **ClassName** or **ClassData** member (or both). |
| **ERROR_DHCP_CLASS_NOT_FOUND** | A class name could not be found that matches the provided information. |
| **ERROR_DHCP_JET_ERROR** | An error occurred while accessing the DHCPv6 server's database. |
| **ERROR_DHCP_CLASS_ALREADY_EXISTS** | The new class name is currently in use, or the new class information is currently in use. |